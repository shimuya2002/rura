use uuid::Uuid;
use rand::Rng;
use std::rc::*;

use std::path::Path;
use std::collections::*;
use crate::imports::*;


///use serde::serde_derive::*;
use serde::*;
//use serde::serde_json::*;
#[derive(Serialize, Deserialize,Copy,Clone,PartialEq,Debug)]
pub enum Rarity{
    R,
    SR,
    SSR,
}
const LOT_SSR_RATE:f64=0.03;
const LOT_SR_RATE:f64=0.18;
const LOT_R_RATE:f64=0.79;

#[derive(Serialize, Deserialize,Copy,Clone,Debug)]
pub enum SUPPORT_TYPE{

}
#[derive(Serialize, Deserialize,Clone,Debug)]
pub struct CharaParam{
    pub speed:i32,
    pub stamina:i32,
    pub power:i32,
    pub guts:i32,
    pub inteli:i32

}
#[derive(Serialize, Deserialize,Copy,Clone,Debug)]
pub struct CharaGrowth{
    pub speed:Option<f32>,
    pub stamina:Option<f32>,
    pub power:Option<f32>,
    pub guts:Option<f32>,
    pub inteli:Option<f32>

}
#[derive(Serialize,Deserialize,Clone,Debug)]
pub struct CharaData{
    pub chara_id:Option<String>,
    pub chara_name:String,
    pub costume_name:String,
    pub cur_params:CharaParam,
    pub max_params:CharaParam,
    pub level:isize,
    pub rarity:Rarity,
    pub stock_num:Option<isize>
}
#[derive(Serialize,Deserialize,Debug)]
pub struct SupportData{
    pub chara_name:String,
    pub event_name:String,
    pub level:isize,
    pub rarity:Rarity,
    pub supports:Vec<SUPPORT_TYPE>
}
#[derive(Serialize,Deserialize,Debug)]
pub struct PlayerData{
    pub user_id:String,
    pub user_name:String,
    pub chara_deck:Vec<CharaData>,
    pub support_deck:Vec<SupportData>
}
pub struct GameData{
    chara_data_list:Vec<CharaData>,
    pub player_data:Option<PlayerData>,
    rand_tbl:[f64;128]
}

impl GameData{
    pub fn new(assets_dir:&Path,app:&mut RApplication)->GameData{
        let mut obj=GameData{
            chara_data_list:Vec::<CharaData>::new(),
            player_data:None,
            rand_tbl:[0.0;128]
        };
        obj.load_game_data(&assets_dir,app);
        let mut rng=rand::thread_rng();
        for i in 0..obj.rand_tbl.len()-1{
            obj.rand_tbl[i]=rng.gen();
        }
        return obj;
    }
    pub fn load_game_data(&mut self,assets_dir:&Path,app:&mut RApplication){
        self.chara_data_list.clear();
        let chara_dir=assets_dir.join("chara_data").canonicalize().unwrap();
        self.load_chara_data(&chara_dir,app);

    }
    fn load_chara_data(&mut self,chara_assets_dir:&Path,app:&mut RApplication){
        for file_path in chara_assets_dir.read_dir().unwrap(){
            if let Ok(file_path) = file_path{
                let file_path_str=String::from(file_path.path().to_str().unwrap());
                if cfg!(debug_assertions){
                    println!("Charactor data file:{}",file_path_str);
                }
                let data=app.read_text_string_from_file(&file_path_str);
                if cfg!(debug_assertions){
                    println!("{}",data);
                }
                let mut obj:CharaData=serde_json::from_str(data.as_str()).unwrap();
                obj.chara_id=Some(Uuid::new_v4().to_string());
                self.chara_data_list.push(obj);

            }
        }
        self.chara_data_list.sort_by(|a,b|a.chara_name.cmp(&b.chara_name));
    }

    pub fn play_chara_lot_box(&mut self,num:isize,milli_sec:u32)->CharaData{
        fn count_rarety_chara_num(cd:&Vec<CharaData>,r:Rarity)->isize{
            let mut cn=0;
            for c in cd{
                if r==c.rarity{
                    cn=cn+1;
                }
            }

            return cn;
        }    

        fn get_target_rarity(l_value:f64,c_ssr_num:isize,c_sr_num:isize,c_r_num:isize)->Rarity{

            if LOT_SSR_RATE>l_value && 0<c_ssr_num{
                return Rarity::SSR;
            }
            if LOT_R_RATE>l_value && 0<c_sr_num{
                return Rarity::SR;
            }

            return Rarity::R;
        }
        let rand_idx=((self.rand_tbl.len() as u32)%milli_sec) as usize;
        let ssr_num=count_rarety_chara_num(&self.chara_data_list,Rarity::SSR);
        let sr_num=count_rarety_chara_num(&self.chara_data_list,Rarity::SR);
        let r_num=count_rarety_chara_num(&self.chara_data_list,Rarity::R);
        let value=self.rand_tbl[rand_idx];
        let target_rarity=get_target_rarity(value,ssr_num,sr_num,r_num);
        let target_idx=(if Rarity::SSR==target_rarity{
                (ssr_num as f64)*value
            }else if Rarity::SR==target_rarity{
                (sr_num  as f64)*value
            }else{
                (r_num  as f64)*value
            }) as usize;

        let mut i=0;
        for c in &self.chara_data_list{
            if target_rarity==c.rarity{
                i=i+1;
                if target_idx==i{
                    return c.clone();
                }
            }
        }
        return self.chara_data_list[0].clone();

    }

    

}