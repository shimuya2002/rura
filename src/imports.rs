

#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
include!(concat!(env!("OUT_DIR"), "/cpp_imports.rs"));

use std::ffi::*;
use std::*;
use std::collections::*;
impl Drop for RWindow{
    #[inline]
    fn drop(&mut self){
        unsafe{
            self.destruct();
        }
    }
}
impl Drop for RApplication{
    #[inline]
    fn drop(&mut self){
        unsafe{
            self.destruct();
        }
    }

}
impl RApplication{
    pub fn get_app_dir_path_string(&mut self)->String{
        unsafe{
            let str= CStr::from_ptr(self.get_app_dir_path());
            return String::from(str.to_str().unwrap());

        }
    }
    pub fn read_text_string_from_file(&mut self,path:&String)->String{
        unsafe{
            let c_path_str=CString::new(path.as_str()).expect("");
            let size=self.read_text_from_file(c_path_str.as_ptr(),
                core::ptr::null_mut());

            let mut text=Vec::<u8>::new();
            text.resize(size as usize,0);
            self.read_text_from_file(c_path_str.as_ptr(),text.as_mut_ptr());
            return String::from(CString::from_vec_with_nul(text).unwrap().to_str().unwrap());
        }
    }
}