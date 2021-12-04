#ifndef __SCORE__H__
#define __SCORE__H__

#include "world.h"
#include "graphisme.h"
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "constante.h"


// typedef struct Element Element;
// struct Element
// {
//     int nombre;
//     Element *suivant;
// };

// typedef struct Liste Liste;
// struct Liste
// {
//     Element *premier;
// };
// Liste *initialisation();


void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste, SDL_Renderer *renderer, world_t *world,textures_t *textures);
void scores(world_t *world, Liste *maListe, SDL_Renderer *renderer,textures_t *textures);
void tableau_des_scores(SDL_Renderer *renderer, world_t *world,textures_t *textures);

#endif
