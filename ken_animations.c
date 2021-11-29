#include "graphisme.h"
#include "ken_animations.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"

void ken_hidle(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Animations
    if(world->mouvement2 == 0 && world->state_ken == REST_KEN){
        if(world->mouvement2 == 0){
            if((int)(world->compteur*4) %4 ==0){
                apply_sprite(renderer, textures->ken_idle,world->spriteTwo);
            }else if((int)(world->compteur*4) %4 ==1){
                apply_sprite(renderer,textures->ken_idle1,world->spriteTwo);
            }
            else if((int)(world->compteur*4) %4 ==2){
                apply_sprite(renderer,textures->ken_idle2,world->spriteTwo);
            }else if((int)(world->compteur*4) %4 ==3){
                apply_sprite(renderer, textures->ken_idle3,world->spriteTwo) ;
            }
        }
    }
}

void ken_walking(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //WALK RIGHT    
    if(world->mouvement2 == 1 && world->state_ken!= ATTACKED){
        if((int)(world->compteur*5) %5 ==0){
            apply_sprite(renderer, textures->ken_walking,world->spriteTwo);
        }else if((int)(world->compteur*5) %5 ==1){
            apply_sprite(renderer,textures->ken_walking1,world->spriteTwo);
        }
        else if((int)(world->compteur*5) %5 ==2){
            apply_sprite(renderer,textures->ken_walking2,world->spriteTwo);
        }else if((int)(world->compteur*5) %5 ==3){
            apply_sprite(renderer, textures->ken_walking3,world->spriteTwo) ;
        }
		else if((int)(world->compteur*5) %5 ==4){
            apply_sprite(renderer, textures->ken_walking4,world->spriteTwo) ;
        }
    }

    //WALK LEFT
	if(world->mouvement2 == 2 && world->state_ken!= ATTACKED){
        if((int)(world->compteur*5) %5 ==0){
            apply_sprite(renderer, textures->ken_walking,world->spriteTwo);
        }else if((int)(world->compteur*5) %5 ==1){
            apply_sprite(renderer,textures->ken_walking1,world->spriteTwo);
        }
        else if((int)(world->compteur*5) %5 ==2){
            apply_sprite(renderer,textures->ken_walking2,world->spriteTwo);
        }else if((int)(world->compteur*5) %5 ==3){
            apply_sprite(renderer, textures->ken_walking3,world->spriteTwo) ;
        }
		else if((int)(world->compteur*5) %5 ==4){
            apply_sprite(renderer, textures->ken_walking4,world->spriteTwo) ;
        }
    }
}

void ken_hadouken(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Hadouken
    float temps;
    float delai;
    if(world->state_ken == HADOUKEN_KEN){
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - world->timerlastshoot);

        if(delai  >=0.0 && delai  <=0.25){
            apply_sprite(renderer, textures->ken_hadouken,world->spriteTwo);
        }if(delai  >=0.25 && delai <=0.5){
            apply_sprite(renderer,textures->ken_hadouken1,world->spriteTwo);
        }
        if(delai  >=0.5 && delai <=0.75){
            apply_sprite(renderer,textures->ken_hadouken2,world->spriteTwo);
        }if(delai  >=0.75 && delai  <=1.){
            apply_sprite(renderer, textures->ken_hadouken3,world->spriteTwo) ;
        }if(delai>= 0.75){
            world->on2=1;
        }
    }
    if(world->on2 == 1){
        for(int i=0; i<10;i++){
            if(delai >=0.8 && delai  <=1.){
                init_sprite(&(world->hadouken_ken[world->nbr_hadouken]), world->spriteTwo->x + HORIZONTAL_SIZE - 260  , world->spriteTwo->y + PROJECTILE_SIZE + 48, PROJECTILE_SIZE, PROJECTILE_SIZE);
                apply_sprite(renderer,textures->ken_hadouken4,&(world->hadouken_ken[i])) ;  
            }else {
                for(int i=0; i<10;i++){
                    apply_sprite(renderer, textures->ken_hadouken5,&(world->hadouken_ken[i])) ;
                }
            }
        }
        for (int i =0 ; i < 10 ; i++){
            if(sprites_collide(world->sprite, &(world->hadouken_ken[i]))){
                world->on2 = 0;
                apply_sprite(renderer, textures->ken_hadouken6,&(world->hadouken_ken[i])) ;
            }
        }
    }
}


