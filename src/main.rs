mod imports;
mod state;
use imports::*;
fn main() {
//    println!("Hello, world!");
    unsafe{
        let mut app=RApplication::new();
        let mut main_wnd=RWindow::new();
        app.set_main_window(&mut main_wnd);
        main_wnd.show();
        app.run();
    }
}
