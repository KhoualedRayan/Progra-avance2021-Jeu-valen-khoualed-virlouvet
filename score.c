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
int count = 0;
void afficherListe(Liste *liste, SDL_Renderer *renderer, world_t *world,textures_t *textures)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;
    sprintf(world->text_score, "SCORES :");
    apply_text(renderer, 100 ,300,100,50,world->text_score,textures->font);
    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        count++;
        for(int i = 0; i< count; i++){
            if(actuel->nombre > world->tab[i]){
                for(int j = 5; j >0; j--){
                    if(world->tab[j]< world->tab[j-1]){
                        world->tab[j] = world->tab[j-1];
                    }
                }
                world->tab[i] = actuel->nombre;
            }
        }
        
        for(int i=0; i<5; i++){
            sprintf(world->text_score, "%d-     %d",i+1,world->tab[i]);
            apply_text(renderer,100,360 + 60 *i, 100, 50, world->text_score,textures->font);
        }


        actuel = actuel->suivant;
    }

    
    
}

void tableau_des_scores(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    sprintf(world->text_score, "SCORES :");
    apply_text(renderer, 100 ,300,100,50,world->text_score,textures->font);
    for(int i=1; i<5;i++){
        sprintf(world->text_score, "%d",world->time);
        apply_text(renderer, 100 ,300 + i*50,100,50,world->text_score,textures->font);
    }

}


void scores(world_t *world, Liste *maListe, SDL_Renderer *renderer,textures_t *textures){

    suppression(maListe);
    if(world->ryu_pv > 0){
        insertion(maListe, world->time*5 + world->ryu_pv*10);
    }else{
        //insertion(maListe, 0);
    }
    //afficherListe(maListe,renderer,world,textures);
    
}

