#ifndef __ANIMATIONS__H__
#define __ANIMATIONS__H__

void refresh_animations(world_t* world,SDL_Renderer *renderer,textures_t *textures);
void timer(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ryu_hidle(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ryu_walking(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ryu_blocking(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ryu_crouching(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ryu_hadouken(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ryu_jumping(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ryu_falling(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void ken_hidle(SDL_Renderer *renderer, world_t *world,textures_t *textures);



#endif
