#include "graphisme.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"

int walk = 0;
int walk2 = 0;


void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){ 
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
	init_ttf();
    init_textures(*renderer,textures);
}

void handle_events_menu(SDL_Event *event,world_t *world){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        switch (event->type)
        {
        case SDL_KEYDOWN:
            //SDL_Log("+key");

            if (keystates[SDL_SCANCODE_DOWN] && world->etat_menu == 0){
                //SDL_Log("Keycode fleche bas"); // Affiche un message
                world->etat_menu++;
            }else{
                if (keystates[SDL_SCANCODE_DOWN] && world->etat_menu == 1){
                    //SDL_Log("Keycode fleche bas"); // Affiche un message
                    world->etat_menu++;
                }else{
                    if (keystates[SDL_SCANCODE_UP] && world->etat_menu == 2){
                        //SDL_Log("Keycode fleche haut"); // Affiche un message
                        world->etat_menu--;
                    }else{
                        if (keystates[SDL_SCANCODE_UP] && world->etat_menu == 1){
                            //SDL_Log("Keycode fleche haut"); // Affiche un message
                            world->etat_menu--;
                        }
                        }
                    }
                }

            if(keystates[SDL_SCANCODE_RETURN] && world->etat_menu == 0){
                world->etat_menu = 3;
            }
            if(keystates[SDL_SCANCODE_RETURN] && world->etat_menu == 2){
                world->etat_menu = 3;
                world->gameover = 1; 
            }
        break;
    }

}

void handle_events_ryu(SDL_Event *event,world_t *world){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        switch (event->type)
        {
        case SDL_KEYDOWN:
            //SDL_Log("+key");
            if (keystates[SDL_SCANCODE_D] && world->state == REST){ // Regarde si le scancode W est enfoncé (Z sous un azerty)
                //SDL_Log("Scancode fleche droite"); // Affiche un message
                world->sprite->x = world->sprite->x + MOVING_STEP;
                world->mouvement = 1;
                walk = 1;
            }

            if (keystates[SDL_SCANCODE_A]&& world->state == REST){ // Regarde si le keycode w est enfoncé (la touche W sous un azerty)
                //SDL_Log("Keycode fleche gauche"); // Affiche un message
                world->sprite->x = world->sprite->x - MOVING_STEP/2;
                world->mouvement = 2;
                walk=1;

            }

            if (keystates[SDL_SCANCODE_S]&& walk ==0 &&world->state == REST){ // Regarde si on appuyer sur la touche Z (la touche Z sous un azerty)
                //SDL_Log("Keycode fleche bas"); // Affiche un message
                world->state = CROUCH;
                world->mouvement=3;
                world->sprite->y = world->sprite->y + 144;
                world->crouch = 1;
            }
            if (keystates[SDL_SCANCODE_W] && world->state == REST){ // Regarde si on appuyer sur la touche Z (la touche Z sous un azerty)
                //SDL_Log("Keycode fleche bas"); // Affiche un message
                world->state = JUMP;
            }
            if(keystates[SDL_SCANCODE_LSHIFT] && walk==0 &&world->state == REST&&world->state <=0){ //si la touche appuyée est 'Lshift'
                world->mouvement = 5;
            }
            if(keystates[SDL_SCANCODE_LSHIFT] && keystates[SDL_SCANCODE_S] && walk ==0 && world->state == CROUCH ){
                world->mouvement = 8;
            }
            if(keystates[SDL_SCANCODE_S] && keystates[SDL_SCANCODE_J] && walk ==0 && world->state == CROUCH){
                world->test = ATTACK;
                world->typeOfAttack = CROUCH_LPUNCH;
                world->addw = 23;
                world->addy = 144;
                world->timerLastAttack = SDL_GetTicks()/1000;
            }
            if(keystates[SDL_SCANCODE_J] && world->state == REST && walk == 0 && world->addy == 0){
                world->test = ATTACK;
                world->typeOfAttack = LPUNCH;
                world->addw = 23;
                world->timerLastAttack = SDL_GetTicks()/1000;
            }
            if(keystates[SDL_SCANCODE_K] && world->state == REST && walk == 0  && world->addy == 0){
                world->test = ATTACK;
                world->typeOfAttack = LKICK;
                world->addw = 23;
                world->timerLastAttack = SDL_GetTicks()/1000;
            }
            if(keystates[SDL_SCANCODE_SPACE] && walk ==0 && world->timerlastshoot + world->firerate < SDL_GetTicks()/1000 && world->state == REST){
                world->nbr_hadouken = world->nbr_hadouken + 1;
                world->timerlastshoot = SDL_GetTicks()/1000;
                if (world->nbr_hadouken == 10){
                    world->nbr_hadouken = 0;
                }
                world->test = HADOUKEN;

            }
            break;
        
        case SDL_KEYUP:// Un événement de type touche relâchée
            //SDL_Log("-key");
            walk = 0;
            world->mouvement =0;
            if(world->state != ATTACKED){
                world->mouvement =0;
            }
            if(world->crouch == 1){
                world->sprite->y = world->sprite->y - 144;
                world->crouch = 0;
                world->spriteAttack->y -= 144;
                world->state = REST;
            }
            break;
    }

}

