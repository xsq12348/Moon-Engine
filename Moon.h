#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include"Moon_Configuration.h"

#if MOONCOMPATIBLE

#include"Moon_Compatible_Function.h"

#endif

#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include <locale.h>
#include <wchar.h>
#if OPEN_SDL
#include <SDL3\SDL.h>
#endif
#pragma comment( lib,"Winmm.lib")
#pragma comment(lib, "Msimg32.lib")

#define Error			-1
#define NOTFOUND		-1
#define YES				TRUE
#define NO				FALSE
#define ON				TRUE
#define OFF				FALSE
#define Pi				3.1415926f
#define TRANSPARENTCOLOR 0xffff00ff

#define Moon_EVENT_KEY_UP	SDL_EVENT_KEY_UP
#define Moon_EVENT_KEY_DOWN SDL_EVENT_KEY_DOWN

#define VK_0 48
#define VK_1 49
#define VK_2 50
#define VK_3 51
#define VK_4 52
#define VK_5 53
#define VK_6 54
#define VK_7 55
#define VK_8 56
#define VK_9 57

#define VK_A 65
#define VK_B 66
#define VK_C 67
#define VK_D 68
#define VK_E 69
#define VK_F 70
#define VK_G 71
#define VK_H 72
#define VK_I 73
#define VK_J 74
#define VK_K 75
#define VK_L 76
#define VK_M 77
#define VK_N 78
#define VK_O 79
#define VK_P 80
#define VK_Q 81
#define VK_R 82
#define VK_S 83
#define VK_T 84
#define VK_U 85
#define VK_V 86
#define VK_W 87
#define VK_X 88
#define VK_Y 89
#define VK_Z 90

#if	   MOONMANYENTITY
#undef MOONSTANDARDENTITY
#undef MOONFEWENTITY
#define ENTITYNUMBER	1000003
#elif  MOONSTANDARDENTITY
#undef MOONMANYENTITY
#undef MOONFEWENTITY
#define ENTITYNUMBER	10007
#elif  MOONFEWENTITY
#undef MOONMANYENTITY
#undef MOONSTANDARDENTITY
#define ENTITYNUMBER	997
#endif

#if OPEN_SDL
#pragma comment(lib, "SDL3.lib")
#endif

