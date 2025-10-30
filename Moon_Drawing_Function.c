#include"Moon.h"

extern void CreateDoubleBuffer(PROJECTGOD* project, DOUBLEBUFFER *doublebuffer, int bmpwidth, int bmpheight)
{
	doublebuffer->width = bmpheight;
	HDC hdcMem = CreateCompatibleDC(GetDC(project->hwnd));
	doublebuffer->hBitmap = CreateCompatibleBitmap(GetDC(project->hwnd), bmpwidth, bmpheight);
	SelectObject(hdcMem, doublebuffer->hBitmap);
	doublebuffer->hdc = hdcMem;
}

extern void RUNDoubleBuffer(DOUBLEBUFFER* doublebuffer_1, DOUBLEBUFFER* doublebuffer_2,int x,int y) 
{ 
	BitBlt(doublebuffer_1->hdc, x, y, doublebuffer_1->width, doublebuffer_1->height, doublebuffer_2->hdc, 0, 0, SRCCOPY); 
}

extern void DeletBuffer(HBITMAP hBitmap, HDC hdcMem)
{
	DeleteObject(hBitmap);
	DeleteDC(hdcMem);
}

extern void Line(PROJECTGOD* project, int x1, int y1, int x2, int y2, int width, int color)
{
	HPEN hpen = CreatePen(PS_SOLID, width, color);
	HPEN holdpen = (HPEN)SelectObject(project->hdc, hpen);
	MoveToEx(project->hdc, x2, y2, NULL);
	LineTo(project->hdc, x1, y1);
	SelectObject(project->hdc, holdpen);
	DeleteObject(hpen);
}

extern void Box(PROJECTGOD* project, int x1, int y1, int x2, int y2, int color)
{

}

extern void BoxFull(PROJECTGOD* project, int x1, int y1, int x2, int y2, int color)
{

}