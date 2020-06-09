#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
 
void changerVitesseObjet(int acceleration, SDL_Rect *positionObjet, SDLKey *derTouche, double *unitDeplacement, double unitDeplacementMax, double uniteAccel, SDL_Event event){
 
    switch(event.key.keysym.sym)
        {
                case SDLK_UP: // Flèche haut
                    (*positionObjet).y -= *unitDeplacement;
                    if(acceleration)
                        *derTouche = SDLK_UP;
                    break;
                case SDLK_DOWN: // Flèche bas
                    (*positionObjet).y += *unitDeplacement;
                    if(acceleration)
                        *derTouche = SDLK_DOWN;
                    break;
                case SDLK_RIGHT: // Flèche droite
                    (*positionObjet).x += *unitDeplacement;
                    if(acceleration)
                        *derTouche = SDLK_RIGHT;
                    break;
                case SDLK_LEFT: // Flèche gauche
                    (*positionObjet).x -= *unitDeplacement;
                    if(acceleration)
                        *derTouche = SDLK_LEFT;
                    break;
        }
 
    if(acceleration){
        if(*unitDeplacement < unitDeplacementMax){
            *unitDeplacement += uniteAccel;
        }
    }else{
        if((*unitDeplacement - uniteAccel) >= 0){
            *unitDeplacement -= uniteAccel;
            if(*unitDeplacement < uniteAccel)
                    *unitDeplacement = 0;
 
        }
    }
}
 
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *guitar = NULL;
    SDL_Rect positionFond, positionGuitar;
    SDL_Event event;
    SDLKey derniereTouche;
 
    int continuer = 1, direction = 0, acceleration = 0;
    double uniteDeplacement = 0, uniteAccel = 0.15, uniteDeplacementMax = 7;
 
    positionFond.x = 0;
    positionFond.y = 0;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    SDL_WM_SetIcon(IMG_Load("images/sdl_icone.bmp"), NULL);
 
    ecran = SDL_SetVideoMode(1000, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
 
    imageDeFond = IMG_Load("background.png");
    guitar = IMG_Load("2.png");
 
    positionGuitar.x = ecran->w / 2 - guitar->w / 2;
    positionGuitar.y = ecran->h / 2 - guitar->h / 2;
 
    SDL_EnableKeyRepeat(10, 10);
 
    while (continuer){
 
        SDL_PollEvent(&event);
 
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                changerVitesseObjet(1, &positionGuitar, &derniereTouche, &uniteDeplacement, uniteDeplacementMax, uniteAccel, event);
                break;
            case SDL_KEYUP:
                changerVitesseObjet(0, &positionGuitar, &derniereTouche, &uniteDeplacement, uniteDeplacementMax, uniteAccel, event);
                break;
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_BlitSurface(guitar, NULL, ecran, &positionGuitar);
        SDL_Flip(ecran);
 
    }
 
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(guitar);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}
