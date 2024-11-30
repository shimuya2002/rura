#pragma once
#if defined(NDEBUG) || defined(_DEBUG)
#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
// Windows ヘッダー ファイル
#include <windows.h>
#include<mmsystem.h>

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

#pragma comment(lib,"winmm.lib")

#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"SDL2_Image.lib")
#pragma comment(lib,"SDL2_TTF.lib")

#define LIB_TYPE(T) T 
#else
#define LIB_TYPE(T) void


#endif
#ifdef RUIAPPSDL_EXPORTS
#define RUI_SDL_EXPORTS __declspec(dllexport)
#else
#define RUI_SDL_EXPORTS __declspec(dllimport)
#endif

 