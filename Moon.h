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
#include <d3d11.h>
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
*					   1. The API name has been changed. If you need to continue using the old API, please import Moon_Compatible_Function.c and enable the MOONCOMPATIBLE configuration.
*					   2. Gradually adding SDL support.
*					   3. The MOONCENTRALDISPATCHER configuration option has been removed.
*					   4. The SDL rewrite of the engine core functions is basically completed.
* 
* 1.2.0.1  2026.1.24   
*                      1.完成了SDL下引擎原本就有休眠模式功能的重写
*                      2.解决了SDL的消息队列
*					   1. Completed the rewriting of the engine's original sleep mode function under SDL
*					   2. Fixed SDL's message queue
* 1.2.0.2              解决了SDL下鼠标坐标的问题																.Solved the issue of mouse coordinates in SDL
* 1.2.0.3  2026.1.25   1.重构了绘图逻辑,将绘图逻辑改到单独的线程中,属性线程逻辑移到了主线程
*                      2.已测试重构后的GDI部分,和原来的效果相同
*					   1. Refactored the drawing logic, moving the drawing logic to a separate thread and the property thread logic to the main thread
*					   2. The refactored GDI part has been tested and the effect is the same as before
* 1.2.0.4  2026.1.26   解决了纹理创建失败的问题																	.Resolved the issue of texture creation failure
* 1.2.0.5  2026.1.27   解决了SDL矩形绘制不了的问题,原因是参数SDL_Rect改成了SDL_FRect								.Solved the problem of SDL rectangles not being drawable; the reason was that the parameter SDL_Rect was changed to SDL_FRect.
* 1.2.0.6              更新了MoonSetDrawImage函数																.Updated the MoonSetDrawImage function
* 1.2.0.7  2026.1.28   正在测试DrawingArea系列函数
*                      1.MoonDrawingArea      已通过
*                      2.MoonDrawingAreaRound 已通过
*					   Testing the DrawingArea series of functions
*					   1. MoonDrawingArea passed
*					   2. MoonDrawingAreaRound passed
* 1.2.0.8  2026.1.29   1.MoonDrawingAreaAlpha 已通过
*                      2.修复了MoonDrawingAreaRound的锚点旋转,保持和GDI版本功能的相同
*                      3.动画系统测试完成
*					   1. MoonDrawingAreaAlpha has passed
*					   2. Fixed the anchor rotation of MoonDrawingAreaRound to maintain the same functionality as the GDI version
*					   3. Animation system testing completed
* 1.2.0.9  2026.1.30   修改了MoonAnimeRun的参数,现在倍数参数size从int改成了float									.Modified the parameters of MoonAnimeRun, now the multiplier parameter size has been changed from int to float
* 1.2.1.0              添加了MoonSDLTextFont系列函数															.Added the MoonSDLTextFont series of functions
* 1.2.1.1              现在MoonDrawingAreaAlpha的最后一个参数有用了,它将用来控制Alpha通道							.Now the last parameter of MoonDrawingAreaAlpha is useful; it will be used to control the Alpha channel.
* 1.2.1.2              取消了MoonDrawingAreaAlpha函数最后一个参数的作用,该功能将集成到MoonModifyAlpha中,原因是性能太低,只要一次Alpha修饰就足够了.The effect of the last parameter of the MoonDrawingAreaAlpha function has been removed. This functionality will be integrated into MoonModifyAlpha because the performance is too low, and a single Alpha modification is sufficient.
* 1.2.1.3  2026.1.31   修复了MoonImageLoadBatch的BUG															.Fixed the bug in MoonImageLoadBatch
* 1.2.2.0  2026.2.1    新添加了MoonSetDrawImage和MoonImagePlgBit函数											.Newly added MoonSetDrawImage and MoonImagePlgBit functions
* 1.2.2.1              修复了MoonImagePlgBit函数在透明度变化时不能显示的BUG										.Fixed the bug in the MoonImagePlgBit function where it could not display when the opacity changed
* 1.2.2.2  2026.3.16   修复了在切換回GDI時的未定義BUG															.Fixed an undefined bug when switching back to GDI
* 1.2.2.3              修復了MoonTextFont函數的BUG																.Fixed a bug in the MoonTextFont function
* 1.2.2.4  2026.4.5    新增了MoonDrawingAreaUV函數,現在可以使用UV矩形坐標											.Added the MoonDrawingAreaUV function, now UV rectangular coordinates can be used
* 1.2.2.5  2026.4.7    將SDL的透明混合模式改成了SDL_SCALEMODE_NEAREST											.Changed SDL's alpha blending mode to SDL_SCALEMODE_NEAREST
* 1.2.2.6  2026.4.9    修復了幀率控制失效的問題																	.Fixed the issue frame rate control not working
* 1.2.2.7  2026.4.13   新增了	MoonCircle函數,用於繪製圓形														.Added the MoonCircle function, used for drawing circles
* 1.2.2.8  2026.4.14   新增了image_old功能,減少SDL_SetRenderTarget帶來的狀態切換提升性能							.Added the image_old feature, reducing state switches caused by SDL_SetRenderTarget to improve performance
* 請注意,由於本人的疏忽,忘記了更新函數不是小版本號,1.2.2.4版本應該是1.2.3.0,那麽1.2.2.7應該是1.2.4.0,但是本人不會再更改舊版本號,從這裏開始應用新版本號
* 這算是一個小問題,只有1.2.3.x和1.2.4.0有問題
* 1.2.4.1  2026.4.15   將MoonImagePlgBit函數的名字改成了MoonDrawingAreaPlgBit,您可以開啓兼容模式以使用原來的名字
* 1.2.4.2			   完成了SDL模式下的MoonGetColor,現在這個函數在SDL下可以使用了
* 1.2.5.0			   新增了MoonImageHandlePassageMatrix函數,可以修飾紋理顔色通道
* 1.2.5.1  2026.4.16   修復了一些函數返回值的錯誤,比如int (*ProjectSetting_2)(PROJECTGOD*)改成了void (*ProjectSetting_2)(PROJECTGOD*)
*					   這是一些在C++下的小錯誤
* 從這個版本開始,我們將逐步把GDI換成DirectX 11
* 因爲DirectX 11涉及到C++,可能要換語言
* 這是極其一個重大的更新,遠非重構可比
* 因此版本號為2.x.x.x
* 未來的繪圖架構將采用消息式
* 開發者不再能夠自由的調用繪圖函數,繪圖函數底層將會變成向引擎呼叫消息
* 引擎根據消息機中的消息來繪圖
* 不過表現形式上與以前沒有區別
* 不過不用擔心,作爲作者的我完全不會C++(笑)
* 大概率依舊會用傳統的C語法來寫作
* 1.2.5.1版本可能是1.0最後一個版本
* 
* 2.0.0.beta	2026.4.16
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