/*
如果您感兴趣,还可以查看另一个功能更加强大但是已经落后的项目:Star,项目请见:https://github.com/xsq12348/star

作者:xsq12348
Email:1993346266@qq.com
创建日期:2025.10.29
版本,如果没有日期,那就是前一个日期一起写的/If there is no date, it is written together with the previous date.
最后一个是修改BUG/重构函数/更新些许小功能,第二个是添加函数,第三个是重构,第四个是正式的大版本号
* 0.0.0.0
* 1.0.0.0  2025.10.29  完成了基本框架的搭建																		.Completed the setup of the basic framework
* 1.0.0.1  2025.10.30  解决了按键检测,窗口输入,消息循环BUG,添加了一个线程用来记录项目运行中的各种属性					.Fixed bugs with key detection, window input, and message loop, and added a thread to record various properties during project execution.
* 1.0.0.2  2025.10.31  解决了帧数显示不出来的问题																.Fixed the issue where the frame count was not displaying.
* 1.0.0.3  2025.11.2   加入了动画系统																			.Added an animation system
* 1.0.0.3  2025.11.3   修改了帧率控制不稳定的问题																.Fixed the issue of unstable frame rate control
* 1.0.0.4              将工具函数转移到了新的文件里																.Moved the utility functions to a new file
* 1.0.0.5  2025.11.4   添加了字符函数																			.Added character function
* 1.0.0.6  2025.11.5   添加了图片旋转																			.Added image rotation
* 1.0.0.7              添加了获取像素颜色																		.Added functionality to get pixel color
* 1.0.0.8              修复了HashFindEntity的BUG																.Fixed the bug in HashFindEntity
* 1.0.0.9              添加了三角形碰撞检测																		.Added triangle collision detection
* 1.0.0.10             添加了运行外部程序																		.Added the ability to run external programs
* 1.1.0.0              引擎几乎搭建完成																		.The engine is almost fully built
* 1.1.0.1  2025.11.6   修复了DringAreaAlpha的BUG																.Fixed the bug in DringAreaAlpha
* 1.1.0.2              更新了ProjectOver函数																	.Updated the ProjectOver function
* 1.1.0.3  2025.11.7   添加了ProjectPause/暂停函数																.Added ProjectPause function
* 1.1.0.4              重构了ProjectGod结构体																	.Refactored the ProjectGod structure
* 1.1.0.5              重构了ProjectRun函数																	.Refactored the ProjectRun function
* 1.1.0.5              修复了ProjectPause的BUG																.Fixed the bug in ProjectPause
* 1.1.0.6              添加了ProjectFunctionSwitch/函数切换函数													.Added ProjectFunctionSwitch function
* 1.1.1.0  2025.11.10  添加了SDL支持																			.Added SDL support
* 1.1.1.1  2025.11.27  解决了StarEngine一直没有解决的窗口焦点问题													.Resolved the window focus issue that StarEngine had never fixed
* 1.1.3.0  2025.11.29  添加了按钮控件																			.Added a button control
* 1.1.3.1              更新了启动图案																			.Updated the startup pattern
* 1.1.3.2  2025.11.29  更新了启动图案																			.Updated the startup pattern
* 1.1.3.3  2025.11.30  修复了模式切换时只能切换初始逻辑函数而不是设计的切换当前逻辑函数的BUG							.Fixed the bug where only the initial logic function could be switched during mode switching, instead of switching to the currently designed logic function.
* 1.1.4.0              添加了实体统计函数																		.Added ProjectFindEntityAllNumber function
* 1.1.4.1  2025.12.1   更新了按钮控件,添加了触发																	.Updated the button control and added a trigger
* 1.1.4.2              将按钮函数更换到了工具区																	.Moved the button function to the toolbar
* 1.1.5.0              添加了触发方式函数																		.Added ButtonSetTriggerMode function
* 1.1.5.1              添加了PROJECTMODULE宏,与PROJECTSETTING功能一样											.Added the PROJECTMODULE macro, which functions the same as PROJECTSETTING
* 1.1.5.2              更新了实体系统																			.Updated the entity system
* 1.1.6.0              实现了C++的适配,如果要使用C++版本的,请确保您所有.c的文件后缀已经改成.cpp						.C++ adaptation has been implemented. If you want to use the C++ version, please make sure all your .c file extensions have been changed to .cpp.
* 1.1.6.1              修复了ProjectFindEntityAllNumber函数的计数错误											.Fixed the counting error in the ProjectFindEntityAllNumber function
* 1.1.6.2              更新了实体系统,现在不再会有堆栈溢出的问题了。
                       因为PROJECTGOD里的ENTITYINDEX entityindex[ENTITYNUMBER];变成了ENTITYINDEX* entityindex;.The entity system has been updated, and there will no longer be stack overflow issues because ENTITYINDEX entityindex[ENTITYNUMBER]; in PROJECTGOD has been changed to ENTITYINDEX* entityindex;
* 1.1.6.3  2025.12.2   修复了引擎内部实体类型不正确的BUG															.Fixed a bug where the internal entity type of the engine was incorrect
* 1.1.6.4              更新了ProjectFindEntityAllNumber函数,现在会打印更详细的内容								.Updated the ProjectFindEntityAllNumber function, it will now print more detailed informatio
* 1.1.6.5              将Hash槽位改成质数,减少Hash冲突															.Change the hash slots to prime numbers to reduce hash collisions
* 1.1.6.6  2025.12.4   优化了主线程逻辑																		.Optimized the main thread logic
* 1.1.7.0              添加了动画创建函数AnimeCreate,现在创建动画不再是手动档了										.Added the animation creation function AnimeCreate, now creating animations is no longer done manually.
* 1.1.8.0              AnimeCreate函数功能实现错误,应该实现的是ImageLoadBatch函数,现在将重新实现AnimeCreate函数		.The AnimeCreate function is implemented incorrectly; it should implement the ImageLoadBatch function. The AnimeCreate function will now be re-implemented.
* 1.1.8.1  2025.12.5   解决了引擎内部的一个隐性BUG,即引擎内部的属性函数错误的保存了初始的函数导致的无论如何调整,
*                      都会回到最初的引擎传入最初的模块,即中央模块,现已修复。
*                      但我们仍然保留了它,如果您想要使用,可以在配置栏里将MOONCENTRALDISPATCHER改成1。					.Fixed an internal hidden bug in the engine, where the engine's internal property function incorrectly saved the initial function, causing it to always revert to the original module passed by the engine, namely the central module, regardless of any adjustments. This has now been fixed. However, we have kept it; if you want to use it, you can change MOONCENTRALDISPATCHER to 1 in the configuration panel.
* 1.1.8.2              添加了函数切换宏,防止您因手动切换模块导致的二级指针问题										.Added a function toggle macro to prevent secondary pointer issues caused by manually switching modules.
* 1.1.8.3              解决了鼠标坐标总是不稳定的问题																.Resolved the issue of the mouse coordinates being unstable.
* 1.1.8.4              修复了按钮系统的空回调函数指针BUG															.Fixed the bug of null callback function pointer in the button system
* 1.1.8.5  2025.12.6   更新了按钮系统,修复了一些BUG																.Updated the button system and fixed some bugs
* 1.1.8.6              修复了MOONCENTRALDISPATCHER的笔误														.Fixed a typo in MOONCENTRALDISPATCHER
* 1.1.8.7  2025.12.9   修复了ButtonDetection函数因为忘记取模造成的Hash溢出时的BUG									.Fixed a bug in the ButtonDetection function where forgetting to use the modulo caused a hash overflow
* 1.1.9.0  2025.12.10  添加了字符转换函数CharToWchar															.Added character conversion function CharToWchar
* 1.1.9.1  2026.1.14   添加了开发者控制台调控模式																.Added developer console control mode
* 1.2.0.0  2026.1.23   
*                      1.更换了API的名称,如果需要继续使用旧API,请导入Moon_Compatible_Function.c并且把MOONCOMPATIBLE配置打开
*                      2.正在逐步添加SDL支持
*                      3.删除了MOONCENTRALDISPATCHER配置选项
*                      4.基本完成引擎核心函数的SDL重写
* 
* 1.2.0.1  2026.1.24   
*                      1.完成了SDL下引擎原本就有休眠模式功能的重写
*                      2.解决了SDL的消息队列
* 1.2.0.2              解决了SDL下鼠标坐标的问题
* 1.2.0.3  2026.1.25   1.重构了绘图逻辑,将绘图逻辑改到单独的线程中,属性线程逻辑移到了主线程
*                      2.已测试重构后的GDI部分,和原来的效果相同
* 1.2.0.4  2026.1.26   解决了纹理创建失败的问题
* 1.2.0.5  2026.1.27   解决了SDL矩形绘制不了的问题,原因是参数SDL_Rect改成了SDL_FRect
* 1.2.0.6              更新了MoonSetDrawImage函数
* 1.2.0.7  2026.1.28   正在测试DrawingArea系列函数
*                      1.MoonDrawingArea      已通过
*                      2.MoonDrawingAreaRound 已通过
* 1.2.0.8  2026.1.29   1.MoonDrawingAreaAlpha 已通过
*                      2.修复了MoonDrawingAreaRound的锚点旋转,保持和GDI版本功能的相同
*                      3.动画系统测试完成
* 1.2.0.9  2026.1.30   修改了MoonAnimeRun的参数,现在倍数参数size从int改成了float
* 1.2.1.0              添加了MoonSDLTextFont系列函数
* 1.2.1.1              现在MoonDrawingAreaAlpha的最后一个参数有用了,它将用来控制Alpha通道
* 1.2.1.2              取消了MoonDrawingAreaAlpha函数最后一个参数的作用,该功能将集成到MoonModifyAlpha中,原因是性能太低,只要一次Alpha修饰就足够了
* 1.2.1.3  2026.1.31   修复了MoonImageLoadBatch的BUG
* 1.2.2.0  2026.2.1    新添加了MoonSetDrawImage和MoonImagePlgBit函数
*/

