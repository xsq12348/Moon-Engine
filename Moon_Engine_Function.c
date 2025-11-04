#include"Moon.h"

static TIMELOAD projectfps;
static int fpsmax, fpsmax2;
static IMAGE projectdoublebuffer;
static POINT projectmousecoord;

#ifdef WIN_Platform

static LRESULT WINAPI WndPorc(HWND hwnd, UINT msgid, WPARAM wparam, LPARAM lparam)
{
	switch (msgid)
	{
	case WM_DESTROY: PostQuitMessage(0); break;
	case WM_SETCURSOR:
		switch (LOWORD(lparam))
		{
		default:SetCursor(LoadCursor(NULL, IDC_CROSS));
			break;
		}
		break;
	}
	return DefWindowProc(hwnd, msgid, wparam, lparam);
}

extern HWND Window(LPCWSTR name,int window_coord_x, int window_coord_y, int window_width, int window_height)
{
	HINSTANCE hinstance = GetModuleHandle(NULL);
	WNDCLASS wndclass = { 0 };
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
	return hwnd;
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

#endif


static CREATETHREADFUNCTION(ProjectLogic)
{	
	GETTHREADRESOURCE(PROJECTGOD*, project);
	while (!project->DEAD)
		project->Logic(project);
}

static CREATETHREADFUNCTION(ProjectAttribute)
{
	GETTHREADRESOURCE(PROJECTGOD*, project);
	HashFindEntity(project,"ProjectMouseCoord", POINT, mousecoord);
	HashFindEntity(project,"ProjectFPS", int, fpsnumber);

	while (!project->DEAD)
	{
		GetCursorPos(mousecoord);
		ScreenToClient(project->hwnd, mousecoord);
		Sleep(1);
	}
}

extern void ProjectInit(PROJECTGOD* project, LPCWSTR project_name, int x, int y, int width, int height, int fps, void (*ProjectSetting_1)(PROJECTGOD*))
{
	if (x < 0 || y < 0)
	{
		x = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
		y = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	}
	project->hwnd = Window(project_name, x, y, width, height);
	project->project_name = project_name;
	project->window_coord_x = x;
	project->window_coord_y = y;
	project->window_height = height;
	project->window_width = width;
	project->DEAD = FALSE;
	TimeLoadInit(&project->timeload, 1000.f / (fps > 0 ? fps : 60));
	TimeLoadInit(&projectfps, 1000);
	CreateImage(project, &projectdoublebuffer, project->window_width, project->window_height);
	CreateEntityIndex(project, &fpsmax2, "ProjectFPS", 1);
	CreateEntityIndex(project, &projectmousecoord, "ProjectMouseCoord", 1);
	CreateEntityIndex(project, &projectdoublebuffer, "ProjectBitmap", 1);
	if (ProjectSetting_1 != NULL)ProjectSetting_1(project);
}

extern void ProjectRun(PROJECTGOD* project, void (*ProjectSetting_2)(PROJECTGOD*), THREAD(*LogicThread)(PROJECTGOD*), void(*ProjectDrawing)(PROJECTGOD*))
{
	MSG msg = { 0 };
	HDC hdc = GetDC(project->hwnd);
	project->Logic = LogicThread;
	if (ProjectDrawing == NULL)
	{
		ProjectError(ProjectDrawing, 1, "绘图函数传入失败!");
		return;
	}
	if (ProjectSetting_2 != NULL)ProjectSetting_2(project);
	if (LogicThread != NULL) CREATETHREAD(ProjectLogic, project);
	CREATETHREAD(ProjectAttribute, project);
	HashFindEntity(project, "ProjectBitmap", IMAGE, projectbitmap);
	int runload[3] = { 0 };
	while (!project->DEAD)
	{
		runload[0] = clock();
		if (!IsWindow(project->hwnd))project->DEAD = YES;
		{
			if (!TimeLoad(&projectfps, TRUE))fpsmax++;
			else { fpsmax2 = fpsmax; fpsmax = 0; }
		}
		{
			BoxFull(projectbitmap, 0, 0, project->window_width, project->window_height, RGB(0, 0, 0));
			ProjectDrawing(project);
			BitBlt(hdc, 0, 0, project->window_width, project->window_height, projectbitmap->image.hdc, 0, 0, SRCCOPY);
		}
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		runload[1] = clock();
		runload[2] = runload[1] - runload[0];
		!project->Power&& runload[2] < project->timeload.timeload && !TimeLoad(&project->timeload, TRUE) && MoonSleep((project->timeload.timeload - runload[2]));
	}
}

extern void ProjectOver(PROJECTGOD* project)
{
	if (project == NULL)
	{
		ProjectError(project, 2, "核心对象[projectgod]丢失!");
		return;
	}
	HashFindEntity(project, "ProjectBitmap", DOUBLEBUFFER, projectbitmap);
	DeletImage(projectbitmap);
	for (int i = 0; i < ENTITYNUMBER; i++)
	{
		project->entityindex[i].entityindex = NULL;
		project->entityindex[i].length		= NULL;
		project->entityindex[i].nameid		= NULL;
	}
}

extern void ProjectError(void* alpha, int degree, char* text)
{
	enum
	{
		Serious = 1,
		General,
		Mild,
	};
	printf("\n来自[%p]的[%s]发生错误!现在转入错误处理函数[ProjectError]", alpha, text);
	switch (degree)
	{
	case Serious:printf("\t等级[Serious/严重]\n"); break;
	case General:printf("\t等级[General/一般]\n"); break;
	case Mild:printf("\t等级[Mild/轻微]\n"); break;
	}
	while (!KeyState(VK_ESCAPE)) Sleep(1);
}
