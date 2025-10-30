#pragma once
#include<stdio.h>
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

/*
该项目几乎相当于StarEngine项目的重构，Star项目请见:https://github.com/xsq12348/star

作者:xsq12348
Email:1993346266@qq.com
创建日期:2025.10.29
版本
最后一个是修改BUG/重构函数新版本号,第二个是添加函数,第三个是重构,第四个是正式的大版本号
* 0.0.0.0
* 1.0.0.0  2025.10.29  完成了基本框架的搭建
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
}ENTITYINDEX;																																			//实体
typedef struct PROJECTGOD
{
	LPCWSTR project_name;		//名字
	HWND hwnd;					//窗口句柄
	HDC hdc;					//窗口上下文
	int window_coord_x;			//水平坐标
	int window_coord_y;			//垂直坐标
	int window_width;			//宽度
	int window_height;			//高度
	int DEAD;					//项目结束
	int GamePower;				//高性能模式
	ENTITYINDEX entityindex[ENTITYNUMBER];//对象池注册表
	TIMELOAD timeload;			//计时器
	TIMELOAD fps;				//帧率
	THREAD(*Logic)(struct PROJECTGOD*);		//多线程逻辑函数
}PROJECTGOD;																																//项目结构体中心
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
	int x;
	int y;
}NEWPOINT;
typedef struct
{
	float x;
	float y;
	float z;
}POINT3D;

//-------------------------------------------------------------------------------------------基础工具函数-----------------------------------------------------------------------------//

unsigned int Hash(char* text);
#define DegRad(phi) (Pi * (phi) * 1.f / 180.f)																															//角度转弧度
#define Lerp(alpha, beta, t) ((1. - t) * alpha + t * beta)																												//线性插值
#define RANGE(alpha, alpha_min, alpha_max) (min(max(alpha,alpha_min),alpha_max))																						//线性插值

//------------------------------------定时函数------------------------------------------------//

//定时器模块
extern void TimeLoadInit(TIMELOAD* Timeload, int load);																													//初始化定时器
extern int TimeLoad(TIMELOAD* Timeload, int mode);																														//运行定时器

//------------------------------------实体函数------------------------------------------------//

#define HashFindEntityIndex(nameid) (Hash(nameid) % ENTITYNUMBER)																										//hash寻找实体
extern int CreateEntityIndex(PROJECTGOD* project, void* arrentity, char* nameid, int length);																			//注册实体

//------------------------------------双缓冲函数------------------------------------------------//

extern void CreateDoubleBuffer(PROJECTGOD* project, DOUBLEBUFFER* doublebuffer, int bmpwidth, int bmpheight);															//创建双缓冲绘图绘图区
extern void RUNDoubleBuffer(DOUBLEBUFFER* doublebuffer_1, DOUBLEBUFFER* doublebuffer_2, int x, int y);																	//运行双缓冲绘图
extern void DeletBuffer(HBITMAP hBitmap, HDC hdcMem);																													//删除双缓冲绘图绘图区

//-------------------------------------------------------------------------------------------多线程函数------------------------------------------------------------------------------//

#define CREATETHREADFUNCTION(NAME)        THREAD NAME(LPARAM lparam)																									//创建多线程函数
#define CREATETHREAD(fuction,resource)   CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)fuction, (LPVOID)resource, 0, NULL);												//创建并运行多线程函数
#define GETTHREADRESOURCE(type,resource) type resource = (type)lparam;																									//获取外部导入的资源

//-------------------------------------------------------------------------------------------Windows函数----------------------------------------------------------------------------//

extern HWND Window(LPCWSTR name,int window_coord_x, int window_coord_y, int window_width, int window_height);															//创建窗口
extern void RunWindow();																																				//窗口消息

//-------------------------------------------------------------------------------------------流程函数--------------------------------------------------------------------------------//

extern void ProjectInit(PROJECTGOD* project, LPCWSTR project_name, int x, int y, int width, int height, int fps,void (*ProjectSetting_1)(PROJECTGOD*));					//创建项目
extern void ProjectRun(PROJECTGOD* project, void (*ProjectSetting_2)(PROJECTGOD*), THREAD(*ProjectLogic)(PROJECTGOD*), void(*ProjectDrawing)(PROJECTGOD*));				//运行项目
extern void ProjectOver(PROJECTGOD* project);																															//结束项目
#define PROJECTSETTING(NAME) NAME(PROJECTGOD* project)																													//创建设置选项

//-------------------------------------------------------------------------------------------绘制函数--------------------------------------------------------------------------------//

#define Pix(projectgod, x, y, color) SetPixel(project->hdc, x, y, color);																								//绘制点
extern void Line(PROJECTGOD* project, int x1, int y1, int x2, int y2, int width, int color);																			//绘制线
//void Pix(PROJECTGOD* project, int x, int y, int color);																													
extern void Box(PROJECTGOD* project, int x1, int y1, int x2, int y2,int color);																							//绘制矩形
extern void BoxFull(PROJECTGOD* project, int x1, int y1, int x2, int y2,int color);																						//绘制填充矩形