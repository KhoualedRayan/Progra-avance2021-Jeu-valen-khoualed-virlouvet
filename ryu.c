#include "world.h"
#include "graphisme.h"
#include "constante.h"
#include "sdl2-light.h"



void gravity_ryu(world_t *world){
	if(world->state == JUMP){
		world->vy_ryu = -INITIAL_SPEED - 2;
		world->mouvement = 0;
	}
	if(world->sprite->y == 179){
		pause(20);
		world->state = FALL;
		world->mouvement = 0;

	}
	if(world->state == FALL){
		world->vy_ryu = INITIAL_SPEED+2;
		world->mouvement = 0;
	}
	if(world->sprite->y == (SCREEN_HEIGHT - VERTICAL_SIZE - 120) && world->state !=JUMP && world->state !=HADOUKEN && world->state != ATTACK ){
		world->state = REST;
	}
	if(world->state == REST){
		world->vy_ryu =0;
	}
	world->sprite->y = world->sprite-> y + world->vy_ryu; 

}

void attack_ryu(world_t *world){
	if(world->test == ATTACK && world->state != JUMP && world->state != FALL && world->state != CROUCH && world->state != HADOUKEN){
		init_sprite(world->spriteAttack,world->sprite->x, world->sprite->y, HORIZONTAL_SIZE+world->addw, VERTICAL_SIZE + world->addh);
		if((world->timerLastAttack +1 > SDL_GetTicks()/1000)){
			world->state = ATTACK;
		}else{
			world->state = REST;
			world->test = 0;
			world->hitted = 0;
			world->addw = 0;
			world->addh = 0;
		}
	}else{
		init_sprite(world->spriteAttack,world->sprite->x, world->sprite->y+3000, HORIZONTAL_SIZE+world->addw, VERTICAL_SIZE + world->addh);
	}
}
void hadouken_ryu(world_t *world){
	if(world->test == HADOUKEN && world->state != JUMP && world->state != FALL && world->state != CROUCH && world->state != ATTACK){
		if((world->timerlastshoot +1 > SDL_GetTicks()/1000)){
			world->state = HADOUKEN;
		}else{
			world->state = REST;
			world->test = 0;
			world->hitted = 0;
		}
	}
}

void receive_damage_ryu(world_t* world){
	for (int i =0 ; i < 10 ; i++){
		if(sprites_collide(world->sprite, &(world->hadouken_ken[i]))){
			world->stun = SDL_GetTicks()/1000;
			if((world->stun +1 > SDL_GetTicks()/1000)){
				world->state = ATTACKED;
				world->mouvement =  13;
			}
		}
	}
}


void update_data_ryu(world_t* world){
    hadouken_ryu(world);
	attack_ryu(world);
    gravity_ryu(world);
	receive_damage_ryu(world);
}