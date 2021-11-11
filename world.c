#include "world.h"
#include "graphisme.h"
#include "constante.h"
#include "sdl2-light.h"



void init_data(world_t * world){
    
    //on n'est pas à la fin du jeu
	world->gameover = 0;
	world->etat_menu = 0;
	world->mouvement = 0;
	world->mouvement2 = 0;
	world->defeat_or_win = 0;
	world->test =0;
	world->on = 0;
	world->timerlastshoot = SDL_GetTicks()/1000;
	world->firerate = 2;
	world->nbr_hadouken = 0;
	world->vy = INITIAL_SPEED;
	world->state = REST;
	//Initialisation de valeurs 
	// Allocation de mémoire
	world->sprite = (sprite_t*)malloc(sizeof(sprite_t));
	world->spriteTwo = (sprite_t*)malloc(sizeof(sprite_t));
	world->menu = (sprite_t*)malloc(sizeof(sprite_t));
	world->titre = (sprite_t*)malloc(sizeof(sprite_t));
	world->exit = (sprite_t*)malloc(sizeof(sprite_t));
	world->exit2 = (sprite_t*)malloc(sizeof(sprite_t));
	world->playervsplayer = (sprite_t*)malloc(sizeof(sprite_t));
	world->playervsplayer2 = (sprite_t*)malloc(sizeof(sprite_t));
	world->playervsbot = (sprite_t*)malloc(sizeof(sprite_t));
	world->playervsbot2 = (sprite_t*)malloc(sizeof(sprite_t));
	//initialisation des sprites
	init_sprite(world->sprite,SCREEN_WIDTH/2 - HORIZONTAL_SIZE/2, SCREEN_HEIGHT - VERTICAL_SIZE - 120, HORIZONTAL_SIZE, VERTICAL_SIZE);
	init_sprite(world->spriteTwo,SCREEN_WIDTH/2 - HORIZONTAL_SIZE/2, SCREEN_HEIGHT - VERTICAL_SIZE - 120, HORIZONTAL_SIZE, VERTICAL_SIZE);
	init_sprite(world->menu,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	init_sprite(world->titre,SCREEN_WIDTH/2-TITLE_WIDTH/2,10,TITLE_WIDTH,TITLE_HEIGHT);
	init_hadouken(world);
	init_sprite(world->exit,SCREEN_WIDTH/2-BOUTON_WIDTH/2-50,550,BOUTON_WIDTH,BOUTON_HEIGHT);
	init_sprite(world->exit2,SCREEN_WIDTH/2-BOUTON_WIDTH/2-50,550,BOUTON_WIDTH,BOUTON_HEIGHT);
	init_sprite(world->playervsplayer,SCREEN_WIDTH/2-BOUTON_WIDTH/2-50,350,BOUTON_WIDTH,BOUTON_HEIGHT);
	init_sprite(world->playervsplayer2,SCREEN_WIDTH/2-BOUTON_WIDTH/2-50,350,BOUTON_WIDTH,BOUTON_HEIGHT);
	init_sprite(world->playervsbot,SCREEN_WIDTH/2-BOUTON_WIDTH/2-50,450,BOUTON_WIDTH,BOUTON_HEIGHT);
	init_sprite(world->playervsbot2,SCREEN_WIDTH/2-BOUTON_WIDTH/2-50,450,BOUTON_WIDTH,BOUTON_HEIGHT);
	

}
void init_sprite(sprite_t* sprite, int x, int y, int w, int h) {
	sprite->x = x;
	sprite->y = y;
	sprite->w = w;
	sprite->h = h;


}

int sprites_collide(sprite_t *sp1, sprite_t *sp2)
{
    int w1 = sp1->w;
    int w2 = sp2->w;
    int h1 = sp1->h;
    int h2 = sp2->h;
    int x1 = sp1->x + w1 / 2;
    int x2 = sp2->x + w2 / 2;
    int y1 = sp1->y + h1 / 2;
    int y2 = sp2->y + h2 / 2;

    return (abs(x1 - x2) <= (w1 + w2) / 2) && (abs(y1 - y2) <= (h1 + h2) / 2);
}

void handle_sprites_collision(sprite_t *sp1, sprite_t *sp2, world_t *world)
{
    int collision = sprites_collide(sp1, sp2);
    if (collision == 1)
    {
        sp1->x = sp1->x - 6;
        sp2->x =sp2->x + 6;
    }
}

void handle_sprites_collision_hadoken(sprite_t *sp1, sprite_t *sp2, world_t *world){
	int hadoken = sprites_collide(sp1, sp2);
}




void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    free(world->sprite);
	free(world->spriteTwo);
	free(world->menu);
	free(world->titre);
	free(world->text);
	free(world->exit);
	free(world->exit2);
	free(world->playervsplayer);
	free(world->playervsplayer2);
	free(world->playervsbot);
	free(world->playervsbot2);
}

