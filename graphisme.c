#include "graphisme.h"
#include "ryu_graphisme.h"
#include "ken_graphisme.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "animations.h"
#include "score.h"


void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->background2);
    clean_texture(textures->background3);

    
    //clean ryu
    clean_texture_ryu(textures);
    
    //clean ken
    clean_textures_ken(textures);

    clean_texture(textures->menu_1);
    clean_texture(textures->titre_p);
    clean_texture(textures->exit_normal);
    clean_texture(textures->exit_select);
    clean_texture(textures->pvp_normal);
    clean_texture(textures->pvp_select);
    clean_texture(textures->pvb_normal);
    clean_texture(textures->pvb_select);
    clean_texture(textures->flecheg);
    clean_texture(textures->fleched);
    clean_texture(textures->map1min);
    clean_texture(textures->map2min);
    clean_texture(textures->map3min);
	clean_font(textures->font);
}


void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/map1.bmp",renderer);
    textures->background2 = load_image( "ressources/harbor.bmp",renderer);
    textures->background3 = load_image( "ressources/map3.bmp",renderer);


    //Ryu
	init_textures_ryu(renderer,textures);

    //Ken
    init_textures_ken(renderer, textures);


    //Menu
	textures->menu_1 = load_image( "ressources/fond_menu.bmp",renderer);
    textures->titre_p = load_image("ressources/titre_principal.bmp", renderer);	 
    textures->exit_normal = load_image("ressources/exit.bmp", renderer);	
    textures->exit_select = load_image("ressources/exit_select.bmp", renderer);
    textures->pvp_normal = load_image("ressources/playervsplayer.bmp", renderer);
    textures->pvp_select = load_image("ressources/playervsplayer_select.bmp", renderer);
    textures->pvb_normal = load_image("ressources/playervsbot.bmp", renderer);
    textures->pvb_select = load_image("ressources/playervsbot_select.bmp", renderer);			
	textures->font = load_font("times.ttf", 69);

    //maps menu
    textures->flecheg = load_image("ressources/fleche_gauche.bmp", renderer);
    textures->fleched = load_image("ressources/fleche_droite.bmp", renderer);
    textures->map1min = load_image("ressources/map1_min.bmp", renderer);
    textures->map2min = load_image("ressources/harbor_min.bmp", renderer);
    textures->map3min = load_image("ressources/map3_min.bmp", renderer);


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


void refresh_graphics_menu(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //on vide le renderer
    clear_renderer(renderer);
    //application des textures dans le renderer
    if(world->etat_menu == 0){
        apply_sprite(renderer, textures->menu_1,world->menu);
        apply_sprite(renderer, textures->titre_p,world->titre);
        apply_sprite(renderer, textures->pvp_select,world->playervsplayer2);
        apply_sprite(renderer, textures->pvb_normal,world->playervsbot);
        apply_sprite(renderer, textures->exit_normal,world->exit);
    }    
    if(world->etat_menu == 1){
        apply_sprite(renderer, textures->menu_1,world->menu);
        apply_sprite(renderer, textures->titre_p,world->titre);
        apply_sprite(renderer, textures->pvp_normal,world->playervsplayer);
        apply_sprite(renderer, textures->pvb_select,world->playervsbot2);
        apply_sprite(renderer, textures->exit_normal,world->exit);
    }
    if(world->etat_menu==2){
        apply_sprite(renderer, textures->menu_1,world->menu);
        apply_sprite(renderer, textures->titre_p,world->titre);
        apply_sprite(renderer, textures->pvp_normal,world->playervsplayer);
        apply_sprite(renderer, textures->pvb_normal,world->playervsbot);
        apply_sprite(renderer, textures->exit_select,world->exit2);
    }

    // on met à jour l'écran
    update_screen(renderer);
}

void refresh_graphics_choix_maps(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //on vide le renderer
    clear_renderer(renderer);
    //application des textures dans le renderer
    if(world->etat_maps == 0){
        apply_sprite(renderer, textures->menu_1,world->menu);
        apply_sprite(renderer, textures->fleched,world->fleche_d);
        apply_sprite(renderer, textures->map1min,world->map1_min);
    }
    if(world->etat_maps == 1){
        apply_sprite(renderer, textures->menu_1,world->menu);
        apply_sprite(renderer, textures->fleched,world->fleche_d);
        apply_sprite(renderer, textures->flecheg,world->fleche_g);
        apply_sprite(renderer, textures->map2min,world->map2_min);
    }
    if(world->etat_maps == 2){
        apply_sprite(renderer, textures->menu_1,world->menu);
        apply_sprite(renderer, textures->flecheg,world->fleche_g);
        apply_sprite(renderer, textures->map3min,world->map3_min);
    }    

    // on met à jour l'écran
    update_screen(renderer);
}

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //on vide le renderer
    clear_renderer(renderer);
	
    //application des textures dans le renderer

    if(world->etat_maps ==0){
        apply_background(renderer, textures->background);
    }
    if(world->etat_maps ==1){
        apply_background(renderer, textures->background2);
    }
    if(world->etat_maps ==2){
        apply_background(renderer, textures->background3);
    }
    
    refresh_animations(world,renderer,textures);



    // on met à jour l'écran
    update_screen(renderer);
	
}