/*
* 函數 MoonHash
* 作用 求字符串的Hash值
* 使用方法 
* char arr[12] = "Hello_World";
* int alpha = Moonhash(arr)
*/
extern unsigned int MoonHash(char* text);

/*
* 函數 DegRad
* 作用 求弧度值
* 使用方法 
* float alpha = cos(DegRad(45));
*/
#define DegRad(phi) (Pi * (phi) * 1.f / 180.f)																															//角度转弧度

/*
* 函數 MoonKeyState
* 作用 獲取硬件狀態
* 使用方法 
* _Bool alpha = MoonKeyState(VK_SPACE);
*/
extern int MoonKeyState(int Key);																																		//获取按键的值

/*
* 函數 Lerp
* 作用 線性插值
* 使用方法
* float alpha = Lerp(0, 1, .5f);
*/
#define Lerp(alpha, beta, t) ((1.f - (t)) * (alpha) + (t) * (beta))																										//线性插值

/*
* 函數 RANGE
* 作用 限制範圍
* 使用方法
* int alpha = RANGE(beta, 0, 100);
*/
#define RANGE(alpha, alpha_min, alpha_max) (min(max(alpha,alpha_min),alpha_max))																						//限制范围

/*
* 函數 SETMOUSECOORD
* 作用 設置鼠標位置
* 使用方法 
* SETMOUSECOORD(x, y);
*/
#define SETMOUSECOORD( X, Y) SetCursorPos(X, Y)																															//设置鼠标位置

