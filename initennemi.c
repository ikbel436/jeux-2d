#include "header.h"

void intialiser_entite(ENTITE_SECONDAIRE *entite)
{ 
entite->enemis[1]=IMG_Load("e1.png");
entite->enemis[0]=IMG_Load("e2.png");
if(entite->enemis[0]==NULL)
		exit(EXIT_FAILURE);
if(entite->enemis[1]==NULL)
		exit(EXIT_FAILURE);
entite->position.x=500;
entite->position.y=600;
entite->direction = 1;



}
void intialiser_frog(entite_frog *frog,int x,int y)
{
frog->pos.x=x;
frog->pos.y=y;
}

/*void intialiser_entite2(ENTITE_SECONDAIRE *entite)
{ 
entite->enemis[1]=IMG_Load("e1.png");
entite->enemis[0]=IMG_Load("e2.png");
if(entite->enemis[0]==NULL)
		exit(EXIT_FAILURE);
if(entite->enemis[1]==NULL)
		exit(EXIT_FAILURE);
entite->position.x=300;
entite->position.y=390;
entite->direction = 0;
}*/