void handle_events_ken(SDL_Event *event,world_t *world){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        switch (event->type)
        {
        case SDL_KEYDOWN:
            //SDL_Log("+key");
            if(keystates[SDL_SCANCODE_RIGHT] && world->state_ken == REST_KEN){ //si la touche appuyée est 'd'

                world->spriteTwo->x = world->spriteTwo->x + MOVING_STEP/2;
                world->mouvement2 = 1; 
                walk2 = 1;
                
            }
			if(keystates[SDL_SCANCODE_LEFT] && world->state_ken == REST_KEN){ //si la touche appuyée est 'a'
                world->spriteTwo->x = world->spriteTwo->x - MOVING_STEP;
                world->mouvement2 = 2;
                walk2=1;
                
            }
			if(keystates[SDL_SCANCODE_DOWN] && walk2 == 0){ //si la touche appuyée est 's'
                world->mouvement2 = 3;

            }
			if(keystates[SDL_SCANCODE_UP]){ //si la touche appuyée est 'z'
                
            }
            if(keystates[SDL_SCANCODE_RSHIFT] && walk2 ==0 && world->timerlastshoot + world->firerate < SDL_GetTicks()/1000 && world->state_ken == REST_KEN){
                world->nbr_hadouken = world->nbr_hadouken + 1;
                world->timerlastshoot = SDL_GetTicks()/1000;
                if (world->nbr_hadouken == 10){
                    world->nbr_hadouken = 0;
                }
                world->test = HADOUKEN_KEN;

            }

            break;
        
        case SDL_KEYUP:// Un événement de type touche relâchée
            //SDL_Log("-key");
            walk2 = 0;
            if(world->state_ken != ATTACKED){
                world->mouvement2 =0;
            }
            break;
        
        
    } 

}

void handle_events(SDL_Event *event,world_t *world){
    const Uint8 *keystates;

    
    while( SDL_PollEvent( event ) ) {
        handle_events_menu(event,world);
        if(world->etat_menu == 3){
            handle_events_ryu(event,world);
            handle_events_ken(event,world);
        }
        //Si l'utilisateur a cliqué sur le X de la fenêtre 
        if( event->type == SDL_QUIT ) {
            //On indique la fin du jeu
            world->etat_menu = 3;
            world->gameover = 1; 
        }
         //si une touche est appuyée
         if(event->type == SDL_KEYDOWN){
			if(event->key.keysym.sym == SDLK_ESCAPE){ //si la touche appuyée est 'Echap'
                world->etat_menu = 3;
				world->gameover = 1;
            }
         }
    }
}