/*
* 函數 Random
* 作用 獲取隨機數
* 使用方法 
* int alpha = Random(0, 100);
*/
#define Random(A, B) (rand() % (B - A) + A)																																//随机数获取

/*
* 函數 MoonMusic
* 作用 播放音樂
* 使用方法
* MoonMusic("music.mp3");
*/
extern void MoonMusic(const wchar_t* File);																																//播放音乐

/*
* 函數 CMD
* 作用 开关控制台
* 使用方法
* CMD(ON);
* CMD(OFF);
*/
#define CMD(YES_OR_ON) ShowWindow(GetConsoleWindow(), YES_OR_ON? SW_SHOW : SW_HIDE)																						//开关控制台

/*
* 函數 MoonGetColor
* 作用 獲取紋理像素顔色
* 使用方法
* int color = MoonGetColor(image, 0, 0);
*/
extern int MoonGetColor(IMAGE* image, int x, int y);																													//获取像素颜色

/*
* 函數 MoonTriangleDetection
* 作用 檢測點與三角形的位置關係
* 使用方法
* POINT point[4] = 
* {
*	{0,0},
*	{10,0},
*	{0,10},
*	{5,50}
* };
* _Bool = MoonTriangleDetection(point[0], point[1], point[2], point[3]);
*/
extern int MoonTriangleDetection(POINT a, POINT b, POINT c, POINT p);																									//三角形碰撞检测

/*
* 函數 MoonRunProgram
* 作用 运行外部程序
* 使用方法
* MoonRunProgram("Game.exe");
*/
extern void MoonRunProgram(const wchar_t* name);																														//运行外部程序

//------------------------------------定时函数--------------------------------------------------//


/*
* 函數 MoonTimeLoadInit
* 作用 初始化定時器
* 使用方法
* TIMELOAD load;
* MoonTimeLoadInit(&load, 100);
*/
extern void MoonTimeLoadInit(TIMELOAD* Timeload, int load);																												//初始化定时器

/*
* 函數 MoonTimeLoad
* 作用 運行定時器
* 使用方法
* MoonTimeLoad(&load, 1);
*/
extern int MoonTimeLoad(TIMELOAD* Timeload, int mode);																													//运行定时器

/*
* 函數 MoonSleep
* 作用 暫停
* 使用方法
* MoonSleep(1);
*/
extern int MoonSleep(int timeload);																																		//暂停

//------------------------------------实体函数--------------------------------------------------//


/*
* 函數 MoonFindEntity
* 作用 尋找實體
* 使用方法
* int* entity = (int*)MoonFindEntity(projectgod, (char*)nameid)
*/
extern void* MoonFindEntity(PROJECTGOD* project, char* nameid);																											//寻找实体

/*
* 函數 HashFindEntity
* 作用 hash寻找实体
* 使用方法
* HashFindEntity(project, "ProjectBitmap", int, engineback);
*/
#define HashFindEntity(projectgod, nameid, type, entity) type* entity = (type*)MoonFindEntity(projectgod, (char*)nameid)												//hash寻找实体

/*
* 函數 MoonCreateEntityIndex
* 作用 注册实体
* 使用方法
* static TIMELOAD logictps;
* MoonCreateEntityIndex(project, &logictps, "LogicTps", sizeof(TIMELOAD));
*/
extern int MoonCreateEntityIndex(PROJECTGOD* project, void* arrentity, char* nameid, int length);																		//注册实体

//------------------------------------双缓冲函数------------------------------------------------//


/*
* 函數 MoonCreateImage
* 作用 创建双缓冲绘图绘图区
* 使用方法
* IMAGE buffer;
* MoonCreateImage(project, &buffer, project->window_width, project->window_height);
*/
extern void MoonCreateImage(PROJECTGOD* project, IMAGE* image, int bmpwidth, int bmpheight);																			//创建双缓冲绘图绘图区

