#include "graphisme.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "animations.h"

//ryu_idle
void ryu_idle_clean(textures_t *textures){
    clean_texture(textures->ryu_idle);
    clean_texture(textures->ryu_idle1);
    clean_texture(textures->ryu_idle2);
    clean_texture(textures->ryu_idle3);

}
void ryu_idle_textures(textures_t *textures, SDL_Renderer *renderer){

    textures->ryu_idle = load_image( "ressources/ryu_idle/f1.bmp",renderer); 
    textures->ryu_idle1 = load_image( "ressources/ryu_idle/f2.bmp",renderer); 
	textures->ryu_idle2 = load_image( "ressources/ryu_idle/f3.bmp",renderer); 
	textures->ryu_idle3 = load_image( "ressources/ryu_idle/f4.bmp",renderer); 
}

void ryu_hit_textures(textures_t *textures, SDL_Renderer *renderer){
    textures->ryu_hit = load_image( "ressources/ryu_hit/f1.bmp", renderer);
    textures->ryu_hit1 = load_image( "ressources/ryu_hit/f1.bmp", renderer);
    textures->ryu_hit2 = load_image( "ressources/ryu_hit/f2.bmp", renderer);
    textures->ryu_hit3 = load_image( "ressources/ryu_hit/f3.bmp", renderer);
}

void ryu_hit_clean(textures_t *textures){
    clean_texture(textures->ryu_hit);
    clean_texture(textures->ryu_hit1);
    clean_texture(textures->ryu_hit2);
    clean_texture(textures->ryu_hit3);

}
//ryu_walking
void ryu_walking_clean(textures_t *textures){

    clean_texture(textures->ryu_walking);
    clean_texture(textures->ryu_walking1);
    clean_texture(textures->ryu_walking2);
    clean_texture(textures->ryu_walking3);
    clean_texture(textures->ryu_walking4);

    //Ryu blocking
    clean_texture(textures->ryu_blocking);
    clean_texture(textures->ryu_blocking1);
}

void ryu_walking_textures(textures_t *textures, SDL_Renderer *renderer){
    textures->ryu_walking = load_image( "ressources/ryu_walking/f1.bmp",renderer); 
    textures->ryu_walking1 = load_image( "ressources/ryu_walking/f2.bmp",renderer);
    textures->ryu_walking2 = load_image( "ressources/ryu_walking/f3.bmp",renderer);
    textures->ryu_walking3 = load_image( "ressources/ryu_walking/f4.bmp",renderer);
    textures->ryu_walking4 = load_image( "ressources/ryu_walking/f5.bmp",renderer);

    //Ryu blocking
    textures->ryu_blocking = load_image( "ressources/ryu_blocking/f1.bmp",renderer); 
    textures->ryu_blocking1 = load_image( "ressources/ryu_blocking/f2.bmp",renderer);
}

//Ryu hadouken
void ryu_hadouken_clean(textures_t *textures){
    clean_texture(textures->ryu_hadouken);
    clean_texture(textures->ryu_hadouken1);
    clean_texture(textures->ryu_hadouken2);
    clean_texture(textures->ryu_hadouken3);
    clean_texture(textures->ryu_hadouken4);
    clean_texture(textures->ryu_hadouken5);
    clean_texture(textures->ryu_hadouken6);
    clean_texture(textures->ryu_hadouken7);
    clean_texture(textures->ryu_hadouken8);
}

void ryu_hadouken_textures(textures_t *textures, SDL_Renderer *renderer){
    textures->ryu_hadouken = load_image( "ressources/ryu_hadouken/f1.bmp",renderer); 
    textures->ryu_hadouken1 = load_image( "ressources/ryu_hadouken/f2.bmp",renderer);
    textures->ryu_hadouken2 = load_image( "ressources/ryu_hadouken/f3.bmp",renderer);
    textures->ryu_hadouken3 = load_image( "ressources/ryu_hadouken/f4.bmp",renderer);
    textures->ryu_hadouken4 = load_image( "ressources/ryu_hadouken/f5.bmp",renderer); 
    textures->ryu_hadouken5 = load_image( "ressources/hadouken/f1.bmp",renderer);
    textures->ryu_hadouken6 = load_image( "ressources/hadouken/f2.bmp",renderer);
    textures->ryu_hadouken7 = load_image( "ressources/hadouken/f3.bmp",renderer); 
    textures->ryu_hadouken8 = load_image( "ressources/hadouken/f4.bmp",renderer); 
}

//ryu_jump
void ryu_jump_clean(textures_t *textures){
    //Ryu jumping
    clean_texture(textures->ryu_jumping);
    clean_texture(textures->ryu_jumping1);
    clean_texture(textures->ryu_jumping2);
    clean_texture(textures->ryu_jumping3);

    //Ryu falling
    clean_texture(textures->ryu_falling);
    clean_texture(textures->ryu_falling1);
    clean_texture(textures->ryu_falling2);
}

