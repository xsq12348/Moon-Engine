#include"Moon.h"

static LRESULT WINAPI WndPorc(HWND hwnd, UINT msgid, WPARAM wparam, LPARAM lparam)
{
	switch (msgid)
	{
	case WM_DESTROY: PostQuitMessage(0); break;
	case WM_PAINT: break;
	case WM_SETCURSOR:
	switch (LOWORD(lparam)) { default:SetCursor(LoadCursor(NULL, IDC_CROSS)); break; }
	}
	return DefWindowProc(hwnd, msgid, wparam, lparam);
}

unsigned int Hash(char* text)
{
	if (text == NULL)return Error;
	unsigned int length = strlen(text), hash = 0;
	if (length <= 0)return Error;
	for (int i = 0; i < length; i++)hash += text[i] * (i + 1);
	return hash;
}

extern void TimeLoadInit(TIMELOAD* Timeload, int load)
{
	Timeload->time1 = NULL;
	Timeload->time2 = NULL;
	Timeload->timeload = load;
	Timeload->timeswitch = 0;
}

extern int TimeLoad(TIMELOAD* Timeload, int mode)
{
	if (!mode)return 0;
	else if (Timeload == NULL)
		{
			printf("[TimeLoad函数错误!]存在空指针");
			return 0;
		}
		if (!Timeload->timeswitch)
		{
			Timeload->time1 = clock();
			if (Timeload->time1 > Timeload->time2 + Timeload->timeload)
			{
				Timeload->time2 = clock();
				Timeload->timeswitch = TRUE;
			}
		}
		else
		{
			Timeload->time2 = clock();
			Timeload->timeswitch = FALSE;
		}
		return Timeload->timeswitch;
}

extern int CreateEntityIndex(PROJECTGOD* project, void* arrentity, char* nameid, int length)
{
	int index = NOTFOUND;
	int hash = Hash(nameid) % ENTITYNUMBER;
	if (project->entityindex[hash].entityindex == NULL)
	{
		if (hash != Error)
		{
			index = hash;
			project->entityindex[index].entityindex = arrentity;
			project->entityindex[index].nameid = nameid;
			project->entityindex[index].length = length;
		}
		else printf("非法的字符串[%s],无法通过这个字符串得到哈希值", nameid);
	}
	else
	{
		printf("[%s]这个名字不合法，请换一个名字", nameid);
		index = NOTFOUND;
	}
	return index;
}

extern HWND Window(LPCWSTR name,int window_coord_x, int window_coord_y, int window_width, int window_height)
{
	HINSTANCE hinstance = GetModuleHandle(NULL);
	WNDCLASS wndclass;
	wndclass.cbClsExtra = NULL;
	wndclass.cbWndExtra = NULL;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hCursor = NULL;
	wndclass.hIcon = NULL;
	wndclass.hInstance = hinstance;
	wndclass.lpfnWndProc = WndPorc;
	wndclass.lpszClassName = name;
	wndclass.lpszMenuName = NULL;
	wndclass.style = NULL;
	RegisterClass(&wndclass);
	HWND hwnd = CreateWindow(name, name, WS_SYSMENU, window_coord_x, window_coord_y, window_width, window_height, NULL, NULL, hinstance, NULL);
	ShowWindow(hwnd, SW_SHOW);
}

extern void RunWindow()
{
	//消息循环
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

static CREATETHREADFUNCTION(ProjectLogic)
{	
	GETTHREADRESOURCE(PROJECTGOD*, project);
	while (!project->DEAD)
	{
		project->Logic(project);
	}
}

extern void ProjectInit(PROJECTGOD* project, LPCWSTR project_name, int x, int y, int width, int height,int fps, void (*ProjectSetting_1)(PROJECTGOD*))
{
	project->hwnd = Window(project_name, x, y, width, height);
	project->project_name = project_name;
	project->window_coord_x = x;
	project->window_coord_y = y;
	project->window_height = height;
	project->window_width = width;
	project->DEAD = FALSE;
	TimeLoadInit(&project->timeload, 1000 / fps);	//初始化定时器,用于帧率控制
	TimeLoadInit(&project->fps, 1000);				//记录帧率
	if (ProjectSetting_1 != NULL)ProjectSetting_1(project);
}

extern void ProjectRun(PROJECTGOD* project, void (*ProjectSetting_2)(PROJECTGOD*), THREAD(*LogicThread)(PROJECTGOD*), void(*ProjectDrawing)(PROJECTGOD*))
{
	MSG msg = { 0 };
	project->Logic = LogicThread;
	if (ProjectDrawing == NULL) { printf("\nError:[未传入任何有效的绘制函数],等级[Serious/严重]\n"); return; }
	if (ProjectSetting_2 != NULL)ProjectSetting_2(project);
	DOUBLEBUFFER doublebuffer;

	if (ProjectLogic != NULL) CREATETHREAD(ProjectLogic, project);
	while (!project->DEAD)
		if (PeekMessage(&msg, NULL, NULL, NULL, NULL))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (!IsWindow(project->hwnd))project->DEAD = YES;
			if (TimeLoad(&project->timeload, !project->GamePower))Sleep(1);		//控制帧率
			ProjectDrawing(project);
		}
}

extern void ProjectOver(PROJECTGOD* project)
{
	for (int i = 0; i = 0; i < ENTITYNUMBER)
	{
		project->entityindex[i].entityindex = NULL;
		project->entityindex[i].length		= NULL;
		project->entityindex[i].nameid		= NULL;
	}
}