/*
* 函數 MoonDeletImage
* 作用 删除双缓冲绘图绘图区/紋理
* 使用方法
* MoonDeletImage(bitmap);
*/
extern void MoonDeletImage(IMAGE* image);																																//删除双缓冲绘图绘图区

//------------------------------------多线程函数------------------------------------------------//


/*
* 函數 创建多线程函数
* 作用 CREATETHREADFUNCTION
* 使用方法
* CREATETHREADFUNCTION(Thread);
*/
#define CREATETHREADFUNCTION(NAME)       THREAD NAME(LPARAM lparam)																										//创建多线程函数

/*
* 函數 CREATETHREAD
* 作用 创建并运行多线程函数
* 使用方法
* CREATETHREAD(Thread, project);
*/
#define CREATETHREAD(fuction,resource)   CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)fuction, (LPVOID)resource, 0, NULL);												//创建并运行多线程函数

/*
* 函數 GETTHREADRESOURCE
* 作用 获取多綫程函數外部导入的资源
* 使用方法
* static CREATETHREADFUNCTION(Thread)
* {
*	GETTHREADRESOURCE(PROJECTGOD*, project);
*	return 1;
* }
*/
#define GETTHREADRESOURCE(type,resource) type resource = (type)lparam;																									//获取外部导入的资源

//------------------------------------字符函数------------------------------------------------//


/*
* 注意!這個函數不好用,就不寫使用方法了
* 函數 MoonCharToLPCWSTR
* 作用 字符转换
* 使用方法
* MoonCharToLPCWSTR()
*/
extern const wchar_t* MoonCharToLPCWSTR(char* str);																														//字符转换

/*
* 函數 MoonCharToWchar
* 作用 字符转换
* 使用方法
* wchar_t* text1;
* char* text2 = "Hello";
* MoonCharToWchar(text1, text2, 5);
*/
extern int MoonCharToWchar(wchar_t* text1, char* text2, int len);																										//字符转换

/*
* 函數
* 作用 字符转换
* 使用方法
* char* text1;
* wchar_t* text2 = L"Hello";
* MoonCharToWchar(text1, text2, 5);
*/
extern int MoonWcharToChar(char* text1, wchar_t* text2, int len);																										//字符转换

/*
* 函數 MoonTextFont
* 作用 在圖像上顯示文字
* 使用方法
* MoonTextFont(&image, 10, 10, L"Hello", RGB(255,255,255), TRUE, L"宋體", 24, 24, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE);
*/
extern void MoonTextFont(IMAGE* image, int x, int y, const wchar_t* text, COLORREF color, BOOL back, const wchar_t* font, int sizewidth, int sizeheight, int texttilt, int fonttilt, int FW_, int underline, int deleteline, int DEFAULT_);	//显示字符

#if OPEN_SDL


/*
* 函數 MoonSDLTextInit
* 作用 初始化SDL文字繪製緩衝區
* 使用方法
* IMAGE textbuffer;
* MoonSDLTextInit(project, &textbuffer, "TextBuffer", 256, 64);
*/
extern void MoonSDLTextInit(PROJECTGOD* project, IMAGE* textbuffer, const char* entity_name, int back_width, int back_height);								//初始化背景缓冲区

/*
* 函數 MoonSDLTextFont
* 作用 使用SDL繪製文字到緩衝區
* 使用方法
* MoonSDLTextFont(&textbuffer, "Hello World", RGB(255,255,255), RGB(0,0,0));
*/
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


/*
* 函數 MoonButtonInit
* 作用 初始化按鈕控件
* 使用方法
* MOONBUTTON btn;
* MoonButtonInit(&btn, 10, 10, 100, 50);
*/
extern int MoonButtonInit(MOONBUTTON* button, int x, int y, int width, int height);																							//初始化按钮

/*
* 函數 MoonButtonDetection
* 作用 檢測按鈕觸發狀態
* 使用方法
* if(MoonButtonDetection(project, "MyButton") == MOON_BUTTONPRESS) { ... }
*/
extern int MoonButtonDetection(PROJECTGOD* project, char* name);																											//检测按钮Trigger

