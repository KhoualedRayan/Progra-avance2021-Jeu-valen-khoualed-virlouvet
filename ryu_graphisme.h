#ifndef __RYU_GRAPHISME__H__
#define __RYU_GRAPHISME__H__

#include "graphisme.h"
#include "world.h"
#include "constante.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "animations.h"

void ryu_idle_clean(textures_t *textures, SDL_Renderer *renderer);

void ryu_idle_textures(textures_t *textures, SDL_Renderer *renderer);

void ryu_walking_clean(textures_t *textures);

void ryu_walking_textures(textures_t *textures, SDL_Renderer *renderer);

void ryu_hadouken_clean(textures_t *textures);

void ryu_hadouken_textures(textures_t *textures, SDL_Renderer *renderer);

void ryu_hit_clean(textures_t *textures);

void ryu_hit_textures(textures_t *textures, SDL_Renderer *renderer);

void ryu_jump_clean(textures_t *textures);

void ryu_jump_textures(textures_t *textures, SDL_Renderer *renderer);

void ryu_lpunch_clean(textures_t *textures);

void ryu_lpunch_textures(textures_t *textures, SDL_Renderer *renderer);

void ryu_crouch_lpunch_clean(textures_t *textures);

void ryu_crouch_lpunch_textures(textures_t *textures, SDL_Renderer *renderer);

void ryu_forward_lpunch_clean(textures_t *textures);

void ryu_forward_lpunch_textures(textures_t *textures, SDL_Renderer *renderer);

void ryu_lkick_clean(textures_t *textures);

void ryu_lkick_textures(textures_t *textures, SDL_Renderer *renderer);

void clean_texture_ryu(textures_t *textures);

void  init_textures_ryu(SDL_Renderer *renderer, textures_t *textures);

#endif