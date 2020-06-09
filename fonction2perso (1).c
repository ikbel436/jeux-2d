#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "fonction.h"

void animed (SDL_Rect animepos[],int *frame)
{
if(*frame<4)
*frame=3;
(*frame)++;


if(*frame>7)
*frame=4;


}

void animeg (SDL_Rect animepos[],int *frame)
{
if (*frame>=4)
*frame=-1;
(*frame)++;
if (*frame==2)
*frame=3;


if(*frame>3)
*frame=0;
}
void initializeHero(Perso* perso)
{
	SDL_Surface* tmp  ;
         tmp = IMG_Load("anim.png");
	perso->image = tmp;


	SDL_Rect pos;
	pos.x=0;
	pos.y=265;
	perso->positionimage=pos;
	perso->score=0;
	perso->vies=20;
}

