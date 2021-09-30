#include "graphisme.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"




void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){ 
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
	init_ttf();
    init_textures(*renderer,textures);
}

void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) {
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            world->gameover = 1; 
        }
         //si une touche est appuyée
         if(event->type == SDL_KEYDOWN){
             //si la touche appuyée est 'flèche vers la droite'
            if(event->key.keysym.sym == SDLK_RIGHT){
				world->sprite->x = world->sprite->x + MOVING_STEP;
            }
			if(event->key.keysym.sym == SDLK_LEFT){ //si la touche appuyée est 'flèche vers la gauche'
                world->sprite->x = world->sprite->x - MOVING_STEP;
            }
			if(event->key.keysym.sym == SDLK_DOWN){ //si la touche appuyée est 'flèche vers le bas'
                world->vy = world->vy - 1;
            }
			if(event->key.keysym.sym == SDLK_UP){ //si la touche appuyée est 'flèche vers le haut'
                world->vy = world->vy + 1;
            }
			if(event->key.keysym.sym == SDLK_ESCAPE){ //si la touche appuyée est 'Echap'
				world->gameover = 1;
            }
			if(event->key.keysym.sym == SDLK_SPACE){ //si la touche appuyée est 'Espace'
				init_sprite(world->projectile,world->sprite->x + HORIZONTAL_SIZE  , world->sprite->y + PROJECTILE_SIZE, PROJECTILE_SIZE, PROJECTILE_SIZE);
            }
			 
         }
	   
    }
}