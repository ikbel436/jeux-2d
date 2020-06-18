/// @file jeu.c
#include "jeu.h"


/**
 * fonction boucle jeu
 * @param ecran la surface de l'ecran pour mettre le jeu dessus
 * @param son la chaine de son pour jouer des sons brefs avec
 * @param musique la chaine de musique pour jouer la musique du jeu avec
 */ 

void jouer(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique)
{
SDL_Surface *background1=NULL,*player=NULL,*enemy=NULL;
SDL_Rect positionbackground1,positionplayer,positionmilieu,positionenemy;
SDL_Event event;
int continuer = 1;
background1=IMG_Load("map.png");
    positionbackground1.x = 0;
    positionbackground1.y = 0;
    player=IMG_Load("player1.png");
    enemy=IMG_Load("enemy.png");
    positionplayer.x =1366/2;
    positionplayer.y =350;

    positionenemy.x =1366/1.5;
    positionenemy.y =370;
    int dir = -1;

    positionmilieu.x = 1366/2;
    positionmilieu.y = 678/2;
//SDL_BlitSurface ( background1,  NULL ,  ecran , &positionbackground1);
//SDL_BlitSurface ( player,   NULL , ecran , &positionplayer );
SDL_EnableKeyRepeat(10,10) ;


    while (continuer)
    {
            while(SDL_PollEvent(&event))
            switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym)
                {
			      case SDLK_ESCAPE :
			      {
              //savegame(ecran,son,musique);
            }
			      break ;
			      case SDLK_LEFT :
			      	if(positionplayer.x>100)positionplayer.x-=10 ;
			      break ;
			      case SDLK_RIGHT:
			      if(positionplayer.x<2000)positionplayer.x+=10 ;
			      break ;
			      case SDLK_UP :
			      if(positionplayer.y>10)positionplayer.y-=10 ;
			      break;
			      case SDLK_DOWN :
			      if(positionplayer.y<600)positionplayer.y+=10 ;
			      break;
			      }
			      break;
			      }
			      }

			      positionbackground1.x = -positionplayer.x+(1366/2);
			      positionmilieu.y = positionplayer.y;
            positionenemy.x+=dir*10;
            if(positionenemy.x<500)dir=1;
            if(positionenemy.x>1200)dir=-1;
SDL_BlitSurface ( background1,  NULL ,  ecran , NULL);
SDL_BlitSurface ( player,   NULL , ecran , &positionplayer);
SDL_BlitSurface ( enemy,   NULL , ecran , &positionenemy);
	SDL_Flip(ecran) ;
       SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
       SDL_Delay(50);
	}
    SDL_FreeSurface(background1);
    SDL_FreeSurface(player);
       SDL_Quit();
       }
