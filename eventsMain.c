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

void handle_events_ryu(SDL_Event *event,world_t *world){
    Uint8 *keystates;
        switch (event->type)
        {
        case SDL_KEYDOWN:
            //SDL_Log("+key");
            if (event->key.keysym.scancode == SDL_SCANCODE_RIGHT){ // Regarde si le scancode W est enfoncé (Z sous un azerty)
                //SDL_Log("Scancode fleche droite"); // Affiche un message
                world->sprite->x = world->sprite->x + MOVING_STEP;
                world->mouvement = 1;
            }

            if (event->key.keysym.sym == SDLK_LEFT){ // Regarde si le keycode w est enfoncé (la touche W sous un azerty)
                //SDL_Log("Keycode fleche gauche"); // Affiche un message
                world->sprite->x = world->sprite->x - MOVING_STEP/2;
                world->mouvement = 2;

            }

            if (event->key.keysym.sym == SDLK_DOWN){ // Regarde si on appuyer sur la touche Z (la touche Z sous un azerty)
                //SDL_Log("Keycode fleche bas"); // Affiche un message
                world->mouvement = 3;
            }
            if(event->key.keysym.sym == SDLK_RCTRL){ //si la touche appuyée est 'flèche vers la gauche'
                //world->sprite->x = world->sprite->x - MOVING_STEP/2;
                world->mouvement = 5;
                
            }
            if(event->key.keysym.sym == SDLK_SPACE){ //si la touche appuyée est 'Espace'
                world->mouvement = 4;
				//init_sprite(world->projectile,world->sprite->x + HORIZONTAL_SIZE  , world->sprite->y + PROJECTILE_SIZE, PROJECTILE_SIZE, PROJECTILE_SIZE);
            }


            break;
        
        case SDL_KEYUP:// Un événement de type touche relâchée
            //SDL_Log("-key");
            break;
        
        
    }

}
void handle_events_ken(SDL_Event *event,world_t *world){
    Uint8 *keystates;
        switch (event->type)
        {
        case SDL_KEYDOWN:
            //SDL_Log("+key");
            if(event->key.keysym.sym == SDLK_d){ 
				world->spriteTwo->x = world->spriteTwo->x + MOVING_STEP/2;
                
            }
			if(event->key.keysym.sym == SDLK_q){ //si la touche appuyée est 'flèche vers la gauche'
                world->spriteTwo->x = world->spriteTwo->x - MOVING_STEP;
                
            }
			if(event->key.keysym.sym == SDLK_s){ //si la touche appuyée est 'flèche vers le bas'

            }
			if(event->key.keysym.sym == SDLK_z){ //si la touche appuyée est 'flèche vers le haut'
                
            }


            break;
        
        case SDL_KEYUP:// Un événement de type touche relâchée
            //SDL_Log("-key");
            break;
        
        
    }

}

void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;

    
    while( SDL_PollEvent( event ) ) {
        handle_events_ryu(event,world);
        handle_events_ken(event,world);

        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            world->gameover = 1; 
        }
         //si une touche est appuyée
         if(event->type == SDL_KEYDOWN){

			if(event->key.keysym.sym == SDLK_ESCAPE){ //si la touche appuyée est 'Echap'
				world->gameover = 1;
            }
			 
         }else{
            world->mouvement =0;

         }
	   
    }
}