void ryu_jump_textures(textures_t *textures, SDL_Renderer *renderer){
    //Ryu jumping
    textures->ryu_jumping = load_image( "ressources/ryu_jumping/f1.bmp",renderer); 
    textures->ryu_jumping1 = load_image( "ressources/ryu_jumping/f2.bmp",renderer);
    textures->ryu_jumping2 = load_image( "ressources/ryu_jumping/f3.bmp",renderer);
    textures->ryu_jumping3 = load_image( "ressources/ryu_jumping/f4.bmp",renderer);

    //Ryu falling
    textures->ryu_falling = load_image( "ressources/ryu_falling/f1.bmp",renderer); 
    textures->ryu_falling1 = load_image( "ressources/ryu_falling/f2.bmp",renderer);
    textures->ryu_falling2 = load_image( "ressources/ryu_falling/f3.bmp",renderer);
}


//ryu_lpunch
void ryu_lpunch_clean(textures_t *textures){
    clean_texture(textures->ryu_lpunch);
    clean_texture(textures->ryu_lpunch1);
}

void ryu_lpunch_textures(textures_t *textures, SDL_Renderer *renderer){
    //Ryu l-punch
    textures->ryu_lpunch = load_image( "ressources/ryu_attacks/l-punch/f1.bmp",renderer); 
    textures->ryu_lpunch1 = load_image( "ressources/ryu_attacks/l-punch/f2.bmp",renderer);
}

//ryu_lkick
void ryu_lkick_clean(textures_t *textures){
    clean_texture(textures->ryu_lkick);
    clean_texture(textures->ryu_lkick1);
}

void ryu_lkick_textures(textures_t *textures, SDL_Renderer *renderer){
    //Ryu l-punch
    textures->ryu_lkick = load_image( "ressources/ryu_attacks/l-kick/f1.bmp",renderer); 
    textures->ryu_lkick1 = load_image( "ressources/ryu_attacks/l-kick/f2.bmp",renderer);
}

//ryu_crouch_lpunch
void ryu_crouch_lpunch_clean(textures_t *textures){
    clean_texture(textures->ryu_crouch_lpunch);
    clean_texture(textures->ryu_crouch_lpunch2);
}

void ryu_crouch_lpunch_textures(textures_t *textures, SDL_Renderer *renderer){
    //Ryu l-punch
    textures->ryu_crouch_lpunch = load_image( "ressources/ryu_attacks/crouch_l-punch/f1.bmp",renderer); 
    textures->ryu_crouch_lpunch2 = load_image( "ressources/ryu_attacks/crouch_l-punch/f2.bmp",renderer);
}

//ryu forwarld low punch
void ryu_forward_lpunch_clean(textures_t *textures){
    clean_texture(textures->ryu_forward_lpunch);
    clean_texture(textures->ryu_forward_lpunch1);
}

void ryu_forward_lpunch_textures(textures_t *textures, SDL_Renderer *renderer){
    //Ryu l-punch
    textures->ryu_forward_lpunch = load_image( "ressources/ryu_attacks/f_l-punch/f1.bmp",renderer); 
    textures->ryu_forward_lpunch1 = load_image( "ressources/ryu_attacks/f_l-punch/f2.bmp",renderer);
}

void ryu_victory_clean(textures_t *textures){
    clean_texture(textures->ryu_victory);
    clean_texture(textures->ryu_victory1);
    clean_texture(textures->ryu_victory2);
}

void ryu_victory_textures(SDL_Renderer *renderer,textures_t *textures){
    //Ryu l-punch
    textures->ryu_victory = load_image( "ressources/ryu_victory/ryu_victory.bmp",renderer); 
    textures->ryu_victory1 = load_image( "ressources/ryu_victory/ryu_victory1.bmp",renderer);
    textures->ryu_victory2 = load_image( "ressources/ryu_victory/ryu_victory2.bmp",renderer);
}

void  init_textures_ryu(SDL_Renderer *renderer, textures_t *textures){
    //Ryu_idle
	ryu_idle_textures(textures,renderer);

    ryu_hit_textures(textures,renderer);

    ryu_walking_textures(textures, renderer);

    ryu_hadouken_textures(textures, renderer);

    ryu_jump_textures(textures,renderer);

    ryu_lpunch_textures(textures,renderer);

    ryu_forward_lpunch_textures(textures,renderer);

    ryu_crouch_lpunch_textures(textures,renderer);

    ryu_lkick_textures(textures,renderer);

    ryu_victory_textures(renderer,textures) ;
    //Ryu crouching
    textures->ryu_crouching = load_image( "ressources/ryu_crouching/f1.bmp",renderer);

    //Ryu hp
    textures->ryu_hp = load_image("ressources/ryu_hp/hp.bmp",renderer);
    textures->ryu_hp_fill = load_image("ressources/ryu_hp/hp_fill.bmp",renderer); 


}

void clean_texture_ryu(textures_t *textures){
    ryu_idle_clean(textures);
    ryu_hit_clean(textures);
    ryu_walking_clean(textures);
    ryu_hadouken_clean(textures);
    ryu_jump_clean(textures);
    ryu_lpunch_clean(textures);
    ryu_lkick_clean(textures);
    ryu_crouch_lpunch_clean(textures);
    ryu_forward_lpunch_clean(textures);
    //Ryu crouching
    clean_texture(textures->ryu_crouching);

    ryu_victory_clean(textures) ;


    //Ryu hp barre
    clean_texture(textures->ryu_hp);
    clean_texture(textures->ryu_hp_fill);
}