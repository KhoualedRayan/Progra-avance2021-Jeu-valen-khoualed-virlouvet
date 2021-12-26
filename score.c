#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "score.h"


Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}


void insertion(Liste *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}
void actualiserListe(Liste *liste, SDL_Renderer *renderer, world_t *world,textures_t *textures)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;
    while (actuel != NULL)
    {   int a;
        for(int i=0;i<5;i++){

            if(actuel->nombre >= world->tab[i] ){
                a=i;
                i=6;
            }
        }
        for(int y=4;y>a;y--){
            world->tab[y]=world->tab[y-1];
        }
        world->tab[a]=actuel->nombre;

        actuel = actuel->suivant;
    }

}

void tableau_des_scores(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    
    sprintf(world->text_score, "SCORES :");
    apply_text(renderer, 100 ,300,100,50,world->text_score,textures->font);
    for(int i=0; i<5; i++){
        sprintf(world->text_score, "%d-     %d",i+1,world->tab[i]);
        apply_text(renderer,100,360 + 60 *i, 100, 50, world->text_score,textures->font);
    }
    

}


void scores(world_t *world, Liste *maListe, SDL_Renderer *renderer,textures_t *textures){

    suppression(maListe);
    if(world->ryu_pv > 0){
        insertion(maListe, world->time*5 + world->ryu_pv*10);
    }else{
    }
    
}

