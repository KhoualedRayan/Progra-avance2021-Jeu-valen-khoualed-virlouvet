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
}

void ken_walking_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->ken_walking = load_image( "ressources/ken_walking/ken_walking1.bmp", renderer);
    textures->ken_walking1 = load_image( "ressources/ken_walking/ken_walking2.bmp", renderer);
    textures->ken_walking2 = load_image( "ressources/ken_walking/ken_walking3.bmp", renderer);
    textures->ken_walking3 = load_image( "ressources/ken_walking/ken_walking4.bmp", renderer);
    textures->ken_walking4 = load_image( "ressources/ken_walking/ken_walking5.bmp", renderer);
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

void clean_textures_ken(textures_t *textures){
    ken_idle_clean(textures);
    ken_hit_clean(textures);
    ken_walking_clean(textures);
    ken_hadouken_clean(textures);
    //Ken hp barre
    clean_texture(textures->ken_hp);
    clean_texture(textures->ken_hp_fill);
}



void  init_textures_ken(SDL_Renderer *renderer, textures_t *textures){
    ken_hit_textures(renderer,textures);
    ken_idle_textures(renderer,textures);
    ken_walking_textures(renderer,textures);
    ken_hadouken_textures(renderer,textures);

    //Ken_hp
    textures->ken_hp = load_image("ressources/ken_hp/hp.bmp",renderer);
    textures->ken_hp_fill = load_image("ressources/ken_hp/hp_fill.bmp",renderer);

}