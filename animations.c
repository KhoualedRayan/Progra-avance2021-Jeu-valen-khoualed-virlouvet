#include "graphisme.h"
#include "animations.h"
#include "ken_animations.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "score.h"

int time = 99;

void timer(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Affichage du texte graphique
	if (world->defeat_or_win !=2) {	
		world->compteur = (float)(SDL_GetTicks()/1000.) ;
	}

	if (world->defeat_or_win == 0) {
        world->time = time- (int)(world->compteur) + (int)(world->compteur_menu);
	    sprintf(world->text, "KO");
	    apply_text(renderer, SCREEN_WIDTH/2 - 25,20,100,50,world->text,textures->font);
        sprintf(world->text, "%d",world->time);
        apply_text(renderer, SCREEN_WIDTH/2 - 25,70,100,50,world->text,textures->font);
	}

    if(world->win == 1){ // quand le compteur est à zero ou que les hp sont à zero le menu réapparait
        world->etat_menu = 0;
        world->gameover = 1;
        scores(world,world->maList,renderer,textures);
    }
    if(world->etat_menu <3){
        actualiserListe(world->maList,renderer,world,textures);
    }
}


void ryu_hidle(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Animations
    if(world->mouvement == REST && world->state == REST){
        if((int)(world->compteur*4) %4 ==0){
            apply_sprite(renderer, textures->ryu_idle,world->sprite);
        }else if((int)(world->compteur*4) %4 ==1){
            apply_sprite(renderer,textures->ryu_idle1,world->sprite);
        }
        else if((int)(world->compteur*4) %4 ==2){
            apply_sprite(renderer,textures->ryu_idle2,world->sprite);
        }else if((int)(world->compteur*4) %4 ==3){
            apply_sprite(renderer, textures->ryu_idle3,world->sprite) ;
        }
    }
}
void ryu_hit(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(world->state == ATTACKED && world->mouvement == 13 && world->ken_pv > 1){
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - temps);
        if(delai  >=0.0 && delai  <=0.25){
            apply_sprite(renderer, textures->ryu_hit,world->sprite);
        }if(delai  >=0.25 && delai  <=0.5){
            apply_sprite(renderer,textures->ryu_hit1,world->sprite);
        }
        if(delai  >=0.5 && delai  <=0.75){
            apply_sprite(renderer,textures->ryu_hit2,world->sprite);
        }if(delai  >=0.75 && delai  < 0.98){
            apply_sprite(renderer, textures->ryu_hit3,world->sprite) ;
        }
        if(delai >= 0.98){
            world->state = REST;
            world->mouvement = REST;
        }
        for(int i=0;i<10;i++){
            if(sprites_collide(world->sprite,&(world->hadouken_ken[i])) && world->hitted_ryu == 0){
                world->ryu_pv -= 5;
                world->hitted_ryu = 1;
            }
        }
    }
}
void ryu_walking(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //WALK RIGHT    
    if(world->mouvement == 1 && world->state == REST){
        if((int)(world->compteur*5) %5 ==0){
            apply_sprite(renderer, textures->ryu_walking,world->sprite);
        }else if((int)(world->compteur*5) %5 ==1){
            apply_sprite(renderer,textures->ryu_walking1,world->sprite);
        }
        else if((int)(world->compteur*5) %5 ==2){
            apply_sprite(renderer,textures->ryu_walking2,world->sprite);
        }else if((int)(world->compteur*5) %5 ==3){
            apply_sprite(renderer, textures->ryu_walking3,world->sprite) ;
        }
		else if((int)(world->compteur*5) %5 ==4){
            apply_sprite(renderer, textures->ryu_walking4,world->sprite) ;
        }
    }

    //WALK LEFT
	if(world->mouvement == 2  && world->state == REST){
        if((int)(world->compteur*5) %5 ==0){
            apply_sprite(renderer, textures->ryu_walking,world->sprite);
        }else if((int)(world->compteur*5) %5 ==1){
            apply_sprite(renderer,textures->ryu_walking1,world->sprite);
        }
        else if((int)(world->compteur*5) %5 ==2){
            apply_sprite(renderer,textures->ryu_walking2,world->sprite);
        }else if((int)(world->compteur*5) %5 ==3){
            apply_sprite(renderer, textures->ryu_walking3,world->sprite) ;
        }
		else if((int)(world->compteur*5) %5 ==4){
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
    if(world->mouvement  == 3 && world->state == CROUCH){
        apply_sprite(renderer, textures->ryu_crouching,world->sprite);
    }
    if(world->mouvement == 8){
        apply_sprite(renderer,textures->ryu_blocking1,world->sprite);
    }
}

void ryu_hadouken(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //Hadouken
    float temps;
    float delai;
    if(world->state == HADOUKEN && world->mouvement ==0 ){
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - world->timerlastshoot);

        if(delai  >=0.0 && delai  <=0.2){
            apply_sprite(renderer, textures->ryu_hadouken,world->sprite);
        }if(delai  >=0.2 && delai <=0.4){
            apply_sprite(renderer,textures->ryu_hadouken1,world->sprite);
        }
        if(delai  >=0.4 && delai <=0.6){
            apply_sprite(renderer,textures->ryu_hadouken2,world->sprite);
        }if(delai  >=0.6 && delai  <=0.8){
            apply_sprite(renderer, textures->ryu_hadouken3,world->sprite) ;
        }
		if(delai  >=0.8 && delai  <=1.){
            apply_sprite(renderer, textures->ryu_hadouken4,world->sprite) ;
        }if(delai >=0.8 ){
            world->on = 1;
        }
    }
    if(world->on == 1){
        for(int i=0; i<10;i++){
            if(delai >=0.8 && delai  <=1.){
                init_sprite(&(world->hadouken[world->nbr_hadouken]), world->sprite->x + HORIZONTAL_SIZE - 96  , world->sprite->y + PROJECTILE_SIZE + 48, PROJECTILE_SIZE, PROJECTILE_SIZE);
                apply_sprite(renderer,textures->ryu_hadouken5,&(world->hadouken[i])) ;  
            }else {
            for(int i=0; i<10;i++){
                apply_sprite(renderer, textures->ryu_hadouken6,&(world->hadouken[i])) ;
            }
            }
        }
    }
    for (int i =0 ; i < 10 ; i++){
        if(sprites_collide(world->spriteTwo, &(world->hadouken[i]))){
            world->on = 0;
            apply_sprite(renderer, textures->ryu_hadouken7,&(world->hadouken[i])) ;
        }
    }

}


void ryu_jumping(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //JUMPING
    if(world->state == JUMP){
        if(world->sprite->y >=419 - 80){
            apply_sprite(renderer,textures->ryu_jumping1,world->sprite);
        }
        else if(world->sprite->y >=419 - 80*2){
            apply_sprite(renderer,textures->ryu_jumping2,world->sprite);
        }else if(world->sprite->y >=419 - 80*3){
            apply_sprite(renderer, textures->ryu_jumping3,world->sprite) ;
        }
    }

}
void ryu_falling(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //FALLING
    if(world->state == FALL){
        if(world->sprite->y <=179+120){
            apply_sprite(renderer, textures->ryu_falling,world->sprite);
        }
        else if(world->sprite->y <=179+80*3){
            apply_sprite(renderer,textures->ryu_falling1,world->sprite);
        }
    }

}


void ryu_hp(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //HP BARRE
    apply_sprite(renderer,textures->ryu_hp,world->ryu_hp_barre);
    for (int i =0 ; i < world->ryu_pv ; i++){
        apply_sprite(renderer, textures->ryu_hp_fill,&(world->ryu_hp[i])) ;
    }
}

void ryu_lpunch(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(world->state == ATTACK && world->typeOfAttack == LPUNCH){
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - world->timerLastAttack);
        if(delai  >=0.0 && delai  <=0.3){
            apply_sprite(renderer, textures->ryu_lpunch,world->spriteAttack);
        }
        if(delai  >=0.3 && delai  <=1.){
            apply_sprite(renderer, textures->ryu_lpunch1,world->spriteAttack);
            damage_knockback(world->spriteTwo,world->spriteAttack,2,6,world);
        }
    }
}

