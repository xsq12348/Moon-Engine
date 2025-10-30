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
����Ŀ�����൱��StarEngine��Ŀ���ع���Star��Ŀ���:https://github.com/xsq12348/star

����:xsq12348
Email:1993346266@qq.com
��������:2025.10.29
�汾
���һ�����޸�BUG/�ع������°汾��,�ڶ�������Ӻ���,���������ع�,���ĸ�����ʽ�Ĵ�汾��
* 0.0.0.0
* 1.0.0.0  2025.10.29  ����˻�����ܵĴ
*/

//�����̺߳����ؼ���
typedef DWORD THREAD;
//��ʱ��
typedef struct
{
    int time1;
    int time2;
    int timeload;
    BOOL timeswitch;
}TIMELOAD;
//����
typedef struct
{
	char* nameid;
	int length;
	void* entityindex;
}ENTITYINDEX;																																			//ʵ��
typedef struct PROJECTGOD
{
	LPCWSTR project_name;		//����
	HWND hwnd;					//���ھ��
	HDC hdc;					//����������
	int window_coord_x;			//ˮƽ����
	int window_coord_y;			//��ֱ����
	int window_width;			//���
	int window_height;			//�߶�
	int DEAD;					//��Ŀ����
	int GamePower;				//������ģʽ
	ENTITYINDEX entityindex[ENTITYNUMBER];//�����ע���
	TIMELOAD timeload;			//��ʱ��
	TIMELOAD fps;				//֡��
	THREAD(*Logic)(struct PROJECTGOD*);		//���߳��߼�����
}PROJECTGOD;																																//��Ŀ�ṹ������
//˫�����ͼ
typedef struct
{
	HDC hdc;
	HBITMAP hBitmap;
	int width;
	int height;
}DOUBLEBUFFER;
//��ṹ��
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

//-------------------------------------------------------------------------------------------�������ߺ���-----------------------------------------------------------------------------//

unsigned int Hash(char* text);
#define DegRad(phi) (Pi * (phi) * 1.f / 180.f)																															//�Ƕ�ת����
#define Lerp(alpha, beta, t) ((1. - t) * alpha + t * beta)																												//���Բ�ֵ
#define RANGE(alpha, alpha_min, alpha_max) (min(max(alpha,alpha_min),alpha_max))																						//���Բ�ֵ

//------------------------------------��ʱ����------------------------------------------------//

//��ʱ��ģ��
extern void TimeLoadInit(TIMELOAD* Timeload, int load);																													//��ʼ����ʱ��
extern int TimeLoad(TIMELOAD* Timeload, int mode);																														//���ж�ʱ��

//------------------------------------ʵ�庯��------------------------------------------------//

#define HashFindEntityIndex(nameid) (Hash(nameid) % ENTITYNUMBER)																										//hashѰ��ʵ��
extern int CreateEntityIndex(PROJECTGOD* project, void* arrentity, char* nameid, int length);																			//ע��ʵ��

//------------------------------------˫���庯��------------------------------------------------//

extern void CreateDoubleBuffer(PROJECTGOD* project, DOUBLEBUFFER* doublebuffer, int bmpwidth, int bmpheight);															//����˫�����ͼ��ͼ��
extern void RUNDoubleBuffer(DOUBLEBUFFER* doublebuffer_1, DOUBLEBUFFER* doublebuffer_2, int x, int y);																	//����˫�����ͼ
extern void DeletBuffer(HBITMAP hBitmap, HDC hdcMem);																													//ɾ��˫�����ͼ��ͼ��

//-------------------------------------------------------------------------------------------���̺߳���------------------------------------------------------------------------------//

#define CREATETHREADFUNCTION(NAME)        THREAD NAME(LPARAM lparam)																									//�������̺߳���
#define CREATETHREAD(fuction,resource)   CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)fuction, (LPVOID)resource, 0, NULL);												//���������ж��̺߳���
#define GETTHREADRESOURCE(type,resource) type resource = (type)lparam;																									//��ȡ�ⲿ�������Դ

//-------------------------------------------------------------------------------------------Windows����----------------------------------------------------------------------------//

extern HWND Window(LPCWSTR name,int window_coord_x, int window_coord_y, int window_width, int window_height);															//��������
extern void RunWindow();																																				//������Ϣ

//-------------------------------------------------------------------------------------------���̺���--------------------------------------------------------------------------------//

extern void ProjectInit(PROJECTGOD* project, LPCWSTR project_name, int x, int y, int width, int height, int fps,void (*ProjectSetting_1)(PROJECTGOD*));					//������Ŀ
extern void ProjectRun(PROJECTGOD* project, void (*ProjectSetting_2)(PROJECTGOD*), THREAD(*ProjectLogic)(PROJECTGOD*), void(*ProjectDrawing)(PROJECTGOD*));				//������Ŀ
extern void ProjectOver(PROJECTGOD* project);																															//������Ŀ
#define PROJECTSETTING(NAME) NAME(PROJECTGOD* project)																													//��������ѡ��

//-------------------------------------------------------------------------------------------���ƺ���--------------------------------------------------------------------------------//

#define Pix(projectgod, x, y, color) SetPixel(project->hdc, x, y, color);																								//���Ƶ�
extern void Line(PROJECTGOD* project, int x1, int y1, int x2, int y2, int width, int color);																			//������
//void Pix(PROJECTGOD* project, int x, int y, int color);																													
extern void Box(PROJECTGOD* project, int x1, int y1, int x2, int y2,int color);																							//���ƾ���
extern void BoxFull(PROJECTGOD* project, int x1, int y1, int x2, int y2,int color);																						//����������