#include "background.h"

int loadBackground(Background *Backg)
{
	// load background
	Backg->backgroundImg = IMG_Load("niveau11.png");
	if (Backg->backgroundImg == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}
	
	
	return (0);
}


void initBackground(Background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0;
	Backg->backgroundPos.w=SCREEN_W;
	Backg->backgroundPos.h=SCREEN_H;
}


void blitBackground(Background*Backg,SDL_Surface *screen)
{
	//Blit the bachground to the backbuffer
	if(Backg->backgroundPos.x>Backg->backgroundImg->w-SCREEN_W)
		Backg->backgroundPos.x=0;
	if(Backg->backgroundPos.x<0)
		Backg->backgroundPos.x=Backg->backgroundImg->w-SCREEN_W;
	SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen,NULL); //scrolling horizontal

}

void freeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
}