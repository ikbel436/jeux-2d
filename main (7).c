#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
//#include "collisionscrolling.h"
int main()
{
SDL_Surface * screen =NULL,*background2=NULL,*background1=NULL,*image2=NULL,*image3=NULL ;
SDL_Rect posbg1,posbg2,position1,position2,pos[8];


int X,Y,W,H,c;
 int continuer = 1;
SDL_Event event;
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(1700,1300,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
//**************************************************************************************** background 1 Du haut  ************************
background1=SDL_CreateRGBSurface(SDL_HWSURFACE,1280,1720,32,0,0,0,0);

background1 = IMG_Load("background.png");
posbg1.x=0;
posbg1.y=0;
SDL_BlitSurface(background1,NULL,screen,&posbg1);

// ***************************************************************************************** background 2 du bas ***************
background2=SDL_CreateRGBSurface(SDL_HWSURFACE,1280,1720,32,0,0,0,0);
background2=IMG_Load("background.png");
posbg2.x=0;
posbg2.y=591;
SDL_BlitSurface(background2,NULL, screen, &posbg2);
//***************************************************************************************** perso 1 *****************
image2 =  IMG_Load("detective.png");
SDL_SetColorKey(image2,SDL_SRCCOLORKEY,SDL_MapRGB(image2->format,255,255,255));
position1.x=60;
position1.y=355;
SDL_BlitSurface(image2, NULL, screen, &position1);

//****************************************************************************************** perso 2  ****************
image3= IMG_Load("detective.png");
SDL_SetColorKey(image3,SDL_SRCCOLORKEY,SDL_MapRGB(image3->format,255,255,255));
position2.x=60;
position2.y=940;
SDL_BlitSurface(image3, NULL, screen, &position2);

//**********************************************************************************************************************
while (continuer==1)
{
SDL_WaitEvent(&event);
	switch(event.type)
    {

case SDL_QUIT: 
                    continuer = 0;



case SDL_KEYDOWN:

if((event.key.keysym.sym==SDLK_ESCAPE)){
continuer = 0 ;
}
//************************************************************ deplacment 1
//******RIGHT******
if((event.key.keysym.sym==SDLK_RIGHT))
{
if(posbg1.x<=posbg1.w){
		 posbg1.x+=20 ;
		SDL_BlitSurface(background1,&posbg1,screen, NULL);
}
position1.x+=50;	
}
//******LEFT******
if((event.key.keysym.sym==SDLK_LEFT))
{
	if(posbg1.x>=0){
posbg1.x-=20;
SDL_BlitSurface(background1,&posbg1,screen, NULL);
}
position1.x-=50;
}
//************************************************************** deplacment 2
//******RIGHT******
if((event.key.keysym.sym==SDLK_d))
{
	

if(posbg2.x<=posbg2.w){
		
		 posbg2.x+=20 ;
		 SDL_BlitSurface(background2,&posbg2,screen,NULL);

		
}
position2.x+=50;
}
//******LEFT******
if((event.key.keysym.sym==SDLK_q))
{
		if(posbg2.x>=0){
		 posbg2.x-=20 ;
		 SDL_BlitSurface(background2,&posbg2,screen,NULL);
}
position2.x-=50;
}
//**************************************************************
break;
}
pos[1].x=X;
pos[1].y=Y;
pos[2].x=X+(W/2);
pos[2].y=Y;
pos[3].x=X+W;
pos[3].y=Y;
pos[4].x=X;
pos[4].y=Y+(H/2);
pos[5].x=X;
pos[5].y=Y+H;
pos[6].x=X+(W/2);
pos[6].y=Y+H;
pos[7].x=X+W;
pos[7].y=Y+H;
pos[8].x=X+W;
pos[8].y=Y+(H/2);
//colision_perfectp(p,b->background);
//SDL_BlitSurface(background1,0,screen,&position);

SDL_BlitSurface(image2, NULL, screen, &position1);
SDL_BlitSurface(image3, NULL, screen, &position2);


SDL_Flip(screen);
}
SDL_Flip(screen);
SDL_FreeSurface(background1);
SDL_FreeSurface(background2);
SDL_Quit();
return 0;
}
