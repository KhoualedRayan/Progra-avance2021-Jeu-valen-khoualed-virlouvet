#ifndef __GRAPHISME__H__
#define __GRAPHISME__H__
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "world.h"

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* charac; /*!<Texture liée à l'image du perso. */
    SDL_Texture* characTwo ;
	SDL_Texture* tir; /*!<Texture liée à l'image d'un tir de projectile' */
    SDL_Texture* hadouken; /*!<Texture liée à l'image d'un tir de projectile' */
	TTF_Font* font; /*!<Police utilisée pour l'affichage */
    SDL_Texture* menu_1; /*!<Texture liée à l'image du fond du menu principal */
    SDL_Texture* titre_p; /*!<Texture liée au titre du menu principal */
};

/**
 * \brief Type qui correspond aux textures du jeu
*/

typedef struct textures_s textures_t;


/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/

void clean_textures(textures_t *textures);

/**
 * \brief La fonction initialise les textures nécessaires à l'affichage graphique du jeu
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void init_textures(SDL_Renderer *renderer, textures_t *textures);

/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param texture la texture liée au fond
*/

void apply_background(SDL_Renderer *renderer, SDL_Texture *texture);


/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer le renderer lié à l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures); //graphique



/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param texture la texture liée au fond
*/

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);



#endif
