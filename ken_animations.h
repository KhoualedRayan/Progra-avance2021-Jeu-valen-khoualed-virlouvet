#ifndef __KEN_ANIMATIONS__H__
#define __KEN_ANIMATIONS__H__

void refresh_animations_ken(world_t* world,SDL_Renderer *renderer,textures_t *textures);

void ken_hidle(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ken_walking(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ken_hadouken(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ken_hit(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ken_hp(SDL_Renderer *renderer, world_t *world,textures_t *textures);

#endif