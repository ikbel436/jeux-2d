#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "save.h"
/**
* @file [save.c].
* @author : Rangers
* @brief : fonction de sauvegarde de jeu 
* @date : 2020/11/09
* @version 1
*/

/**
* @brief to fonction du boucle de sauvegarder le fichier .
* @param positionplayer position du joueur 
* @param file initialiser le fichier 
* @return nothing
*/

void savegame(SDL_Rect player, int score,int vie,char* file )

{
    FILE * f = fopen(file,"w") ;
	if (f==NULL)
	{
	   
		printf("erreur, le fichier de sauvegarde ne peut pas etre ouvert\n");
	}
	
	else
	{

    fprintf(f,"%d\n",player.x);
    fprintf(f,"%d\n",player.y);
    fprintf(f,"%d\n", score);
    fprintf(f,"%d\n", vie);
   fclose(f);
	}
}


/**
* @brief to fonction du boucle de loadgame .
* @param positionplayer position du joueur  
* @return nothing
*/
void loadgame(SDL_Rect *player, int* score,int* vie)
{
	char file[20];
	FILE* f = fopen("save.txt","r");
	if(f!=NULL)
	{
		while(!feof(f))
		{
		    fscanf(f, "%d\n",&player->x);
		    fscanf(f, "%d\n",&player->y);
		    fscanf(f, "%d\n", score);
		    fscanf(f, "%d\n", vie);
		}
		
	
	fclose(f);
	}
	else 
{
	printf("erreur, le fichier de sauvegarde ne peut pas etre ouvert\n");
}

	
}
/**
* @brief to fonction du boucle d'effacer le contenu du fichier .
* @param nothing
* @return nothing
*/
void resetgame( )

{
    FILE * f = fopen("save.txt","w") ;
	if (f==NULL)
	{
	   
		printf("erreur, le fichier de sauvegarde ne peut pas etre ouvert\n");
	}
	
	else
	{

   
   fclose(f);
	}
}