/*
* 函數 MoonButtonSetTriggerMode
* 作用 更改按鈕觸發方式
* 使用方法
* MoonButtonSetTriggerMode(project, "MyButton", MOON_BUTTONPRESS);
*/
extern int MoonButtonSetTriggerMode(PROJECTGOD* project, char* name, unsigned char key);																					//更改触发方式

/*
* 函數 MOONBUTTONCREATE
* 作用 便捷注冊按鈕
* 使用方法
* static MOONBUTTON button
* MOONBUTTONCREATE(project, name, x, y, w, h, 0, 0, 0);
*/
#define MOONBUTTONCREATE(project, name, button, x, y, width, height, Press, Release, Hover) \
MoonButtonInit(&button,(x), (y), (width), (height));                                        \
button.ButtonModeHover = Hover;                                                             \
button.ButtonModePress = Press;                                                             \
button.ButtonModeRelease = Release;                                                         \
strcpy(button.nameid , name);                                                               \
MoonCreateEntityIndex(project, &button, (char*)name, sizeof(MOONBUTTON));

//-------------------------------------------------------------------------------------------Windows函数----------------------------------------------------------------------------//


/*
* 函數 MoonWindow
* 作用 創建Windows窗口
* 使用方法
* HWND hwnd = MoonWindow(L"MyGame", 100, 100, 800, 600);
*/
extern HWND MoonWindow(const wchar_t* name,int window_coord_x, int window_coord_y, int window_width, int window_height);													//创建窗口

/*
* 注意!内部已經存在消息循環,請不要放入循環中
* 函數 MoonRunWindow
* 作用 處理窗口消息循環
* 使用方法
* MoonRunWindow();
*/
extern void MoonRunWindow();																																				//窗口消息

//-------------------------------------------------------------------------------------------流程函数--------------------------------------------------------------------------------//


/*
* 函數 MoonProjectInit
* 作用 初始化遊戲項目
* 使用方法
* PROJECTGOD game;
* MoonProjectInit(&game, L"MyGame", 100, 100, 800, 600, 60, GameSetting);
*/
extern void MoonProjectInit(PROJECTGOD* project, const wchar_t* project_name, int x, int y, int width, int height, int fps,void (*ProjectSetting_1)(PROJECTGOD*));			//创建项目

/*
* 函數 MoonProjectRun
* 作用 運行遊戲項目主循環
* 使用方法
* MoonProjectRun(&game, GameInit, GameLogic, GameDrawing);
*/
extern void MoonProjectRun(PROJECTGOD* project, void (*ProjectSetting_2)(PROJECTGOD*), int(*ProjectLogic)(PROJECTGOD*), int(*ProjectDrawing)(PROJECTGOD*));					//运行项目

/*
* 函數 MoonProjectOver
* 作用 結束遊戲項目，釋放資源
* 使用方法
* MoonProjectOver(&game, GameCleanup);
*/
extern void MoonProjectOver(PROJECTGOD* project, void (*ProjectOverSetting)(PROJECTGOD*));																					//结束项目

/*
* 函數
* 作用
* 使用方法

*/
#define PROJECTSETTING(NAME) void NAME(PROJECTGOD* project)																													//创建设置选项

/*
* 函數
* 作用
* 使用方法

*/
#define PROJECTMODULE(NAME)  int NAME(PROJECTGOD* project)																													//配置模块

/*
* 函數 MoonProjectError
* 作用 錯誤處理函數
* 使用方法
* MoonProjectError(NULL, 1, "Something went wrong!");
*/
extern int MoonProjectError(void* alpha, int degree, char* text);																											//错误处理

/*
* 注意!這個函數對你的代碼沒有任何作用!僅僅是引擎内部初始化使用的,你可以使用MoonProjectFunctionSwitch來獲得更好的效果
* 函數 MoonProjectPause
* 作用 暫停/恢復項目運行
* 使用方法
* MoonProjectPause(1, &project->Logic, NULL, NULL);
*/
extern int MoonProjectPause(int mode, int (**function_1)(PROJECTGOD*), int (*function_2)(PROJECTGOD*), int (*function_3)(PROJECTGOD*));										//暂停函数

