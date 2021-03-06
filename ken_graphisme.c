#include "graphisme.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "animations.h"

//ken_idle
void ken_idle_clean(textures_t *textures){

    clean_texture(textures->ken_idle);
    clean_texture(textures->ken_idle1);
    clean_texture(textures->ken_idle2);
    clean_texture(textures->ken_idle3);
}

void ken_idle_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->ken_idle = load_image( "ressources/ken_idle/ken_idle.bmp",renderer);
    textures->ken_idle1 = load_image( "ressources/ken_idle/ken_idle1.bmp",renderer);
    textures->ken_idle2 = load_image( "ressources/ken_idle/ken_idle2.bmp",renderer);
    textures->ken_idle3 = load_image( "ressources/ken_idle/ken_idle3.bmp",renderer);
}

//ken_walking
void ken_walking_clean(textures_t *textures){
    clean_texture(textures->ken_walking);
    clean_texture(textures->ken_walking1);
    clean_texture(textures->ken_walking2);
    clean_texture(textures->ken_walking3);
    clean_texture(textures->ken_walking4);
    //Ken blocking
    clean_texture(textures->ken_blocking);
    clean_texture(textures->ken_blocking1);
}

void ken_walking_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->ken_walking = load_image( "ressources/ken_walking/ken_walking1.bmp", renderer);
    textures->ken_walking1 = load_image( "ressources/ken_walking/ken_walking2.bmp", renderer);
    textures->ken_walking2 = load_image( "ressources/ken_walking/ken_walking3.bmp", renderer);
    textures->ken_walking3 = load_image( "ressources/ken_walking/ken_walking4.bmp", renderer);
    textures->ken_walking4 = load_image( "ressources/ken_walking/ken_walking5.bmp", renderer);
    //Ken blocking
    textures->ken_blocking = load_image( "ressources/ken_blocking/f1.bmp",renderer); 
    textures->ken_blocking1 = load_image( "ressources/ken_blocking/f2.bmp",renderer);
}

//ken hit
void ken_hit_clean(textures_t *textures){
    clean_texture(textures->ken_hit);
    clean_texture(textures->ken_hit1);
    clean_texture(textures->ken_hit2);
    clean_texture(textures->ken_hit3);
}

void ken_hit_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->ken_hit = load_image( "ressources/ken_hit/ken_hit.bmp", renderer);
    textures->ken_hit1 = load_image( "ressources/ken_hit/ken_hit1.bmp", renderer);
    textures->ken_hit2 = load_image( "ressources/ken_hit/ken_hit2.bmp", renderer);
    textures->ken_hit3 = load_image( "ressources/ken_hit/ken_hit3.bmp", renderer);
}

//ken_hadouken
void ken_hadouken_clean(textures_t *textures){
    clean_texture(textures->ken_hadouken);
    clean_texture(textures->ken_hadouken1);
    clean_texture(textures->ken_hadouken2);
    clean_texture(textures->ken_hadouken3);
    clean_texture(textures->ken_hadouken4);
    clean_texture(textures->ken_hadouken5);
    clean_texture(textures->ken_hadouken6);
}

void ken_hadouken_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->ken_hadouken = load_image( "ressources/ken_hadouken/ken_hadouken.bmp",renderer); 
    textures->ken_hadouken1 = load_image( "ressources/ken_hadouken/ken_hadouken1.bmp",renderer);
    textures->ken_hadouken2 = load_image( "ressources/ken_hadouken/ken_hadouken2.bmp",renderer);
    textures->ken_hadouken3 = load_image( "ressources/ken_hadouken/ken_hadouken3.bmp",renderer); 
    textures->ken_hadouken4 = load_image( "ressources/hadouken/hadouken_k.bmp",renderer); 
    textures->ken_hadouken6 = load_image( "ressources/hadouken/hadouken_k1.bmp",renderer); 
    textures->ken_hadouken5 = load_image( "ressources/hadouken/hadouken_k2.bmp",renderer); 
}

//ken_lpunch
void ken_lpunch_clean(textures_t *textures){
    clean_texture(textures->ken_lpunch);
    clean_texture(textures->ken_lpunch1);
}

