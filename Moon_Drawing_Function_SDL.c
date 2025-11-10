#include"Moon.h"
#ifdef OPEN_SDL

extern void SDL_DrawingArea(IMAGE* image_1, IMAGE* image_2, int x, int y, int width, int height)
{

}

extern void SDL_DrawingAreaAlpha(IMAGE* image_1, IMAGE* image_2, int x, int y, int width, int height, int transparent_color)
{

}

extern void SDL_DrawingAreaRound(IMAGE* image_1, IMAGE* image_2, int x, int y, int apx, int apy, int width, int height, int deg)
{

}

extern void SDL_Pix(IMAGE* image, int x, int y, int color)
{

}

extern void SDL_Line(IMAGE* image, int x1, int y1, int x2, int y2, int width, int color)
{

}

extern void SDL_Box(IMAGE* image, int x1, int y1, int x2, int y2, int width, int color)
{

}

extern void SDL_BoxFull(IMAGE* image, int x1, int y1, int x2, int y2, int color)
{
	
}

extern int SDL_AnimeInit(ANIME* anime, LPCSTR name, IMAGE* sequenceframes, int timeload, int totalnumber, int width, int height)
{
	
}

extern int SDL_AnimeRun(IMAGE* image, ANIME* anime, int animeswitch, int x, int y, int widthsize, int heightsize)
{
	
}

#endif