void ryu_lkick(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(world->state == ATTACK && world->typeOfAttack == LKICK){
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - world->timerLastAttack);
        if(delai  >=-0.0 && delai  <=0.3){
            apply_sprite(renderer, textures->ryu_lkick,world->spriteAttack);
        }
        if(delai  >=0.3 && delai  <=1.){
            apply_sprite(renderer, textures->ryu_lkick1,world->spriteAttack);
            damage_knockback(world->spriteTwo,world->spriteAttack,3,20,world);        
        }
    }
}

void ryu_crouch_lpunch(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(world->state == ATTACK && world->typeOfAttack == CROUCH_LPUNCH){
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - world->timerLastAttack);
        if(delai  >=-0.0 && delai  <=0.3){
            apply_sprite(renderer, textures->ryu_crouch_lpunch,world->spriteAttack);
        }
        if(delai  >=0.3 && delai  <=1.){
            apply_sprite(renderer, textures->ryu_crouch_lpunch2,world->spriteAttack);
            damage_knockback(world->spriteTwo,world->spriteAttack,1,5,world);
                
        }
    }
}

void ryu_forward_lpunch(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(world->state == ATTACK && world->typeOfAttack == FORWARD_LPUNCH){
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - world->timerLastAttack);
        if(delai  >=-0.0 && delai  <=0.3){
            apply_sprite(renderer, textures->ryu_forward_lpunch,world->spriteAttack);
        }
        if(delai  >=0.3 && delai  <=1.){
            apply_sprite(renderer, textures->ryu_forward_lpunch1,world->spriteAttack);
            damage_knockback(world->spriteTwo,world->spriteAttack,2,25,world);   
        }
    }
}