int is_game_over(world_t *world){
    return world->gameover;
}

void update_hadouken(sprite_t *hadouken, world_t *world){
	hadouken->x = hadouken->x + INITIAL_SPEED ;
}
void gravity(world_t *world){
	if(world->state == JUMP){
		world->vy = -INITIAL_SPEED - 2;
		world->mouvement = 0;
	}
	if(world->sprite->y == 179){
		pause(20);
		world->state = FALL;
		world->mouvement = 0;

	}
	if(world->state == FALL){
		world->vy = INITIAL_SPEED+2;
		world->mouvement = 0;
	}
	if(world->sprite->y == (SCREEN_HEIGHT - VERTICAL_SIZE - 120) && world->state !=JUMP && world->state !=HADOUKEN){
		world->state = REST;
	}
	if(world->state == REST){
		world->vy =0;
	}
	world->sprite->y = world->sprite-> y + world->vy; 

}
void hadouken(world_t *world){
	int compt, temps;
	if(world->test == HADOUKEN){
		temps = 2;
		compt = SDL_GetTicks()/1000;
		if((world->timerlastshoot  +1 > SDL_GetTicks()/1000)){
			world->state = HADOUKEN;
		}else{
			world->state = REST;
			world->test = 0;
		}
	}
	

}


void update_data(world_t *world){
	limite(world);
	hadouken(world);
	for (int i =0 ; i < 10 ; i++){
		if(sprites_collide(world->spriteTwo, &(world->hadouken[i]))){
			world->mouvement2 = 10;
		}
	}
	gravity(world);
	handle_sprites_collision(world->sprite, world->spriteTwo,world);
	for (int i = 0; i <10; i++)
	{
		update_hadouken(&(world->hadouken[i]), world);
		handle_sprites_collision_hadoken(world->spriteTwo, &(world->hadouken[i]),world);
	}
}



void limite(world_t* world) {
	if (world->sprite->x < 0) {
		world->sprite->x = 0;
	}
	if (world->sprite->x > SCREEN_WIDTH - HORIZONTAL_SIZE) {
		world->sprite->x = SCREEN_WIDTH - HORIZONTAL_SIZE;
	}
	//pour le deuxieme personnage
	if (world->spriteTwo->x < 0) {
		world->spriteTwo->x = 0;
	}
	if (world->spriteTwo->x > SCREEN_WIDTH - HORIZONTAL_SIZE) {
		world->spriteTwo->x = SCREEN_WIDTH - HORIZONTAL_SIZE;
	}

}

void init_hadouken(world_t* world) {
	init_sprite(&(world->hadouken[0]),-9990,-9990,96,192);
	init_sprite(&(world->hadouken[1]),-9990,-9990,96,192);
	init_sprite(&(world->hadouken[2]),-9990,-9990,64,160);
	init_sprite(&(world->hadouken[3]),-9990,-9990,288,160);
	init_sprite(&(world->hadouken[4]),-9990,-9990,160,192);
	init_sprite(&(world->hadouken[5]),-9990,-9990,96,192);
	init_sprite(&(world->hadouken[6]),-9990,-9990,128,192);
	init_sprite(&(world->hadouken[7]),-9990,-9990,128,192);
	init_sprite(&(world->hadouken[0]),-9990,-9990,96,192);
	init_sprite(&(world->hadouken[1]),-9990,-9990,96,192);
	init_sprite(&(world->hadouken[2]),-9990,-9990,64,160);

}