void ken_hit(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(world->state_ken == ATTACKED && world->mouvement2 == 10){
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - temps);
        if(delai  >=0. && delai  <=0.25){
            apply_sprite(renderer, textures->ken_hit,world->spriteTwo);
        }if(delai  >=0.25 && delai  <=0.5){
            apply_sprite(renderer,textures->ken_hit1,world->spriteTwo);
        }
        if(delai  >=0.5 && delai  <=0.75){
            apply_sprite(renderer,textures->ken_hit2,world->spriteTwo);
        }if(delai  >=0.75 && delai  <=0.98){
            apply_sprite(renderer, textures->ken_hit3,world->spriteTwo) ;
        }
        if(delai >= 0.98){
            world->state_ken = REST_KEN;
            world->mouvement2 = 0;
        }
        for(int i=0;i<10;i++){
            if(sprites_collide(world->spriteTwo,&(world->hadouken[i])) && world->hitted == 0){
                world->ken_pv -= 5;
                world->hitted = 1;
            }
        }
    }
}


void ken_hp(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //HP BARRE
    apply_sprite(renderer,textures->ken_hp,world->ken_hp_barre);
    for (int i =0 ; i < world->ken_pv ; i++){
        apply_sprite(renderer, textures->ken_hp_fill,&(world->ken_hp[i])) ;
    }

}

void ken_lpunch(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(world->state_ken == ATTACK && world->typeOfAttack2 == LPUNCH){
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - world->timerLastAttack2);
        if(delai  >=-0.0 && delai  <=0.3){
            apply_sprite(renderer, textures->ken_lpunch,world->spriteAttackTwo);
        }
        if(delai  >=0.3 && delai  <=1.){
            apply_sprite(renderer, textures->ken_lpunch1,world->spriteAttackTwo);
            damage_knockback(world->sprite,world->spriteAttackTwo,2,-6,world);
                
        }
    }
}

void ken_lkick(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(world->state_ken == ATTACK && world->typeOfAttack2 == LKICK){
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - world->timerLastAttack2);
        if(delai  >=-0.0 && delai  <=0.3){
            apply_sprite(renderer, textures->ken_lkick,world->spriteAttackTwo);
        }
        if(delai  >=0.3 && delai  <=1.){
            apply_sprite(renderer, textures->ken_lkick1,world->spriteAttackTwo);
            damage_knockback(world->sprite,world->spriteAttackTwo,3,-20,world);        
        }
    }
}

void ken_crouch_lpunch(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(world->state_ken == ATTACK && world->typeOfAttack2 == CROUCH_LPUNCH){
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - world->timerLastAttack2);
        if(delai  >=-0.0 && delai  <=0.3){
            apply_sprite(renderer, textures->ken_crouch_lpunch,world->spriteAttackTwo);
        }
        if(delai  >=0.3 && delai  <=1.){
            apply_sprite(renderer, textures->ken_crouch_lpunch2,world->spriteAttackTwo);
            damage_knockback(world->sprite,world->spriteAttackTwo,1,-5,world);
                
        }
    }
}

void ken_victory(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(99 - (int)(world->compteur) + (int)(world->compteur_menu) <= 0 || world->ryu_pv <=0){
        world->mouvement2 = 52 ;
        world->state_ken = REST_KEN ;
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - temps);
        if(delai  >=-0.0 && delai  <=0.3){
            sprintf(world->text, "YOU LOOSE !");
		    apply_text(renderer, SCREEN_WIDTH/2 - 100 ,SCREEN_HEIGHT/2-200,200,100,world->text,textures->font);
            apply_sprite(renderer, textures->ken_victory,world->spriteTwo);

        }
        if(delai  >=0.3 && delai  <=0.6){
            sprintf(world->text, "YOU LOOSE !");
		    apply_text(renderer, SCREEN_WIDTH/2 - 100 ,SCREEN_HEIGHT/2-200,200,100,world->text,textures->font);
            apply_sprite(renderer, textures->ken_victory1,world->spriteTwo);
                
        }
        if(delai  >=0.6 && delai  <=1.){
            sprintf(world->text, "YOU LOOSE !");
		    apply_text(renderer, SCREEN_WIDTH/2 - 100 ,SCREEN_HEIGHT/2-200,200,100,world->text,textures->font);
            apply_sprite(renderer, textures->ken_victory2,world->spriteTwo);
            world->win = 1 ;
        }
    }
}


void refresh_animations_ken(world_t* world,SDL_Renderer *renderer,textures_t *textures){
    //KEN
    ken_hidle(renderer,world,textures);
    ken_walking(renderer,world,textures);
    ken_hadouken(renderer,world,textures);
    ken_hit(renderer, world, textures);
    ken_hp(renderer,world,textures);
    ken_lpunch(renderer,world,textures);
    ken_lkick(renderer,world,textures);
    ken_crouch_lpunch(renderer,world,textures);
    ken_victory(renderer,world,textures);
}