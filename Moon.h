#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include"Moon_Configuration.h"

#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#pragma comment( lib,"Winmm.lib")
#pragma comment(lib, "Msimg32.lib")

#define Error			-1
#define NOTFOUND		-1
#define YES				TRUE
#define NO				FALSE
#define ON				TRUE
#define OFF				FALSE
#define Pi				3.1415926f
#define ENTITYNUMBER	10000
#define TRANSPARENTCOLOR RGB(255,0,255)

/*
如果您感兴趣，还可以查看另一个功能更加强大但是已经落后的项目:Star,项目请见:https://github.com/xsq12348/star

作者:xsq12348
Email:1993346266@qq.com
创建日期:2025.10.29
版本
最后一个是修改BUG/重构函数/更新些许小功能,第二个是添加函数,第三个是重构,第四个是正式的大版本号
* 0.0.0.0
* 1.0.0.0  2025.10.29  完成了基本框架的搭建
* 1.0.0.1  2025.10.30  解决了按键检测，窗口输入，消息循环BUG,添加了一个线程用来记录项目运行中的各种属性
* 1.0.0.2  2025.10.31  解决了帧数显示不出来的问题
* 1.0.0.3  2025.11.2   加入了动画系统
* 1.0.0.3  2025.11.3   修改了帧率控制不稳定的问题
* 1.0.0.4			   将工具函数转移到了新的文件里
* 1.0.0.5  2025.11.4   添加了字符函数
* 1.0.0.6  2025.11.5   添加了图片旋转
* 1.0.0.7			   添加了获取像素颜色
* 1.0.0.8			   修复了HashFindEntity的BUG
* 1.0.0.9			   添加了三角形碰撞检测
* 1.0.0.10			   添加了运行外部程序
* 1.1.0.0			   引擎几乎搭建完成
* 1.1.0.1  2025.11.6   修复了DringAreaAlpha的BUG
* 1.1.0.2			   更新了ProjectOver函数
* 1.1.0.3  2025.11.7   添加了ProjectPause/暂停函数
* 1.1.0.4			   重构了ProjectGod结构体
* 1.1.0.5			   重构了ProjectRun函数
* 1.1.0.5			   修复了ProjectPause的BUG
* 1.1.0.6			   添加了ProjectFunctionSwitch/函数切换函数
* 1.1.1.0  2025.11.10  添加了SDL支持
* 1.1.1.1  2025.11.27  解决了StarEngine一直没有解决的窗口焦点问题
* 1.1.3.0  2025.11.29  添加了按钮控件
* 1.1.3.1              更新了启动图案
*/

