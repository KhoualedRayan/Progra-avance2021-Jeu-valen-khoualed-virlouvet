#include "world.h"
#include "constante.h"
#include "sdl2-light.h"

void gravity_ken(world_t *world){
	if(world->state_ken == JUMP){
		world->vy_ken = -INITIAL_SPEED - 2;
		world->mouvement2 = 0;
	}
	if(world->spriteTwo->y == 179){
		pause(20);
		world->state_ken = FALL;
		world->mouvement2 = 0;

	}
	if(world->state_ken == FALL){
		world->vy_ken = INITIAL_SPEED+2;
		world->mouvement2 = 0;
	}
	if(world->spriteTwo->y == (SCREEN_HEIGHT - VERTICAL_SIZE - 120) && world->state_ken <=1){
		world->state_ken = REST_KEN;
	}
	if(world->state_ken == REST_KEN){
		world->vy_ken =0;
	}
	world->spriteTwo->y = world->spriteTwo-> y + world->vy_ken; 

}

void hadouken_ken(world_t *world){
	if(world->test == HADOUKEN_KEN && world->state_ken != JUMP && world->state_ken != FALL && world->state_ken != CROUCH){
		if((world->timerlastshoot +1 > SDL_GetTicks()/1000)){
			world->state_ken = HADOUKEN_KEN;
		}else{
			world->state_ken = REST_KEN;
			world->test = 0;
			world->hitted_ryu = 0;
		}
	}
}
void attack_ken(world_t *world){
	if(world->test2 == ATTACK && world->state_ken != JUMP && world->state != FALL && world->state != CROUCH && world->state != HADOUKEN){
		init_sprite(world->spriteAttackTwo,world->spriteTwo->x +world->addx2, world->spriteTwo->y +world->addy2, HORIZONTAL_SIZE+world->addw2, VERTICAL_SIZE + world->addh2);
		if((world->timerLastAttack2 +1 > SDL_GetTicks()/1000)){
			world->state_ken = ATTACK;
		}else{
			world->state_ken = REST;
			world->test2 = 0;
			world->hitted = 0;
			world->addw2 = 0;
			world->addh2 = 0;
			world->addx2 = 0;
			world->addy2 = 0;
		}
	}else{
		init_sprite(world->spriteAttackTwo,world->spriteTwo->x, world->spriteTwo->y+3000, HORIZONTAL_SIZE+world->addw2, VERTICAL_SIZE + world->addh2);
	}
}

void receive_damage_ken(world_t* world){
	for (int i =0 ; i < 10 ; i++){
		if(sprites_collide(world->spriteTwo,world->spriteAttack) || sprites_collide(world->spriteTwo, &(world->hadouken[i]))){
			world->stun = SDL_GetTicks()/1000;
			if((world->stun +1 > SDL_GetTicks()/1000)){
				world->state_ken = ATTACKED;
				world->mouvement2 = 10;
			}
		}
	}
}

void update_data_Ken(world_t* world){
    gravity_ken(world) ;
	attack_ken(world);
    hadouken_ken(world);
	receive_damage_ken(world);
}