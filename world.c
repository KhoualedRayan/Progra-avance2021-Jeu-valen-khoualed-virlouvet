#include "world.h"
#include "graphisme.h"
#include "constante.h"
#include "sdl2-light.h"


void init_data(world_t * world){
    
    //on n'est pas à la fin du jeu
	world->gameover = 0;
	world->mouvement = 0;
	//Initialisation de valeurs 
	// Allocation de mémoire
	world->sprite = (sprite_t*)malloc(sizeof(sprite_t));
	world->projectile = (sprite_t*)malloc(sizeof(sprite_t));
	world->menu = (sprite_t*)malloc(sizeof(sprite_t));
	//initialisation des sprites
	init_sprite(world->sprite,SCREEN_WIDTH/2 - HORIZONTAL_SIZE/2, SCREEN_HEIGHT - VERTICAL_SIZE - 120, VERTICAL_SIZE, HORIZONTAL_SIZE);
	init_sprite(world->menu,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);

}
void init_sprite(sprite_t* sprite, int x, int y, int w, int h) {
	sprite->x = x;
	sprite->y = y;
	sprite->w = w;
	sprite->h = h;
}



void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    free(world->sprite);
    free(world->projectile);
}

int is_game_over(world_t *world){
    return world->gameover;
}


void update_data(world_t *world){
	limite(world);
	world->projectile->x = world->projectile->x + INITIAL_SPEED;

}



void limite(world_t* world) {
	if (world->sprite->x < 0) {
		world->sprite->x = 0;
	}
	if (world->sprite->x > SCREEN_WIDTH - HORIZONTAL_SIZE) {
		world->sprite->x = SCREEN_WIDTH - HORIZONTAL_SIZE;
	}
}
