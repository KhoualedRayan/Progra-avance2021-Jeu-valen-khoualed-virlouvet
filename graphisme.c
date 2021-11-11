#include "graphisme.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "animations.h"



void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    //Ryu_idle
    clean_texture(textures->ryu_idle);
    clean_texture(textures->ryu_idle1);
    clean_texture(textures->ryu_idle2);
    clean_texture(textures->ryu_idle3);

    //Ryu walking
    clean_texture(textures->ryu_walking);
    clean_texture(textures->ryu_walking1);
    clean_texture(textures->ryu_walking2);
    clean_texture(textures->ryu_walking3);
    clean_texture(textures->ryu_walking4);

    //Ryu blocking
    clean_texture(textures->ryu_blocking);
    clean_texture(textures->ryu_blocking1);

    //Ryu crouching
    clean_texture(textures->ryu_crouching);

    //Ryu hadouken
    clean_texture(textures->ryu_hadouken);
    clean_texture(textures->ryu_hadouken1);
    clean_texture(textures->ryu_hadouken2);
    clean_texture(textures->ryu_hadouken3);
    clean_texture(textures->ryu_hadouken4);
    clean_texture(textures->ryu_hadouken5);
    clean_texture(textures->ryu_hadouken6);
    clean_texture(textures->ryu_hadouken7);
    clean_texture(textures->ryu_hadouken8);

    //Ryu jumping
    clean_texture(textures->ryu_jumping);
    clean_texture(textures->ryu_jumping1);
    clean_texture(textures->ryu_jumping2);
    clean_texture(textures->ryu_jumping3);

    //Ryu jumping
    clean_texture(textures->ryu_falling);
    clean_texture(textures->ryu_falling1);
    clean_texture(textures->ryu_falling2);

    //ken_idle
    clean_texture(textures->ken_idle);
    clean_texture(textures->ken_idle1);
    clean_texture(textures->ken_idle2);
    clean_texture(textures->ken_idle3);

    //ken_walking
    clean_texture(textures->ken_walking);
    clean_texture(textures->ken_walking1);
    clean_texture(textures->ken_walking2);
    clean_texture(textures->ken_walking3);
    clean_texture(textures->ken_walking4);

    clean_texture(textures->menu_1);
    clean_texture(textures->titre_p);
	clean_font(textures->font);
}


void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/harbor.bmp",renderer);
    //Ryu
	init_textures_ryu(renderer,textures);

    //Ken
    init_textures_ken(renderer, textures);

	textures->menu_1 = load_image( "ressources/fond_menu.bmp",renderer);
    textures->titre_p = load_image("ressources/titre_principal.bmp", renderer);	 			
	textures->font = load_font("times.ttf", 69);
}

