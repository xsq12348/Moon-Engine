#include"Moon.h"

extern void DrawingArea(DOUBLEBUFFER* doublebuffer_1, DOUBLEBUFFER* doublebuffer_2,int x,int y,int width ,int height)
{
	BitBlt(doublebuffer_1->hdc, x, y, width, height, doublebuffer_1->hdc, 0, 0, SRCCOPY);
}

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

extern void DeletBuffer(DOUBLEBUFFER* doublebuffer)
{
	DeleteObject(doublebuffer->hBitmap);
	DeleteDC(doublebuffer->hdc);
}

extern void Pix(DOUBLEBUFFER* doublebuffer, int x, int y, int color)
{
	SetPixel(doublebuffer->hdc, x, y, color);
}

extern void Line(DOUBLEBUFFER* doublebuffer, int x1, int y1, int x2, int y2, int width, int color)
{
	HPEN hpen = CreatePen(PS_SOLID, width, color);
	HPEN holdpen = (HPEN)SelectObject(doublebuffer->hdc, hpen);
	MoveToEx(doublebuffer->hdc, x2, y2, NULL);
	LineTo(doublebuffer->hdc, x1, y1);
	SelectObject(doublebuffer->hdc, holdpen);
	DeleteObject(hpen);
}

extern void Box(DOUBLEBUFFER* doublebuffer, int x1, int y1, int x2, int y2,int width, int color)
{
	Line(doublebuffer, x1, y1, x2, y1, width, color);
	Line(doublebuffer, x1, y1, x1, y2, width, color);
	Line(doublebuffer, x1, y2, x2, y2, width, color);
	Line(doublebuffer, x2, y1, x2, y2, width, color);
}

extern void BoxFull(DOUBLEBUFFER* doublebuffer, int x1, int y1, int x2, int y2, int color)
{
	PAINTSTRUCT ps;
	HBRUSH hbs = CreateSolidBrush(color);
	RECT rect = { x1,y1,x2,y2 };
	FillRect(doublebuffer->hdc, &rect, hbs);
	DeleteObject(hbs);
}

extern void ImageLoad(IMAGE* image, LPCWSTR* imagefile, int imagenumber)
{
	if (imagenumber == 1)
	{
		HDC hdcmem;
		BITMAP bitmap;
		HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, *imagefile, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		GetObject(hBitmap, sizeof(BITMAP), &bitmap);
		hdcmem = CreateCompatibleDC(image->image.hdc);
		SelectObject(hdcmem, hBitmap);
		TransparentBlt(image->image.hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcmem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, RGB(1, 1, 1));
		image->lengths.x = bitmap.bmWidth;
		image->lengths.y = bitmap.bmHeight;
		DeleteDC(hdcmem);
		DeleteObject(hBitmap); // 释放位图资源
	}
	else if (imagenumber > 0)
		for (int i = 0; i < imagenumber; i++)
		{
			HDC hdcmem;
			BITMAP bitmap;
			HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, imagefile[i], IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			GetObject(hBitmap, sizeof(BITMAP), &bitmap);
			hdcmem = CreateCompatibleDC(image[i].image.hdc);
			SelectObject(hdcmem, hBitmap);
			TransparentBlt(image[i].image.hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcmem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, RGB(1, 1, 1));
			image[i].lengths.x = bitmap.bmWidth;
			image[i].lengths.y = bitmap.bmHeight;
			DeleteDC(hdcmem);
			DeleteObject(hBitmap); // 释放位图资源
		}
}

extern int InitialisationAnime(ANIME* anime, LPCSTR name, IMAGE* sequenceframes, int timeload, int totalnumber, int width, int height)
{
	anime->Name = name;
	if (totalnumber <= 0) { printf("[InitialisationAnime函数错误]动画序列帧总数有问题,请检查名为[%s]的动画!\n", name); return Error; }
	if (sequenceframes == NULL) { printf("[InitialisationAnime函数错误]动画序列帧有问题,请检查名为[%s]的动画是否存在!\n", name); return Error; }
	anime->animeswitch = 0;
	anime->sequenceframes = sequenceframes;
	anime->totalnumber = totalnumber;
	anime->number = 0;
	for (int i = 0; i < anime->totalnumber; i++)
	{
		anime->sequenceframes[i].lengths.x = width;
		anime->sequenceframes[i].lengths.y = height;
	}
	TimeLoadInit(&(anime->timeload), timeload);		//设置定时器
	return YES;
}

extern int RunAnime(DOUBLEBUFFER* doublebuffer, ANIME* anime, int animeswitch, int x, int y, int widthsize, int heightsize)
{
	if (!animeswitch)return 0;
	else
	{
		anime->number %= anime->totalnumber;
		TransparentBlt(doublebuffer->hdc, x, y, anime->sequenceframes[anime->number].lengths.x * widthsize, anime->sequenceframes[anime->number].lengths.y * heightsize, anime->sequenceframes[anime->number].image.hdc, 0, 0, anime->sequenceframes[anime->number].lengths.x, anime->sequenceframes[anime->number].lengths.y, RGB(1, 1, 1));
	}
	if (TimeLoad(&(anime->timeload), 1)) ++anime->number;	//添加下一帧	
	return anime->number;
}

