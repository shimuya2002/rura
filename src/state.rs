use std::collections::*;
use crate::game_data::*;
use crate::imports::*;
#[derive(Copy,Clone,PartialEq,Debug)]
pub enum ModeState{
    STATE_DECK,
    STATE_STORIES,
    STATE_HOME,
    STATE_RACE,
    STATE_LOT_BOX,

}
pub struct State{
    state_queue:Vec<ModeState>

}

impl State{
    pub fn new()->State{
        return State{state_queue:Vec::<ModeState>::new()};
    }

    pub fn proc_frame(&mut self,data:&mut GameData){

        match self.state_queue.last(){
            None=>{
                self.state_queue.push(ModeState::STATE_HOME);

            },
            Some(state)=>{
                match state{
                    _=>{}
                }
            }

        }
    }
    pub fn draw_frame(&mut self,data:&mut GameData,canvas:&mut RCanvas){

        //Draw buttom menu
        match self.state_queue.last(){
            None=>{},
            Some(s)=>{
                match s{
                    ModeState::STATE_HOME=>{
                        unsafe{
                            let btnw=canvas.get_canvas_width()/5;
                            let wh=canvas.get_canvas_height();
                            let btn_caption=[
                                "Deck",
                                "Stories",
                                "Home",
                                "Race",
                                "Lot box"
                            ];
                            let next_states=[
                                ModeState::STATE_DECK,
                                ModeState::STATE_STORIES,
                                ModeState::STATE_HOME,
                                ModeState::STATE_RACE,
                                ModeState::STATE_LOT_BOX

                            ];
                            for i in 0..5-1{
                                if canvas.draw_button_str(btnw*i,wh-32,&btn_caption[i as usize].to_string()){
                                    self.state_queue.pop();
                                    self.state_queue.push(next_states[i as usize]);
                                    break;
                                }
                            }
                        }
                    
                    }
                    _=>{}
                }
            }
        }
    }
}