//创建线程函数关键字
typedef DWORD THREAD;

#if OPEN_SDL

typedef SDL_FPoint MOON_SDL_POINT;
typedef SDL_FRect MOON_SDL_RECT;

#endif

//定时器
typedef struct
{
	int time1;
	int time2;
	int timeload;
	BOOL timeswitch;
}TIMELOAD;
//对象
typedef struct
{
	char* nameid;
	int length;
	void* entityindex;
}ENTITYINDEX;																																		//实体
typedef struct PROJECTGOD
{
	const wchar_t* project_name;		//名字
#if !OPEN_SDL
	HWND hwnd;					//窗口句柄
#else
	SDL_Window* hwnd_sdl;		//窗口句柄
#endif
	int window_coord_x;			//水平坐标
	int window_coord_y;			//垂直坐标
	int window_width;			//宽度
	int window_height;			//高度
	char DEAD;					//项目状态
	char Power;					//高性能模式
	ENTITYINDEX* entityindex;	//对象池注册表
	TIMELOAD timeload;			//计时器
	int(*Logic)(struct PROJECTGOD*);		//多线程逻辑函数
	int(*Drawing)(struct PROJECTGOD*);		//主线程绘图函数
	int(*developerconsole)(struct PROJECTGOD*);	//开发者控制台,按下波浪号进入

#if OPEN_SDL

	SDL_Event sdl_event;

#endif

}PROJECTGOD;																															//项目结构体中心
//点结构体
typedef struct
{
	float x;
	float y;
	float z;
}POINT3D;
//双缓冲绘图
typedef struct
{
	HDC hdc;
	HBITMAP hBitmap;
	int width;
	int height;
}DOUBLEBUFFER;

