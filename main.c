#include "sdl2-light.h"
#include "world.h"
#include "graphisme.h"
#include "constante.h"
#include "eventsMain.h"
#include "animations.h"



/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world);


void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}


int main( int argc, char* args[] )
{
	
    SDL_Event event;
    world_t world;
    textures_t textures;
    SDL_Renderer *renderer;
    SDL_Window *window;
	
    world.etat_menu = 0;

    while(world.etat_menu == 0 && !is_game_over(&world)){
        //initialisation du jeu
        init(&window,&renderer,&textures,&world);
        while(world.etat_menu != 3){
        
            //gestion des évènements
            handle_events(&event,&world);

            //mise à jour des données liée à la physique du monde
            update_data(&world);

            //affiche le menu
            refresh_graphics_menu(renderer,&world,&textures);

            // pause de 10 ms pour controler la vitesse de rafraichissement
            pause(10);

            world.compteur_menu = (float)(SDL_GetTicks()/1000.);
        }

        if(world.etat_menu==3 && world.gameover==0){
            world.compteur =(float)(SDL_GetTicks()/1000.);
	        world.mouvement = 0;
	        world.mouvement2 = 0;
	        world.defeat_or_win = 0;
	        world.test =0;
            init_sprite(world.sprite,SCREEN_WIDTH/2 - HORIZONTAL_SIZE/2, SCREEN_HEIGHT - VERTICAL_SIZE - 120, HORIZONTAL_SIZE, VERTICAL_SIZE);
	        init_sprite(world.spriteTwo,SCREEN_WIDTH/2 - HORIZONTAL_SIZE/2, SCREEN_HEIGHT - VERTICAL_SIZE - 120, HORIZONTAL_SIZE, VERTICAL_SIZE);
        }
    
        while(!is_game_over(&world)){ //tant que le jeu n'est pas fini

            //gestion des évènements
            handle_events(&event,&world);
        
            //mise à jour des données liée à la physique du monde
            update_data(&world);

	
            //rafraichissement de l'écran
            refresh_graphics(renderer,&world,&textures);
		
            // pause de 10 ms pour controler la vitesse de rafraichissement
            pause(10);    
        }

        if(world.etat_menu == 0){ // retour au menu
            world.gameover=0;
        }

	    pause(1000);
        //nettoyage final
        clean(window,renderer,&textures,&world);
    }
    
   
    
    
    return 0;
}