/*
* 函數 MoonProjectFunctionSwitch
* 作用 切換項目中的函數指針
* 使用方法
* MoonProjectFunctionSwitch(&project->Drawing, NewDrawingFunction);
*/
extern void MoonProjectFunctionSwitch(int (**function_1)(PROJECTGOD*), int (*function_2)(PROJECTGOD*));																		//函数切换

/*
* 函數
* 作用
* 使用方法

*/
#define FUNCTIONSWITCH(function) MoonProjectFunctionSwitch(&project->Drawing, function);																					//函数切换宏

/*
* 函數 MoonProjectFindEntityAllNumber
* 作用 統計項目中已註冊的實體總數
* 使用方法
* int count = MoonProjectFindEntityAllNumber(project);
*/
extern int  MoonProjectFindEntityAllNumber(PROJECTGOD* project);																											//统计实体总数
#if OPEN_SDL


/*
* 注意!這個函數對你的代碼沒有任何作用!僅僅是引擎内部初始化使用的
* 函數 MoonRendererLoad
* 作用 加載SDL渲染器，從實體系統中獲取渲染器和紋理
* 使用方法
* MoonRendererLoad(project);
*/
extern void MoonRendererLoad(PROJECTGOD* project);																															//加载SDL_Renderer

#endif
//-------------------------------------------------------------------------------------------绘制函数--------------------------------------------------------------------------------//


/*
* 函數 MoonDrawingArea
* 作用 將image_2繪製到image_1上，不帶透明度
* 使用方法
* MoonDrawingArea(&backBuffer, &sprite, 10, 20, 64, 64);
*/
extern void MoonDrawingArea(IMAGE* image_1, IMAGE* image_2, int x, int y, int width, int height);																			//画板

/*
* 函數 MoonDrawingAreaAlpha
* 作用 將image_2繪製到image_1上，帶透明度（透明色）
* 使用方法
* MoonDrawingAreaAlpha(&backBuffer, &sprite, 10, 20, 64, 64, TRANSPARENTCOLOR);
*/
extern void MoonDrawingAreaAlpha(IMAGE* image_1, IMAGE* image_2, int x, int y, int width, int height, int transparent_color);												//带透明度的画板

/*
* 函數 MoonDrawingAreaRound
* 作用 將image_2旋轉後繪製到image_1上
* 使用方法
* MoonDrawingAreaRound(&backBuffer, &sprite, 100, 100, 32, 32, 64, 64, 45);
*/
extern void MoonDrawingAreaRound(IMAGE* image_1, IMAGE* image_2, int x, int y, int apx, int apy, int width, int height, int deg);											//旋转的画板

/*
* 函數 MoonPix
* 作用 在圖像上繪製一個像素點
* 使用方法
* MoonPix(&image, 10, 10, RGB(255,0,0));
*/
extern void MoonPix(IMAGE* image, int x, int y, int color);																													//绘制点

/*
* 函數 MoonLine
* 作用 在圖像上繪製線條
* 使用方法
* MoonLine(&image, 0, 0, 100, 100, 2, RGB(255,255,255));
*/
extern void MoonLine(IMAGE* image, int x1, int y1, int x2, int y2, int width, int color);																					//绘制线

/*
* 函數 MoonBox
* 作用 在圖像上繪製矩形邊框
* 使用方法
* MoonBox(&image, 10, 10, 100, 100, 2, RGB(255,0,0));
*/
extern void MoonBox(IMAGE* image, int x1, int y1, int x2, int y2, int width, int color);																					//绘制矩形

/*
* 函數 MoonBoxFull
* 作用 在圖像上繪製填充矩形
* 使用方法
* MoonBoxFull(&image, 10, 10, 100, 100, RGB(255,0,0));
*/
extern void MoonBoxFull(IMAGE* image, int x1, int y1, int x2, int y2,int color);																							//绘制填充矩形

