extern crate cc;
extern crate bindgen;

use std::env;
use std::path::PathBuf;

fn main() {
    //println!("cargo:rustc-link-lib=c++");
    println!("cargo:rustc-link-search=/usr/local/Cellar/sdl2/2.30.9/lib/");
    println!("cargo:rustc-link-lib=SDL2");
    println!("cargo:rustc-link-search=/usr/local/Cellar/sdl2_image/2.8.2_2/lib/");
    println!("cargo:rustc-link-lib=SDL2_Image");
    println!("cargo:rustc-link-search=/usr/local/Cellar/sdl2_ttf/2.22.0/lib/");
    println!("cargo:rustc-link-lib=SDL2_ttf");
    cc::Build::new()
        .file("src/cpp/sdl/pch.cpp")
        .file("src/cpp/sdl/dllmain.cpp")
        .file("src/cpp/sdl/RApplication.cpp")
        .file("src/cpp/sdl/RCanvas.cpp")
        .file("src/cpp/sdl/RFPSTimer.cpp")
        .file("src/cpp/sdl/RWindow.cpp")
        .include("src/cpp/sdl/")
        .include("/usr/local/Cellar/sdl2/2.30.9/include/SDL2")
        .include("/usr/local/Cellar/sdl2_ttf/2.22.0/include/SDL2")
        .include("/usr/local/Cellar/sdl2_image/2.8.2_2/include/SDL2")
        
        .define("_DEBUG","1")
        .compile("rui_app");

        let bindings = bindgen::Builder::default()
        .header("src/cpp/SDL/exports.hpp")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");

        let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
        bindings
        .write_to_file(out_path.join("cpp_imports.rs"))
        .expect("Couldn't write bindings!");
}