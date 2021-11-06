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
    //ken_idle
    clean_texture(textures->ken_idle);
    clean_texture(textures->ken_idle1);
    clean_texture(textures->ken_idle2);
    clean_texture(textures->ken_idle3);

	clean_texture(textures->tir);
	clean_font(textures->font);

}


void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/harbor.bmp",renderer);
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

    //Ken_idle
    textures->ken_idle = load_image( "ressources/ken_idle/ken_idle.bmp",renderer);
    textures->ken_idle1 = load_image( "ressources/ken_idle/ken_idle1.bmp",renderer);
    textures->ken_idle2 = load_image( "ressources/ken_idle/ken_idle2.bmp",renderer);
    textures->ken_idle3 = load_image( "ressources/ken_idle/ken_idle3.bmp",renderer);
    //Ryu walking
    textures->ryu_hadouken = load_image( "ressources/ryu_hadouken/f1.bmp",renderer); 
    textures->ryu_hadouken1 = load_image( "ressources/ryu_hadouken/f2.bmp",renderer);
    textures->ryu_hadouken2 = load_image( "ressources/ryu_hadouken/f3.bmp",renderer);
    textures->ryu_hadouken3 = load_image( "ressources/ryu_hadouken/f4.bmp",renderer);
    textures->ryu_hadouken4 = load_image( "ressources/ryu_hadouken/f5.bmp",renderer);

    //Ken
    textures->characTwo = load_image( "ressources/Ken.bmp",renderer);

	textures->tir = load_image( "ressources/hadouken.bmp",renderer);  
	textures->menu_1 = load_image( "ressources/fond_menu.bmp",renderer);	 			
	textures->font = load_font("times.ttf", 69);
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
    apply_sprite(renderer, textures->tir, world->projectile);
    //apply_sprite(renderer, textures->menu_1,world->menu);
    refresh_animations(world,renderer,textures);



    // on met à jour l'écran
    update_screen(renderer);
	
}