//创建线程函数关键字
typedef DWORD THREAD;
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
	LPCWSTR project_name;		//名字
	HWND hwnd;					//窗口句柄
	int window_coord_x;			//水平坐标
	int window_coord_y;			//垂直坐标
	int window_width;			//宽度
	int window_height;			//高度
	int DEAD;					//项目结束
	int Power;					//高性能模式
	ENTITYINDEX entityindex[ENTITYNUMBER];//对象池注册表
	TIMELOAD timeload;			//计时器
	void(*Logic)(struct PROJECTGOD*);		//多线程逻辑函数
	void(*Drawing)(struct PROJECTGOD*);		//主线程绘图函数
}PROJECTGOD;																															//项目结构体中心
//双缓冲绘图
typedef struct
{
	HDC hdc;
	HBITMAP hBitmap;
	int width;
	int height;
}DOUBLEBUFFER;
//点结构体
typedef struct
{
	float x;
	float y;
	float z;
}POINT3D;
//图片
typedef struct
{
	POINT lengths;				//图片大小
	DOUBLEBUFFER image;			//图片
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

extern unsigned int Hash(char* text);
#define DegRad(phi) (Pi * (phi) * 1.f / 180.f)																															//角度转弧度
extern int KeyState(int Key);																																			//获取按键的值
#define Lerp(alpha, beta, t) ((1. - t) * alpha + t * beta)																												//线性插值
#define RANGE(alpha, alpha_min, alpha_max) (min(max(alpha,alpha_min),alpha_max))																						//线性插值
#define SETMOUSECOORD( X, Y) SetCursorPos(X, Y)																															//设置鼠标位置
#define Random(A, B) (rand() % (B - A) + A)																																//随机数获取
extern void Music(LPCWSTR File);																																		//播放音乐
#define CMD(YES_OR_ON) ShowWindow(GetConsoleWindow(), YES_OR_ON? SW_SHOW : SW_HIDE)																						//开关控制台
extern int GetColor(IMAGE* image, int x, int y);																														//获取像素颜色
extern int TriangleDetection(POINT a, POINT b, POINT c, POINT p);																										//三角形碰撞检测
extern void RunProgram(LPCWSTR name);																																	//运行外部程序

//------------------------------------定时函数--------------------------------------------------//

extern void TimeLoadInit(TIMELOAD* Timeload, int load);																													//初始化定时器
extern int TimeLoad(TIMELOAD* Timeload, int mode);																														//运行定时器
extern int MoonSleep(int timeload);																																		//暂停

//------------------------------------实体函数--------------------------------------------------//

#define HashFindEntity(projectgod, nameid, type, entity) type* entity = (type*)projectgod->entityindex[(Hash(nameid) % ENTITYNUMBER)].entityindex						//hash寻找实体
extern int CreateEntityIndex(PROJECTGOD* project, void* arrentity, char* nameid, int length);																			//注册实体

//------------------------------------双缓冲函数------------------------------------------------//

extern void CreateImage(PROJECTGOD* project, IMAGE* image, int bmpwidth, int bmpheight);																				//创建双缓冲绘图绘图区
extern void DeletImage(IMAGE* image);																																	//删除双缓冲绘图绘图区

//------------------------------------多线程函数------------------------------------------------//

#define CREATETHREADFUNCTION(NAME)       THREAD NAME(LPARAM lparam)																										//创建多线程函数
#define CREATETHREAD(fuction,resource)   CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)fuction, (LPVOID)resource, 0, NULL);												//创建并运行多线程函数
#define GETTHREADRESOURCE(type,resource) type resource = (type)lparam;																									//获取外部导入的资源

//------------------------------------字符函数------------------------------------------------//

extern LPCWSTR CharToLPCWSTR(char* str);																																//字符转换

extern void TextFont(IMAGE* image, int x, int y, LPCWSTR text, COLORREF color, BOOL back, LPCWSTR font, int sizewidth, int sizeheight, int texttilt, int fonttilt, int FW_, int underline, int deleteline, int DEFAULT_);	//显示字符

//-------------------------------------------------------------------------------------------Windows函数----------------------------------------------------------------------------//

extern HWND Window(LPCWSTR name,int window_coord_x, int window_coord_y, int window_width, int window_height);															//创建窗口
extern void RunWindow();																																				//窗口消息

//-------------------------------------------------------------------------------------------流程函数--------------------------------------------------------------------------------//

extern void ProjectInit(PROJECTGOD* project, LPCWSTR project_name, int x, int y, int width, int height, int fps,void (*ProjectSetting_1)(PROJECTGOD*));					//创建项目
extern void ProjectRun(PROJECTGOD* project, void (*ProjectSetting_2)(PROJECTGOD*), THREAD(*ProjectLogic)(PROJECTGOD*), void(*ProjectDrawing)(PROJECTGOD*));				//运行项目
extern void ProjectOver(PROJECTGOD* project, void (*ProjectOverSetting)(PROJECTGOD*));																					//结束项目
#define PROJECTSETTING(NAME) NAME(PROJECTGOD* project)																													//创建设置选项
extern void ProjectError(void* alpha, int degree, char* text);																											//错误处理
extern void ProjectPause(int mode, void (**function_1)(PROJECTGOD), void (*function_2)(PROJECTGOD), void (*function_3)(PROJECTGOD));									//暂停函数
extern void ProjectFunctionSwitch(void (**function_1)(PROJECTGOD), void (*function_2)(PROJECTGOD));																		//函数切换

//-------------------------------------------------------------------------------------------绘制函数--------------------------------------------------------------------------------//

extern void DrawingArea(IMAGE* image_1, IMAGE* image_2, int x, int y, int width, int height);																			//画板
extern void DrawingAreaAlpha(IMAGE* image_1, IMAGE* image_2, int x, int y, int width, int height, int transparent_color);												//带透明度的画板
extern void DrawingAreaRound(IMAGE* image_1, IMAGE* image_2, int x, int y, int apx, int apy, int width, int height, int deg);											//旋转的画板
extern void Pix(IMAGE* image, int x, int y, int color);																													//绘制点
extern void Line(IMAGE* image, int x1, int y1, int x2, int y2, int width, int color);																					//绘制线
extern void Box(IMAGE* image, int x1, int y1, int x2, int y2, int width, int color);																					//绘制矩形
extern void BoxFull(IMAGE* image, int x1, int y1, int x2, int y2,int color);																							//绘制填充矩形

extern void SDL_Moon_DrawingArea(IMAGE* image_1, IMAGE* image_2, int x, int y, int width, int height);																	//画板
extern void SDL_Moon_DrawingAreaAlpha(IMAGE* image_1, IMAGE* image_2, int x, int y, int width, int height, int transparent_color);										//带透明度的画板
extern void SDL_Moon_DrawingAreaRound(IMAGE* image_1, IMAGE* image_2, int x, int y, int apx, int apy, int width, int height, int deg);									//旋转的画板
extern void SDL_Moon_Pix(IMAGE* image, int x, int y, int color);																										//绘制点
extern void SDL_Moon_Line(IMAGE* image, int x1, int y1, int x2, int y2, int width, int color);																			//绘制线
extern void SDL_Moon_Box(IMAGE* image, int x1, int y1, int x2, int y2, int width, int color);																			//绘制矩形
extern void SDL_Moon_BoxFull(IMAGE* image, int x1, int y1, int x2, int y2, int color);																					//绘制填充矩形
extern int  SDL_Moon_AnimeInit(ANIME* anime, LPCSTR name, IMAGE* sequenceframes, int timeload, int totalnumber, int width, int height);									//运行动画
extern int  SDL_Moon_AnimeRun(IMAGE* image, ANIME* anime, int animeswitch, int x, int y, int widthsize, int heightsize);												//删除动画

//------------------------------------图片------------------------------------------------//

extern void ImageLoad(IMAGE* image, LPCWSTR* imagefile, int imagenumber);																								//加载图片

//------------------------------------动画------------------------------------------------//

extern int AnimeInit(ANIME* anime, LPCSTR name, IMAGE* sequenceframes, int timeload, int totalnumber, int width, int height);											//初始化动画
extern int AnimeRun(IMAGE* image, ANIME* anime, int animeswitch, int x, int y, int widthsize, int heightsize);															//运行动画
extern void AnimeDelete(ANIME* anime);																																	//删除动画

//-------------------------------------------------------------------------------------------绘制函数--------------------------------------------------------------------------------//

//------------------------------------按钮控件------------------------------------------------//

enum
{
	MOON_BUTTONRELEASE,
	MOON_BUTTONPRESS,
	MOON_BUTTONRHOVER,
};

typedef struct MOONBUTTON
{
	char nameid[255];
	int x;
	int y;
	int width;
	int height;
	int mode;
	int (*ButtonModePress)   (PROJECTGOD* project, struct MOONBUTTON* buton);	//按下
	int (*ButtonModeRelease) (PROJECTGOD* project, struct MOONBUTTON* buton);	//松开
	int (*ButtonModeHover)   (PROJECTGOD* project, struct MOONBUTTON* buton);	//悬停
}MOONBUTTON;

extern int ButtonInit(MOONBUTTON* button, int x, int y, int width, int height);																							//初始化按钮
extern int ButtonDetection(PROJECTGOD* project, char* name);																											//检测按钮

#define MOONBUTTON(project, name, button, x, y, width, height, Press, Release, Hover) \
MOONBUTTON button; ButtonInit(&button,(x),(y),(width),(height));                      \
button.ButtonModeHover = Hover;                                                       \
button.ButtonModePress = Press;                                                       \
button.ButtonModeRelease = Release;                                                   \
strcpy(button.nameid , name);                                                         \
CreateEntityIndex(project, &button, name, sizeof(MOONBUTTON));