void  init_textures_ryu(SDL_Renderer *renderer, textures_t *textures){
    //Ryu_idle
	textures->ryu_idle = load_image( "ressources/ryu_idle/f1.bmp",renderer); 
    textures->ryu_idle1 = load_image( "ressources/ryu_idle/f2.bmp",renderer); 
	textures->ryu_idle2 = load_image( "ressources/ryu_idle/f3.bmp",renderer); 
	textures->ryu_idle3 = load_image( "ressources/ryu_idle/f4.bmp",renderer); 

    //Ryu walking
    textures->ryu_walking = load_image( "ressources/ryu_walking/f1.bmp",renderer); 
    textures->ryu_walking1 = load_image( "ressources/ryu_walking/f2.bmp",renderer);
    textures->ryu_walking2 = load_image( "ressources/ryu_walking/f3.bmp",renderer);
    textures->ryu_walking3 = load_image( "ressources/ryu_walking/f4.bmp",renderer);
    textures->ryu_walking4 = load_image( "ressources/ryu_walking/f5.bmp",renderer);

    //Ryu walking
    textures->ryu_blocking = load_image( "ressources/ryu_blocking/f1.bmp",renderer); 
    textures->ryu_blocking1 = load_image( "ressources/ryu_blocking/f2.bmp",renderer);

    //Ryu crouching
    textures->ryu_crouching = load_image( "ressources/ryu_crouching/f1.bmp",renderer);

    //Ryu walking
    textures->ryu_hadouken = load_image( "ressources/ryu_hadouken/f1.bmp",renderer); 
    textures->ryu_hadouken1 = load_image( "ressources/ryu_hadouken/f2.bmp",renderer);
    textures->ryu_hadouken2 = load_image( "ressources/ryu_hadouken/f3.bmp",renderer);
    textures->ryu_hadouken3 = load_image( "ressources/ryu_hadouken/f4.bmp",renderer);
    textures->ryu_hadouken4 = load_image( "ressources/ryu_hadouken/f5.bmp",renderer); 
    textures->ryu_hadouken5 = load_image( "ressources/hadouken/f1.bmp",renderer);
    textures->ryu_hadouken6 = load_image( "ressources/hadouken/f2.bmp",renderer);
    textures->ryu_hadouken7 = load_image( "ressources/hadouken/f3.bmp",renderer); 
    textures->ryu_hadouken8 = load_image( "ressources/hadouken/f4.bmp",renderer); 

      //Ryu falling
    textures->ryu_falling = load_image( "ressources/ryu_falling/f1.bmp",renderer); 
    textures->ryu_falling1 = load_image( "ressources/ryu_falling/f2.bmp",renderer);
    textures->ryu_falling2 = load_image( "ressources/ryu_falling/f3.bmp",renderer);

    //Ryu jumping
    textures->ryu_jumping = load_image( "ressources/ryu_jumping/f1.bmp",renderer); 
    textures->ryu_jumping1 = load_image( "ressources/ryu_jumping/f2.bmp",renderer);
    textures->ryu_jumping2 = load_image( "ressources/ryu_jumping/f3.bmp",renderer);
    textures->ryu_jumping3 = load_image( "ressources/ryu_jumping/f4.bmp",renderer);
}

void  init_textures_ken(SDL_Renderer *renderer, textures_t *textures){


    //Ken_idle
    textures->ken_idle = load_image( "ressources/ken_idle/ken_idle.bmp",renderer);
    textures->ken_idle1 = load_image( "ressources/ken_idle/ken_idle1.bmp",renderer);
    textures->ken_idle2 = load_image( "ressources/ken_idle/ken_idle2.bmp",renderer);
    textures->ken_idle3 = load_image( "ressources/ken_idle/ken_idle3.bmp",renderer);
    //ken_walking
    textures->ken_walking = load_image( "ressources/ken_walking/ken_walking1.bmp", renderer);
    textures->ken_walking1 = load_image( "ressources/ken_walking/ken_walking2.bmp", renderer);
    textures->ken_walking2 = load_image( "ressources/ken_walking/ken_walking3.bmp", renderer);
    textures->ken_walking3 = load_image( "ressources/ken_walking/ken_walking4.bmp", renderer);
    textures->ken_walking4 = load_image( "ressources/ken_walking/ken_walking5.bmp", renderer);
    //ken_hit
    textures->ken_hit = load_image( "ressources/ken_hit/ken_hit.bmp", renderer);
    textures->ken_hit1 = load_image( "ressources/ken_hit/ken_hit1.bmp", renderer);
    textures->ken_hit2 = load_image( "ressources/ken_hit/ken_hit2.bmp", renderer);
    textures->ken_hit3 = load_image( "ressources/ken_hit/ken_hit3.bmp", renderer);

}


void apply_background(SDL_Renderer *renderer, SDL_Texture *texture){
    if(texture != NULL){
      apply_texture(texture, renderer, 0, 0);
    }
}

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite){
	if(texture != NULL){
		apply_texture(texture, renderer, sprite->x, sprite->y);
    }
}



void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //on vide le renderer
    clear_renderer(renderer);
	
    //application des textures dans le renderer
    apply_background(renderer, textures->background);
    //apply_sprite(renderer, textures->menu_1,world->menu);
    refresh_animations(world,renderer,textures);



    // on met à jour l'écran
    update_screen(renderer);
	
}





