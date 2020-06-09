#include "header.h"

 void deplacement_aleatoire(ENTITE_SECONDAIRE *e,int min,int max,BACKGROUND back)
{       
	     
        if ((e->position).x + back.position.x >= max )
		e->direction = 0;
	if  ((e->position).x+ back.position.x <= min )
		e->direction = 1;
	if ( e->direction == 1)
		(e->position).x += 5;
	if (e->direction == 0)
		(e->position).x -= 5;
            

} 
