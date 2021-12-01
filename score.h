#ifndef __SCORE__H__
#define __SCORE__H__

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);
//void scores();

#endif
