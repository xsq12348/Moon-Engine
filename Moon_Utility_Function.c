#include"Moon.h"

static int KEYSTATEbuffer[255];

extern unsigned int Hash(char* text)
{
	if (text == NULL)return Error;
	unsigned int length = (unsigned)strlen(text), hash = 0;
	if (length <= 0)return Error;
	for (unsigned int i = 0; i < length; i++)hash += text[i] * (i + 1);
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
	if (!mode)return FALSE;
	else if (Timeload == NULL)
	{
		printf("Error:[TimeLoad函数错误!]存在空指针");
		return Error;
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

extern int MoonSleep(int timeload)
{
	Sleep(timeload);
	return 0;
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
		else printf("非法的名称[%s],无法通过这个字符串得到合法的索引", nameid);
	}
	else
	{
		printf("非法的名称[%s]，请换一个名字", nameid);
		index = NOTFOUND;
	}
	return index;
}

extern int KeyState(int Key)
{
	int state = GetAsyncKeyState(Key);
	if (state & 0x8000)
	{
		if (KEYSTATEbuffer[Key] == 0) { KEYSTATEbuffer[Key] = 1; return 1; }
		return 0;
	}
	else { KEYSTATEbuffer[Key] = 0; return 0; }
}

extern void Music(LPCWSTR File)
{
    TCHAR cmd[255];
    wsprintf(cmd, TEXT("open \%s\ alias music"), File);
    mciSendString(TEXT("close music"), 0, 0, 0);
    mciSendString(cmd, NULL, 0, NULL);
    mciSendString(TEXT("play music"), NULL, 0, NULL);
}

extern LPCWSTR CharToLPCWSTR(char* str)
{
	static wchar_t* wideStr;
	wideStr = (wchar_t*)malloc(strlen(str) * sizeof(wchar_t));
	MultiByteToWideChar(CP_UTF8, 0, str, -1, wideStr, strlen(str));
	return wideStr;
}

extern void TextFont(IMAGE* image, int x, int y, LPCWSTR text, COLORREF color, BOOL back, LPCWSTR font, int sizewidth, int sizeheight, int texttilt, int fonttilt, int FW_, int underline, int deleteline, int DEFAULT_)
{
	if (!back)SetBkMode(image->image.hdc, TRANSPARENT);
	HFONT hfont = CreateFont(sizeheight, sizewidth, texttilt, fonttilt, FW_, FALSE, underline, deleteline, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_, font);
	SelectObject(image->image.hdc, hfont);
	SetTextColor(image->image.hdc, color);
	TextOut(image->image.hdc, x, y, text, wcslen(text));
	HFONT hfontold = (HFONT)GetStockObject(SYSTEM_FONT);
	SelectObject(image->image.hdc, hfontold);
	DeleteObject(hfont);
}

extern int GetColor(IMAGE* image, int x, int y)
{
	return GetPixel(image->image.hdc, x, y);
}

extern int TriangleDetection(POINT a, POINT b, POINT c, POINT p)
{
	int d1 = (p.x - b.x) * (a.y - b.y) - (a.x - b.x) * (p.y - b.y);
	int d2 = (p.x - c.x) * (b.y - c.y) - (b.x - c.x) * (p.y - c.y);
	int d3 = (p.x - a.x) * (c.y - a.y) - (c.x - a.x) * (p.y - a.y);
	return (d1 * d2 > 0) && (d2 * d3 > 0);
}

extern void RunProgram(LPCWSTR name) 
{ 
	ShellExecute(NULL, L"open", name, NULL, NULL, SW_SHOW); 
}
