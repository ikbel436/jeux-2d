#include "header.h"
#define STAT_SOL 0
#define STAT_AIR 1
void init_perso(perso *p)

{

    int i;
  

    char chaine[20],chaine1[20];
/*
    for (i=1; i<8; i++)

    {

        sprintf(chaine,"l%d.png",i);

        p->tab[i-1]=IMG_Load(chaine);

    }
*/
    p->frame=1;
    p->posperso.x=50;
    p->posperso.y=690;
    p->status = STAT_SOL;
    p->vx = p->vy = 0.0f;
    p->perframe=IMG_Load("perso/standright/1.png");
    p->vie=100;
    p->score=0;
  

}


void afficher_perso(perso p,SDL_Surface *screen,SDL_Event event)
{
    SDL_BlitSurface(p.perframe,NULL,screen,&p.posperso);
}


