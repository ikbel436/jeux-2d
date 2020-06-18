/// @file main.c
#include "menu.h"
/**
 * fonction boucle jeu
 * @param ecran la surface de l'ecran pour mettre le jeu dessus
 * @param son la chaine de son pour jouer des sons brefs avec
 * @param musique la chaine de musique pour jouer la musique du jeu avec
 */ 
int main (void)
{
    int continuee=1;
    SDL_Surface *ecran =NULL;
    Mix_Music *musique;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(IMG_Load("logo.png"), NULL); 
    ecran = SDL_SetVideoMode(1366, 678,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("DIGILAND", "DIGILAND");
    SDL_Event event;

if (ecran==NULL)
{
printf("error: %s ",SDL_GetError());
exit(EXIT_FAILURE);
}
if(Mix_OpenAudio(48000,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
  {printf("%s",Mix_GetError()); }

	   musique=Mix_LoadMUS("music2.mp3");
           Mix_PlayMusic(musique,-1);
           SDL_Rect poslogo;
poslogo.x=(1366/2)-262 ;
poslogo.y=(678/2)-200 ;
SDL_Surface *logo=IMG_Load("logo.png") ;
SDL_BlitSurface(logo,NULL,ecran,&poslogo);
SDL_Flip(ecran);
SDL_Delay(500);


while (continuee)
{
menu(ecran,musique);
}

Mix_FreeMusic(musique);
Mix_CloseAudio();
SDL_FreeSurface(ecran);
SDL_Quit();
return EXIT_SUCCESS;
}