void ken_lpunch_textures( SDL_Renderer *renderer,textures_t *textures){
    //Ryu l-punch
    textures->ken_lpunch = load_image( "ressources/ken_attacks/l-punch/f1.bmp",renderer); 
    textures->ken_lpunch1 = load_image( "ressources/ken_attacks/l-punch/f2.bmp",renderer);
}

//ken_lkick
void ken_lkick_clean(textures_t *textures){
    clean_texture(textures->ken_lkick);
    clean_texture(textures->ken_lkick1);
}

void ken_lkick_textures(SDL_Renderer *renderer,textures_t *textures){
    //Ryu l-punch
    textures->ken_lkick = load_image( "ressources/ken_attacks/l-kick/f1.bmp",renderer); 
    textures->ken_lkick1 = load_image( "ressources/ken_attacks/l-kick/f2.bmp",renderer);
}

//ken_crouch_lpunch
void ken_crouch_lpunch_clean(textures_t *textures){
    clean_texture(textures->ken_crouch_lpunch);
    clean_texture(textures->ken_crouch_lpunch2);
}

void ken_crouch_lpunch_textures(SDL_Renderer *renderer,textures_t *textures){
    //Ryu l-punch
    textures->ken_crouch_lpunch = load_image( "ressources/ken_attacks/crouch_l-punch/f1.bmp",renderer); 
    textures->ken_crouch_lpunch2 = load_image( "ressources/ken_attacks/crouch_l-punch/f2.bmp",renderer);
}

void ken_victory_clean(textures_t *textures){
    clean_texture(textures->ken_victory);
    clean_texture(textures->ken_victory1);
    clean_texture(textures->ken_victory2);
}

void ken_victory_textures(SDL_Renderer *renderer,textures_t *textures){
    //Ryu l-punch
    textures->ken_victory = load_image( "ressources/ken_victory/ken_victory.bmp",renderer); 
    textures->ken_victory1 = load_image( "ressources/ken_victory/ken_victory1.bmp",renderer);
    textures->ken_victory2 = load_image( "ressources/ken_victory/ken_victory2.bmp",renderer);
}

void ken_Ko_clean(textures_t *textures){
    clean_texture(textures->ken_Ko);
    clean_texture(textures->ken_Ko1);
    clean_texture(textures->ken_Ko2);
}

void ken_Ko_textures(SDL_Renderer *renderer,textures_t *textures){
    //Ryu l-punch
    textures->ken_Ko = load_image( "ressources/Ken_ko/Ken_Ko.bmp",renderer); 
    textures->ken_Ko1 = load_image( "ressources/Ken_ko/Ken_Ko1.bmp",renderer); 
    textures->ken_Ko2 = load_image( "ressources/Ken_ko/Ken_Ko2.bmp",renderer); 
}



void clean_textures_ken(textures_t *textures){
    ken_idle_clean(textures);
    ken_hit_clean(textures);
    ken_walking_clean(textures);
    ken_hadouken_clean(textures);
    ken_crouch_lpunch_clean(textures);
    ken_lpunch_clean(textures);
    ken_lkick_clean(textures);
    ken_victory_clean(textures);
    ken_Ko_clean(textures);
    //Ken hp barre
    clean_texture(textures->ken_hp);
    clean_texture(textures->ken_hp_fill);
    clean_texture(textures->ken_crouching);

}



void  init_textures_ken(SDL_Renderer *renderer, textures_t *textures){
    ken_hit_textures(renderer,textures);
    ken_idle_textures(renderer,textures);
    ken_walking_textures(renderer,textures);
    ken_hadouken_textures(renderer,textures);
    ken_crouch_lpunch_textures(renderer,textures);
    ken_lkick_textures(renderer,textures);
    ken_lpunch_textures(renderer,textures);
    ken_victory_textures(renderer, textures);
    ken_Ko_textures(renderer, textures);

    //Ken_hp
    textures->ken_hp = load_image("ressources/ken_hp/hp.bmp",renderer);
    textures->ken_hp_fill = load_image("ressources/ken_hp/hp_fill.bmp",renderer);

    //Ken crouching
    textures->ken_crouching = load_image( "ressources/ken_crouching/f1.bmp",renderer);

}