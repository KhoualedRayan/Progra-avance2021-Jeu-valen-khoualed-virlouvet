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
	sprintf(text, "TIME : %d",(int)(compteur));
	apply_text(renderer, SCREEN_WIDTH/2 - 25,0,100,50,text,textures->font);
	}
	if (world->defeat_or_win == 1) {
		sprintf(text, "YOU DIED !");
		apply_text(renderer, SCREEN_WIDTH/2 - 100 ,SCREEN_HEIGHT/2 -50,200,100,text,textures->font);
		world->gameover=1;
	}
	if (world->defeat_or_win == 2) {
		sprintf(text, "YOU WON IN %ds", (int)(compteur));
		apply_text(renderer, SCREEN_WIDTH/2 -100 ,SCREEN_HEIGHT/2 -50,200,100,text,textures->font);
		world->gameover = 1;
	}
}

void ryu_hidle(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Animations
    if(world->mouvement == REST && world->state == REST){
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
    //WALK RIGHT    
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

    //WALK LEFT
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
    if(world->mouvement == 8){
        apply_sprite(renderer,textures->ryu_blocking1,world->sprite);
    }
}

void ryu_hadouken(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Hadouken
    if(world->mouvement == 4 && world->state == HADOUKEN){
        if((int)(compteur*5) %5 ==0){
            apply_sprite(renderer, textures->ryu_hadouken,world->sprite);
        }else if((int)(compteur*5) %5 ==1){
            apply_sprite(renderer,textures->ryu_hadouken1,world->sprite);
        }
        else if((int)(compteur*5) %5 ==2){
            apply_sprite(renderer,textures->ryu_hadouken2,world->sprite);
        }else if((int)(compteur*5) %5 ==3){
            apply_sprite(renderer, textures->ryu_hadouken3,world->sprite) ;
        }
		else if((int)(compteur*5) %5 ==4){
            apply_sprite(renderer, textures->ryu_hadouken4,world->sprite) ;
        }
    }

}

void ryu_jumping(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //JUMPING
    if(world->state == JUMP){
        if((int)(compteur*4) %4 ==0){
            apply_sprite(renderer, textures->ryu_jumping,world->sprite);
        }else if((int)(compteur*4) %4 ==1){
            apply_sprite(renderer,textures->ryu_jumping1,world->sprite);
        }
        else if((int)(compteur*4) %4 ==2){
            apply_sprite(renderer,textures->ryu_jumping2,world->sprite);
        }else if((int)(compteur*4) %4 ==3){
            apply_sprite(renderer, textures->ryu_jumping3,world->sprite) ;
        }
    }

}
void ryu_falling(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //FALLING
    if(world->state == FALL){
        if((int)(compteur*3) %3 ==0){
            apply_sprite(renderer, textures->ryu_falling,world->sprite);
        }else if((int)(compteur*3) %4 ==1){
            apply_sprite(renderer,textures->ryu_falling1,world->sprite);
        }
        else if((int)(compteur*3) %3 ==2){
            apply_sprite(renderer,textures->ryu_falling2,world->sprite);
        }
    }

}

void ken_hidle(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Animations
    if(world->mouvement2 == 0){
        if((int)(compteur*4) %4 ==0){
            apply_sprite(renderer, textures->ken_idle,world->spriteTwo);
        }else if((int)(compteur*4) %4 ==1){
            apply_sprite(renderer,textures->ken_idle1,world->spriteTwo);
        }
        else if((int)(compteur*4) %4 ==2){
            apply_sprite(renderer,textures->ken_idle2,world->spriteTwo);
        }else if((int)(compteur*4) %4 ==3){
            apply_sprite(renderer, textures->ken_idle3,world->spriteTwo) ;
        }
    }
}

void ken_walking(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //WALK RIGHT    
    if(world->mouvement2 == 1){
        if((int)(compteur*5) %5 ==0){
            apply_sprite(renderer, textures->ken_walking,world->spriteTwo);
        }else if((int)(compteur*5) %5 ==1){
            apply_sprite(renderer,textures->ken_walking1,world->spriteTwo);
        }
        else if((int)(compteur*5) %5 ==2){
            apply_sprite(renderer,textures->ken_walking2,world->spriteTwo);
        }else if((int)(compteur*5) %5 ==3){
            apply_sprite(renderer, textures->ken_walking3,world->spriteTwo) ;
        }
		else if((int)(compteur*5) %5 ==4){
            apply_sprite(renderer, textures->ken_walking4,world->spriteTwo) ;
        }
    }

    //WALK LEFT
	if(world->mouvement2 == 2){
        if((int)(compteur*5) %5 ==0){
            apply_sprite(renderer, textures->ken_walking,world->spriteTwo);
        }else if((int)(compteur*5) %5 ==1){
            apply_sprite(renderer,textures->ken_walking1,world->spriteTwo);
        }
        else if((int)(compteur*5) %5 ==2){
            apply_sprite(renderer,textures->ken_walking2,world->spriteTwo);
        }else if((int)(compteur*5) %5 ==3){
            apply_sprite(renderer, textures->ken_walking3,world->spriteTwo) ;
        }
		else if((int)(compteur*5) %5 ==4){
            apply_sprite(renderer, textures->ken_walking4,world->spriteTwo) ;
        }
    }
}

void ken_hit(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    if(world->mouvement2 == 10){
        for (int i =0 ; i < 100 ; i++){
            if(sprites_collide(world->spriteTwo, &(world->hadouken[i]))){
                if((int)(compteur*4) %4 ==0){
                    apply_sprite(renderer, textures->ken_hit,world->spriteTwo);
                }else if((int)(compteur*4) %4 ==1){
                    apply_sprite(renderer,textures->ken_hit1,world->spriteTwo);
                }
                else if((int)(compteur*4) %4 ==2){
                    apply_sprite(renderer,textures->ken_hit2,world->spriteTwo);
                }else if((int)(compteur*4) %4 ==3){
                    apply_sprite(renderer, textures->ken_hit3,world->spriteTwo) ;
                }
            }
        }
    }
}

void refresh_animations(world_t* world,SDL_Renderer *renderer,textures_t *textures){
    //TIMER
    timer(renderer,world,textures);

    //RYU
    ryu_hidle(renderer,world,textures);
	ryu_walking(renderer,world,textures);
	ryu_blocking(renderer,world,textures);
	ryu_crouching(renderer,world,textures);
    ken_hidle(renderer,world,textures);
    ken_walking(renderer,world,textures);
    ken_hit(renderer, world, textures);
    ryu_jumping(renderer,world,textures);
    ryu_falling(renderer,world,textures);
    ryu_hadouken(renderer,world,textures);



    //KEN
    ken_hidle(renderer,world,textures);



}