#if OPEN_SDL

typedef struct 
{
	SDL_Texture* bitmapgpu;
	int width;//物理尺寸
	int height;
} DOUBLEBUFFER_SDL;

#endif

//图片
typedef struct
{
	POINT lengths;				//逻辑尺寸
#if OPEN_SDL
	DOUBLEBUFFER_SDL image;			//图片
#else
	DOUBLEBUFFER image;			//图片
#endif
}IMAGE;
//动画结构体
typedef struct
{
	LPCSTR Name;
	IMAGE* sequenceframes;		//序列帧数组
	long long int number;		//当前序列帧
	int totalnumber;			//序列帧总数
	BOOL animeswitch;			//动画动画播放开关
	TIMELOAD timeload;			//定时器
}ANIME;

//-------------------------------------------------------------------------------------------基础工具函数-----------------------------------------------------------------------------//

extern unsigned int MoonHash(char* text);
#define DegRad(phi) (Pi * (phi) * 1.f / 180.f)																															//角度转弧度
extern int MoonKeyState(int Key);																																		//获取按键的值
#define Lerp(alpha, beta, t) ((1.f - (t)) * (alpha) + (t) * (beta))																										//线性插值
#define RANGE(alpha, alpha_min, alpha_max) (min(max(alpha,alpha_min),alpha_max))																						//限制范围
#define SETMOUSECOORD( X, Y) SetCursorPos(X, Y)																															//设置鼠标位置
#define Random(A, B) (rand() % (B - A) + A)																																//随机数获取
extern void MoonMusic(const wchar_t* File);																																//播放音乐
#define CMD(YES_OR_ON) ShowWindow(GetConsoleWindow(), YES_OR_ON? SW_SHOW : SW_HIDE)																						//开关控制台
extern int MoonGetColor(IMAGE* image, int x, int y);																													//获取像素颜色
extern int MoonTriangleDetection(POINT a, POINT b, POINT c, POINT p);																									//三角形碰撞检测
extern void MoonRunProgram(const wchar_t* name);																														//运行外部程序

//------------------------------------定时函数--------------------------------------------------//

extern void MoonTimeLoadInit(TIMELOAD* Timeload, int load);																												//初始化定时器
extern int MoonTimeLoad(TIMELOAD* Timeload, int mode);																													//运行定时器
extern int MoonSleep(int timeload);																																		//暂停

//------------------------------------实体函数--------------------------------------------------//

extern void* MoonFindEntity(PROJECTGOD* project, char* nameid);																											//寻找实体
#define HashFindEntity(projectgod, nameid, type, entity) type* entity = (type*)MoonFindEntity(projectgod, (char*)nameid)												//hash寻找实体
extern int MoonCreateEntityIndex(PROJECTGOD* project, void* arrentity, char* nameid, int length);																		//注册实体

