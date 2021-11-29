#ifndef __KEN_GRAPHISME__H__
#define __KEN_GRAPHISME__H__

#include "graphisme.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "animations.h"


void ken_idle_clean(textures_t *textures);

void ken_idle_textures(SDL_Renderer *renderer, textures_t *textures);

void ken_walking_clean(textures_t *textures);

void ken_walking_textures(SDL_Renderer *renderer, textures_t *textures);

void ken_hit_clean(textures_t *textures);

void ken_hit_textures(SDL_Renderer *renderer, textures_t *textures);

void ken_hadouken_clean(textures_t *textures);

void ken_hadouken_textures(SDL_Renderer *renderer, textures_t *textures);

void ken_lpunch_clean(textures_t *textures);

void ken_lpunch_textures(textures_t *textures, SDL_Renderer *renderer);

void ken_crouch_lpunch_clean(textures_t *textures);

void ken_crouch_lpunch_textures(textures_t *textures, SDL_Renderer *renderer);

void ken_lkick_clean(textures_t *textures);

void ken_lkick_textures(textures_t *textures, SDL_Renderer *renderer);

void ken_victory_textures(SDL_Renderer *renderer,textures_t *textures);

void ken_victory_clean(textures_t *textures);

void clean_textures_ken(textures_t *textures);


void  init_textures_ken(SDL_Renderer *renderer, textures_t *textures);

#endif