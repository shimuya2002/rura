mod imports;
mod game_data;
mod user_data;
mod state;
use std::sync::*;
use imports::*;
use std::path::*;
use game_data::*;
use state::*;
static game_state:LazyLock<State>=LazyLock::new(||{State::new()});
pub extern  "C" fn draw_frame(arg1: *mut RCanvas){
}

fn main() {
//    println!("Hello, world!");
    unsafe{
        let mut app=RApplication::new();
        println!("{}",app.get_app_dir_path_string());
        let assets_path=if cfg!(debug_assertions){
            Path::new(&app.get_app_dir_path_string()).join("../../assets/")
        }else{
            Path::new(&app.get_app_dir_path_string()).join("/assets/")

        }.canonicalize().unwrap();
        println!("{}",assets_path.as_path().to_str().unwrap());
        let mut game=GameData::new(&assets_path,&mut app);
        let mut main_wnd=RWindow::new();
        app.set_main_window(&mut main_wnd);
        main_wnd.show();
        app.run();
    }
}