//------------------------------------双缓冲函数------------------------------------------------//

extern void MoonCreateImage(PROJECTGOD* project, IMAGE* image, int bmpwidth, int bmpheight);																			//创建双缓冲绘图绘图区
extern void MoonDeletImage(IMAGE* image);																																//删除双缓冲绘图绘图区

//------------------------------------多线程函数------------------------------------------------//

#define CREATETHREADFUNCTION(NAME)       THREAD NAME(LPARAM lparam)																										//创建多线程函数
#define CREATETHREAD(fuction,resource)   CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)fuction, (LPVOID)resource, 0, NULL);												//创建并运行多线程函数
#define GETTHREADRESOURCE(type,resource) type resource = (type)lparam;																									//获取外部导入的资源

//------------------------------------字符函数------------------------------------------------//

extern const wchar_t* MoonCharToLPCWSTR(char* str);																														//字符转换
extern int MoonCharToWchar(wchar_t* text1, char* text2, int len);																										//字符转换
extern int MoonWcharToChar(char* text1, wchar_t* text2, int len);																										//字符转换

extern void MoonTextFont(IMAGE* image, int x, int y, const wchar_t* text, COLORREF color, BOOL back, const wchar_t* font, int sizewidth, int sizeheight, int texttilt, int fonttilt, int FW_, int underline, int deleteline, int DEFAULT_);	//显示字符

#if OPEN_SDL

extern void MoonSDLTextInit(PROJECTGOD* project, IMAGE* textbuffer, const char* entity_name, int back_width, int back_height);								//初始化背景缓冲区
extern void MoonSDLTextFont(IMAGE* textbuffer, const char* text, int text_transparent_color, int back_transparent_color);									//绘制文字

#endif

//------------------------------------按钮控件------------------------------------------------//

enum
{
	MOON_BUTTONPRESS = 1,																																				//按下
	MOON_BUTTONRHOVER,																																					//悬停
};

typedef struct MOONBUTTON
{
	char nameid[255];
	int x;
	int y;
	int width;
	int height;
	char mode;
	unsigned char triggermode;
	int (*ButtonModePress)   (PROJECTGOD* project, struct MOONBUTTON* buton);	//按下
	int (*ButtonModeRelease) (PROJECTGOD* project, struct MOONBUTTON* buton);	//松开
	int (*ButtonModeHover)   (PROJECTGOD* project, struct MOONBUTTON* buton);	//悬停
}MOONBUTTON;

extern int MoonButtonInit(MOONBUTTON* button, int x, int y, int width, int height);																							//初始化按钮
extern int MoonButtonDetection(PROJECTGOD* project, char* name);																											//检测按钮Trigger
extern int MoonButtonSetTriggerMode(PROJECTGOD* project, char* name, unsigned char key);																					//更改触发方式

#define MOONBUTTONCREATE(project, name, button, x, y, width, height, Press, Release, Hover) \
MoonButtonInit(&button,(x), (y), (width), (height));                                        \
button.ButtonModeHover = Hover;                                                             \
button.ButtonModePress = Press;                                                             \
button.ButtonModeRelease = Release;                                                         \
strcpy(button.nameid , name);                                                               \
MoonCreateEntityIndex(project, &button, (char*)name, sizeof(MOONBUTTON));

//-------------------------------------------------------------------------------------------Windows函数----------------------------------------------------------------------------//

extern HWND MoonWindow(const wchar_t* name,int window_coord_x, int window_coord_y, int window_width, int window_height);													//创建窗口
extern void MoonRunWindow();																																				//窗口消息

//-------------------------------------------------------------------------------------------流程函数--------------------------------------------------------------------------------//

