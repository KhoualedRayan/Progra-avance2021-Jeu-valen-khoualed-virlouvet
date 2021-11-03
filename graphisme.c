#include "graphisme.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"

int compteur;


void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->charac);
    clean_texture(textures->characTwo);
	clean_texture(textures->tir);
	clean_font(textures->font);

}


void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/harbor.bmp",renderer);
	textures->charac = load_image( "ressources/ryu.bmp",renderer); 
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
    apply_sprite(renderer, textures->charac,world->sprite);
    apply_sprite(renderer, textures->characTwo, world->spriteTwo );
    apply_sprite(renderer, textures->tir, world->projectile);
    apply_sprite(renderer, textures->menu_1,world->menu);
    // on met à jour l'écran
    update_screen(renderer);
	
}





