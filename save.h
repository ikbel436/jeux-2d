
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

void savegame(SDL_Rect player, int score, int vie,char* file );
void loadgame(SDL_Rect *player, int* score,int* vie);
void resetgame();