void ryu_victory(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(world->ken_pv <=0 && world->state == REST){
        world->mouvement = 52 ;
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - temps);
        if(delai  >=-0.0 && delai  <=0.3){
            sprintf(world->text, "YOU WIN !");
		    apply_text(renderer, SCREEN_WIDTH/2 - 100 ,SCREEN_HEIGHT/2-200,200,100,world->text,textures->font);
            apply_sprite(renderer, textures->ryu_victory,world->sprite);

        }
        if(delai  >=0.3 && delai  <=0.6){
            sprintf(world->text, "YOU WIN !");
		    apply_text(renderer, SCREEN_WIDTH/2 - 100 ,SCREEN_HEIGHT/2-200,200,100,world->text,textures->font);
            apply_sprite(renderer, textures->ryu_victory1,world->sprite);
                
        }
        if(delai  >=0.6 && delai  <=1.){
            sprintf(world->text, "YOU WIN !");
		    apply_text(renderer, SCREEN_WIDTH/2 - 100 ,SCREEN_HEIGHT/2-200,200,100,world->text,textures->font);
            apply_sprite(renderer, textures->ryu_victory2,world->sprite);
        }if(delai > 0.90){
            world->win = 1 ;
        }
    }
}

void ryu_ko(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    float temps;
    float delai;
    if(world->ryu_pv <=0 && world->state == REST){
        world->mouvement = 53 ;
        temps = SDL_GetTicks()/1000;
        delai = (float) ((world->compteur) - temps);
        if(delai  >=-0.0 && delai  <=0.3){
            apply_sprite(renderer, textures->ryu_ko,world->sprite);
            world->sprite->x = world->sprite-> x - 2; 

        }
        if(delai  >=0.3 && delai  <=0.6){
            apply_sprite(renderer, textures->ryu_ko1,world->sprite);
            world->sprite->y = world->sprite-> y + 4;
            world->sprite->x = world->sprite-> x - 2;  
                
        }
        if(delai  >=0.6 && delai  <=1.){
            apply_sprite(renderer, textures->ryu_ko2,world->sprite);
            world->sprite->y = world->sprite-> y + 3; 
            world->sprite->x = world->sprite-> x - 2; 
        }
    }
}



void refresh_animations(world_t* world,SDL_Renderer *renderer,textures_t *textures){
    //TIMER
    timer(renderer,world,textures);

    //RYU
    ryu_hidle(renderer,world,textures);
    ryu_hit(renderer,world,textures);
	ryu_walking(renderer,world,textures);
	ryu_blocking(renderer,world,textures);
	ryu_crouching(renderer,world,textures);
    ryu_jumping(renderer,world,textures);
    ryu_falling(renderer,world,textures);
    ryu_hadouken(renderer,world,textures);
    ryu_hp(renderer,world,textures);
    ryu_lpunch(renderer,world,textures);
    ryu_lkick(renderer,world,textures);
    ryu_crouch_lpunch(renderer,world,textures);
    ryu_forward_lpunch(renderer,world,textures);
    ryu_victory(renderer,world,textures) ;

    ryu_ko(renderer,world, textures);

    //Ken
    refresh_animations_ken(world,renderer,textures);


}

