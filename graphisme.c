#include "graphisme.h"
#include "ryu_graphisme.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "animations.h"


void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    //Ryu_idle
    clean_texture_ryu(textures) ;


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

    //Ryu jumping
    clean_texture(textures->ryu_lpunch);
    clean_texture(textures->ryu_lpunch1);
    clean_texture(textures->ryu_lpunch2);

    //Ryu hp barre
    clean_texture(textures->ryu_hp);
    clean_texture(textures->ryu_hp_fill);

    //Ken hp barre
    clean_texture(textures->ken_hp);
    clean_texture(textures->ken_hp_fill);

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
    
    //ken_hadouken
    clean_texture(textures->ken_hadouken);
    clean_texture(textures->ken_hadouken1);
    clean_texture(textures->ken_hadouken2);
    clean_texture(textures->ken_hadouken3);

    clean_texture(textures->menu_1);
    clean_texture(textures->titre_p);
    clean_texture(textures->exit_normal);
    clean_texture(textures->exit_select);
    clean_texture(textures->pvp_normal);
    clean_texture(textures->pvp_select);
    clean_texture(textures->pvb_normal);
    clean_texture(textures->pvb_select);
	clean_font(textures->font);
}


void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/harbor.bmp",renderer);
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

    //ken_hadouken
    textures->ken_hadouken = load_image( "ressources/ken_hadouken/ken_hadouken.bmp",renderer); 
    textures->ken_hadouken1 = load_image( "ressources/ken_hadouken/ken_hadouken1.bmp",renderer);
    textures->ken_hadouken2 = load_image( "ressources/ken_hadouken/ken_hadouken2.bmp",renderer);
    textures->ken_hadouken3 = load_image( "ressources/ken_hadouken/ken_hadouken3.bmp",renderer); 

    //Ken_hp
    textures->ken_hp = load_image("ressources/ken_hp/hp.bmp",renderer);
    textures->ken_hp_fill = load_image("ressources/ken_hp/hp_fill.bmp",renderer);

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

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    //on vide le renderer
    clear_renderer(renderer);
	
    //application des textures dans le renderer
    apply_background(renderer, textures->background);
    refresh_animations(world,renderer,textures);



    // on met à jour l'écran
    update_screen(renderer);
	
}