#if OPEN_SDL


/*
* 函數 MoonCircle
* 作用 在圖像上繪製圓形
* 使用方法
* MoonCircle(&image, 50, 50, 30, RGB(255,0,0));
*/
extern void MoonCircle(IMAGE* image, int x, int y, int r, int color);																										//繪製圓

/*
* 函數 MoonPixAll
* 作用 批量繪製多個像素點
* 使用方法
* MOON_SDL_POINT points[] = {{10,10},{20,20},{30,30}};
* MoonPixAll(&image, points, 3, RGB(255,0,0));
*/
extern void MoonPixAll(IMAGE* image, MOON_SDL_POINT* points, int allnumber, int color);																						//绘制点

/*
* 函數 MoonLineAll
* 作用 批量繪製多條線段
* 使用方法
* MOON_SDL_POINT lines[] = {{0,0},{100,100},{100,0},{0,100}};
* MoonLineAll(&image, lines, 4, RGB(255,255,255));
*/
extern void MoonLineAll(IMAGE* image, MOON_SDL_POINT* points, int allnumber, int color);																					//绘制线

/*
* 函數 MoonBoxAll
* 作用 批量繪製多個矩形邊框
* 使用方法
* MOON_SDL_RECT rects[] = {{10,10,50,50},{70,10,50,50}};
* MoonBoxAll(&image, rects, 2, RGB(255,0,0));
*/
extern void MoonBoxAll(IMAGE* image, MOON_SDL_RECT* points, int allnumber, int color);																						//绘制矩形

/*
* 函數 MoonBoxFullAll
* 作用 批量繪製多個填充矩形
* 使用方法
* MOON_SDL_RECT rects[] = {{10,10,50,50},{70,10,50,50}};
* MoonBoxFullAll(&image, rects, 2, RGB(255,0,0));
*/
extern void MoonBoxFullAll(IMAGE* image, MOON_SDL_RECT* points, int allnumber, int color);																					//绘制填充矩形

/*
* 函數 MoonImageDesignated
* 作用 手動指定當前的渲染目標紋理
* 使用方法
* MoonImageDesignated(&backBuffer);
*/
extern void MoonImageDesignated(IMAGE* image);																																//设置绘图对象

/*
* 函數 MoonSetDrawImage
* 作用 設置紋理的混合模式
*	case 0:return; break; 
* 	case 1:SDL_SetTextureBlendMode(image->image.bitmapgpu, SDL_BLENDMODE_NONE); break;
	case 2:SDL_SetTextureBlendMode(image->image.bitmapgpu, SDL_BLENDMODE_BLEND); break;
	case 3:SDL_SetTextureBlendMode(image->image.bitmapgpu, SDL_BLENDMODE_BLEND_PREMULTIPLIED); break;
	case 4:SDL_SetTextureBlendMode(image->image.bitmapgpu, SDL_BLENDMODE_ADD); break;
	case 5:SDL_SetTextureBlendMode(image->image.bitmapgpu, SDL_BLENDMODE_ADD_PREMULTIPLIED); break;
	case 6:SDL_SetTextureBlendMode(image->image.bitmapgpu, SDL_BLENDMODE_MOD); break;
	case 7:SDL_SetTextureBlendMode(image->image.bitmapgpu, SDL_BLENDMODE_MUL); break;
	case 8:SDL_SetTextureBlendMode(image->image.bitmapgpu, SDL_BLENDMODE_INVALID); break;
* 使用方法
* MoonSetDrawImage(&sprite, 2);
*/
extern void MoonSetDrawImage(IMAGE* image, int mode);																														//设置绘图模式

/*
* 函數 MoonModifyAlpha
* 作用 修改整個紋理的全局透明度
* 使用方法
* MoonModifyAlpha(&sprite, 128);  // 設置半透明
*/
extern void MoonModifyAlpha(IMAGE* image, int transparent_color);																											//修饰Alpha通道

