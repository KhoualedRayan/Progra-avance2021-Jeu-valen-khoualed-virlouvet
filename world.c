#include "world.h"
#include "graphisme.h"
#include "constante.h"
#include "sdl2-light.h"


void init_data(world_t * world){
    
    //on n'est pas à la fin du jeu
	world->gameover = 0;
	world->mouvement = 0;
	world->defeat_or_win = 0;
	world->test =0;
	//Initialisation de valeurs 
	// Allocation de mémoire
	world->sprite = (sprite_t*)malloc(sizeof(sprite_t));
	world->spriteTwo = (sprite_t*)malloc(sizeof(sprite_t));
	world->projectile = (sprite_t*)malloc(sizeof(sprite_t));
	world->menu = (sprite_t*)malloc(sizeof(sprite_t));
	//initialisation des sprites
	init_sprite(world->sprite,SCREEN_WIDTH/2 - HORIZONTAL_SIZE/2, SCREEN_HEIGHT - VERTICAL_SIZE - 120, HORIZONTAL_SIZE, VERTICAL_SIZE);
	init_sprite(world->spriteTwo,SCREEN_WIDTH/2 - HORIZONTAL_SIZE/2, SCREEN_HEIGHT - VERTICAL_SIZE - 120, HORIZONTAL_SIZE, VERTICAL_SIZE);
	init_sprite(world->menu,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);




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
	if (hadoken == 1)
    {
        sp1->x = 1000000000;
    } 
}



void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    free(world->sprite);
	free(world->spriteTwo);
    free(world->projectile);
}

int is_game_over(world_t *world){
    return world->gameover;
}


void update_data(world_t *world){
	limite(world);
	world->projectile->x = world->projectile->x + INITIAL_SPEED;
	handle_sprites_collision(world->sprite, world->spriteTwo,world);
	handle_sprites_collision_hadoken(world->spriteTwo, world->projectile,world);
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
