#include "world.h"
#include "constante.h"
#include "sdl2-light.h"

void gravity_ken(world_t *world){
	if(world->state_ken == JUMP){
		world->vy = -INITIAL_SPEED - 2;
		world->mouvement2 = 0;
	}
	if(world->spriteTwo->y == 179){
		pause(20);
		world->state_ken = FALL;
		world->mouvement2 = 0;

	}
	if(world->state_ken == FALL){
		world->vy = INITIAL_SPEED+2;
		world->mouvement2 = 0;
	}
	if(world->spriteTwo->y == (SCREEN_HEIGHT - VERTICAL_SIZE - 120) && world->state_ken !=JUMP && world->state_ken !=HADOUKEN && world->state_ken!= ATTACKED	){
		world->state_ken = REST_KEN;
	}
	if(world->state_ken == REST_KEN){
		world->vy =0;
	}
	world->spriteTwo->y = world->spriteTwo-> y + world->vy; 

}

void hadouken_ken(world_t *world){
	int compt;
	if(world->test == HADOUKEN_KEN && world->state_ken != JUMP && world->state_ken != FALL && world->state_ken != CROUCH){
		compt = SDL_GetTicks()/1000;
		if((world->timerlastshoot +1 > SDL_GetTicks()/1000)){
			world->state_ken = HADOUKEN_KEN;
		}else{
			world->state_ken = REST_KEN;
			world->test = 0;
		}
	}
}

void update_data_Ken(world_t* world){
    gravity_ken(world) ;
    hadouken_ken(world);
}