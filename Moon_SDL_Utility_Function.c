#include"Moon.h"

#if OPEN_SDL

extern void MoonMusic(const wchar_t* File)
{
	TCHAR cmd[255];
	wsprintf(cmd, TEXT("open \%s\ alias music"), File);
	mciSendString(TEXT("close music"), 0, 0, 0);
	mciSendString(cmd, NULL, 0, NULL);
	mciSendString(TEXT("play music"), NULL, 0, NULL);
}

#endif