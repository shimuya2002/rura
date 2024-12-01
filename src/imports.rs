#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
include!(concat!(env!("OUT_DIR"), "/cpp_imports.rs"));
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