/*
* 函數 MoonDrawingAreaPlgBit
* 作用 將image_2進行四點透視變換後繪製到image_1上（紋理貼圖）
* 使用方法
* POINT points[4] = {{0,0},{100,0},{0,100},{100,100}};
* MoonDrawingAreaPlgBit(&backBuffer, &texture, points, RGB(255,255,255));
*/
extern void MoonDrawingAreaPlgBit(IMAGE* image_1, IMAGE* image_2, POINT point[4], int color);																				//纹理贴图

/*
* 函數 MoonDrawingAreaUV
* 作用 將image_2的指定UV區域繪製到image_1上
* 使用方法
* MoonDrawingAreaUV(&backBuffer, &sprite, 10, 20, 64, 64, 0, 0, 32, 32);
*/
extern void MoonDrawingAreaUV(IMAGE* image_1, IMAGE* image_2, int x, int y, int width, int height, int uv_x1, int uv_y1, int uv_width, int uv_height);						//UV纹理贴图

/*
* 函數 MoonImageHandlePassageMatrix
* 作用 修飾Image顔色通道
* 使用方法
* 最好不要運行時修飾
* 
* 		float matrix[9] =
		{
			1.f,0.f,0.f,	//R通道
			0.f,1.f,0.f,	//G通道
			0.f,0.f,1.f,	//B通道
		};
		MoonImageHandlePassageMatrix(&imagell, matrix, 0, 0, imagell.image.width, imagell.image.height);
*/
extern int MoonImageHandlePassageMatrix(IMAGE* image, float passage[9], int x, int y, unsigned int width, unsigned int height);

#endif

//------------------------------------图片------------------------------------------------//


/*
* 函數 MoonImageLoad
* 作用 加載BMP圖片到紋理中
* 使用方法
* const wchar_t* files[] = {L"1.bmp", L"2.bmp"};
* MoonImageLoad(&image, files, 2);
*/
extern void MoonImageLoad(IMAGE* image, const wchar_t** imagefile, int imagenumber);																						//加载图片

/*
* 函數 MoonImageLoadBatch
* 作用 批量創建紋理並加載圖片
* 使用方法
* IMAGE frames[10];
* const wchar_t* names[] = {L"frame1.bmp", L"frame2.bmp", ...};
* MoonImageLoadBatch(project, frames, 10, names, 64, 64);
*/
extern void MoonImageLoadBatch(PROJECTGOD* project, IMAGE* image, int totalnumber, const wchar_t** name, int width, int height);											//批量加载图片

//------------------------------------动画------------------------------------------------//


/*
* 函數 MoonAnimeInit
* 作用 初始化動畫結構體
* 使用方法
* ANIME anim;
* MoonAnimeInit(&anim, "Walk", frames, 100, 8, 64, 64);
*/
extern int MoonAnimeInit(ANIME* anime, LPCSTR name, IMAGE* sequenceframes, int timeload, int totalnumber, int width, int height);											//初始化动画

/*
* 函數 MoonAnimeRun
* 作用 運行動畫，繪製當前幀
* 使用方法
* MoonAnimeRun(&backBuffer, &anim, 1, x, y, 1.0f, 1.0f);
*/
extern int MoonAnimeRun(IMAGE* image, ANIME* anime, int animeswitch, int x, int y, float widthsize, float heightsize);														//运行动画

/*
* 函數 MoonAnimeDelete
* 作用 刪除動畫並釋放所有序列幀紋理
* 使用方法
* MoonAnimeDelete(&anim);
*/
extern void MoonAnimeDelete(ANIME* anime);																																	//删除动画

/*
* 函數 MoonAnimeCreate
* 作用 一步創建完整的動畫（批量加載圖片+初始化動畫+註冊實體）
* 使用方法
* IMAGE frames[10];
* ANIME anim;
* const wchar_t* names[] = {L"1.bmp", L"2.bmp", ...};
* MoonAnimeCreate(project, frames, &anim, 10, names, "PlayerAnim", 100, 64, 64);
*/
extern void MoonAnimeCreate(PROJECTGOD* project, IMAGE* image, ANIME* anime, int totalnumber, const wchar_t** animename, char* entityname, int timeload, int width, int height);	//创建动画