extern void MoonProjectInit(PROJECTGOD* project, const wchar_t* project_name, int x, int y, int width, int height, int fps,void (*ProjectSetting_1)(PROJECTGOD*));			//创建项目
extern void MoonProjectRun(PROJECTGOD* project, int (*ProjectSetting_2)(PROJECTGOD*), int(*ProjectLogic)(PROJECTGOD*), int(*ProjectDrawing)(PROJECTGOD*));					//运行项目
extern void MoonProjectOver(PROJECTGOD* project, void (*ProjectOverSetting)(PROJECTGOD*));																					//结束项目
#define PROJECTSETTING(NAME) void NAME(PROJECTGOD* project)																													//创建设置选项
#define PROJECTMODULE(NAME)  int NAME(PROJECTGOD* project)																													//配置模块
extern int MoonProjectError(void* alpha, int degree, char* text);																											//错误处理
extern int MoonProjectPause(int mode, int (**function_1)(PROJECTGOD*), int (*function_2)(PROJECTGOD*), int (*function_3)(PROJECTGOD*));										//暂停函数
extern void MoonProjectFunctionSwitch(int (**function_1)(PROJECTGOD*), int (*function_2)(PROJECTGOD*));																		//函数切换
#define FUNCTIONSWITCH(function) MoonProjectFunctionSwitch(&project->Drawing, function);																						//函数切换宏
extern int  MoonProjectFindEntityAllNumber(PROJECTGOD* project);																											//统计实体总数
#if OPEN_SDL

extern void MoonRendererLoad(PROJECTGOD* project);																															//加载SDL_Renderer

#endif
//-------------------------------------------------------------------------------------------绘制函数--------------------------------------------------------------------------------//

extern void MoonDrawingArea(IMAGE* image_1, IMAGE* image_2, int x, int y, int width, int height);																			//画板
extern void MoonDrawingAreaAlpha(IMAGE* image_1, IMAGE* image_2, int x, int y, int width, int height, int transparent_color);												//带透明度的画板
extern void MoonDrawingAreaRound(IMAGE* image_1, IMAGE* image_2, int x, int y, int apx, int apy, int width, int height, int deg);											//旋转的画板
extern void MoonPix(IMAGE* image, int x, int y, int color);																													//绘制点
extern void MoonLine(IMAGE* image, int x1, int y1, int x2, int y2, int width, int color);																					//绘制线
extern void MoonBox(IMAGE* image, int x1, int y1, int x2, int y2, int width, int color);																					//绘制矩形
extern void MoonBoxFull(IMAGE* image, int x1, int y1, int x2, int y2,int color);																							//绘制填充矩形

#if OPEN_SDL

extern void MoonPixAll(IMAGE* image, MOON_SDL_POINT* points, int allnumber, int color);																						//绘制点
extern void MoonLineAll(IMAGE* image, MOON_SDL_POINT* points, int allnumber, int color);																					//绘制线
extern void MoonBoxAll(IMAGE* image, MOON_SDL_RECT* points, int allnumber, int color);																						//绘制矩形
extern void MoonBoxFullAll(IMAGE* image, MOON_SDL_RECT* points, int allnumber, int color);																					//绘制填充矩形
extern void MoonImageDesignated(IMAGE* image);																																//设置绘图对象
extern void MoonSetDrawImage(IMAGE* image, int mode);																														//设置绘图模式
extern void MoonModifyAlpha(IMAGE* image, int transparent_color);																											//修饰Alpha通道
extern void MoonImagePlgBit(IMAGE* image_1, IMAGE* image_2, POINT point[4], int color);																						//纹理贴图

#endif

//------------------------------------图片------------------------------------------------//

extern void MoonImageLoad(IMAGE* image, const wchar_t** imagefile, int imagenumber);																						//加载图片
extern void MoonImageLoadBatch(PROJECTGOD* project, IMAGE* image, int totalnumber, const wchar_t** name, int width, int height);											//批量加载图片

//------------------------------------动画------------------------------------------------//

extern int MoonAnimeInit(ANIME* anime, LPCSTR name, IMAGE* sequenceframes, int timeload, int totalnumber, int width, int height);											//初始化动画
extern int MoonAnimeRun(IMAGE* image, ANIME* anime, int animeswitch, int x, int y, float widthsize, float heightsize);														//运行动画
extern void MoonAnimeDelete(ANIME* anime);																																	//删除动画
extern void MoonAnimeCreate(PROJECTGOD* project, IMAGE* image, ANIME* anime, int totalnumber, const wchar_t** animename, char* entityname, int timeload, int width, int height);	//创建动画
