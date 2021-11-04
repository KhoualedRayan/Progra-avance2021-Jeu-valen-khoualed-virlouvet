#include "graphisme.h"
#include "animations.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"

float compteur;

void timer(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Affichage du texte graphique
	if (world->defeat_or_win !=2) {	
		compteur = (float)(SDL_GetTicks()/1000.);
	}
	char* text = (char*)malloc(sizeof(char)* 100);	
	if (world->defeat_or_win == 0) {
	sprintf(text, "TIME : %f",compteur);
	apply_text(renderer, SCREEN_WIDTH/2 - 25,0,100,50,text,textures->font);
	}
	if (world->defeat_or_win == 1) {
		sprintf(text, "YOU DIED !");
		apply_text(renderer, SCREEN_WIDTH/2 - 100 ,SCREEN_HEIGHT/2 -50,200,100,text,textures->font);
		world->gameover=1;
	}
	if (world->defeat_or_win == 2) {
		sprintf(text, "YOU WON IN %fs", compteur);
		apply_text(renderer, SCREEN_WIDTH/2 -100 ,SCREEN_HEIGHT/2 -50,200,100,text,textures->font);
		world->gameover = 1;
	}
}

void ryu_hidle(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Animations
    if(world->mouvement == 0){
        if((int)(compteur*4) %4 ==0){
            apply_sprite(renderer, textures->ryu_idle,world->sprite);
        }else if((int)(compteur*4) %4 ==1){
            apply_sprite(renderer,textures->ryu_idle1,world->sprite);
        }
        else if((int)(compteur*4) %4 ==2){
            apply_sprite(renderer,textures->ryu_idle2,world->sprite);
        }else if((int)(compteur*4) %4 ==3){
            apply_sprite(renderer, textures->ryu_idle3,world->sprite) ;
        }
    }
}
void ryu_walking(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Animations
    if(world->mouvement == 1){
        if((int)(compteur*5) %5 ==0){
            apply_sprite(renderer, textures->ryu_walking,world->sprite);
        }else if((int)(compteur*5) %5 ==1){
            apply_sprite(renderer,textures->ryu_walking1,world->sprite);
        }
        else if((int)(compteur*5) %5 ==2){
            apply_sprite(renderer,textures->ryu_walking2,world->sprite);
        }else if((int)(compteur*5) %5 ==3){
            apply_sprite(renderer, textures->ryu_walking3,world->sprite) ;
        }
		else if((int)(compteur*5) %5 ==4){
            apply_sprite(renderer, textures->ryu_walking4,world->sprite) ;
        }
    }
	if(world->mouvement == 2){
        if((int)(compteur*5) %5 ==0){
            apply_sprite(renderer, textures->ryu_walking,world->sprite);
        }else if((int)(compteur*5) %5 ==1){
            apply_sprite(renderer,textures->ryu_walking1,world->sprite);
        }
        else if((int)(compteur*5) %5 ==2){
            apply_sprite(renderer,textures->ryu_walking2,world->sprite);
        }else if((int)(compteur*5) %5 ==3){
            apply_sprite(renderer, textures->ryu_walking3,world->sprite) ;
        }
		else if((int)(compteur*5) %5 ==4){
            apply_sprite(renderer, textures->ryu_walking4,world->sprite) ;
        }
    }
}
void ryu_blocking(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Animations
    if(world->mouvement == 5){
        apply_sprite(renderer, textures->ryu_blocking,world->sprite);
    }
}

void ryu_crouching(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Animations
    if(world->mouvement == 3){
        apply_sprite(renderer, textures->ryu_crouching,world->sprite);
    }
}

void refresh_animations(world_t* world,SDL_Renderer *renderer,textures_t *textures){
    timer(renderer,world,textures);
    ryu_hidle(renderer,world,textures);
	ryu_walking(renderer,world,textures);
	ryu_blocking(renderer,world,textures);
	ryu_crouching(renderer,world,textures);




}

