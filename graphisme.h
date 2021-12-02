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
    SDL_Texture* background2; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* background3; /*!< Texture liée à l'image du fond de l'écran. */


    //Ryu_idle
    SDL_Texture* ryu_idle; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_idle1; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_idle2; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_idle3; /*!<Texture liée à l'image du perso. */

    SDL_Texture* ryu_hit;
    SDL_Texture* ryu_hit1;
    SDL_Texture* ryu_hit2;
    SDL_Texture* ryu_hit3;

    //Ryu_walking
    SDL_Texture* ryu_walking; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_walking1; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_walking2; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_walking3; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_walking4; /*!<Texture liée à l'image du perso. */

    //Ryu blocking
    SDL_Texture* ryu_blocking; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_blocking1; /*!<Texture liée à l'image du perso. */

    //Ryu crouching
    SDL_Texture* ryu_crouching; /*!<Texture liée à l'image du perso. */

    //Ryu_hadouken
    SDL_Texture* ryu_hadouken; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_hadouken1; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_hadouken2; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_hadouken3; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_hadouken4; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_hadouken5; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_hadouken6; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_hadouken7; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_hadouken8; /*!<Texture liée à l'image du perso. */

    //Ryu_jumping
    SDL_Texture* ryu_jumping; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_jumping1; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_jumping2; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_jumping3; /*!<Texture liée à l'image du perso. */

    //Ryu_falling
    SDL_Texture* ryu_falling; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_falling1; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_falling2; /*!<Texture liée à l'image du perso. */

    //Ryu_l-punch
    SDL_Texture* ryu_lpunch; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_lpunch1; /*!<Texture liée à l'image du perso. */

    //Ryu_l-kick
    SDL_Texture* ryu_lkick; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_lkick1; /*!<Texture liée à l'image du perso. */

    //Ryu_crouch_lpunch
    SDL_Texture* ryu_crouch_lpunch; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_crouch_lpunch2; /*!<Texture liée à l'image du perso. */

    //Ryu_forward_lpunch
    SDL_Texture* ryu_forward_lpunch; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ryu_forward_lpunch1; /*!<Texture liée à l'image du perso. */

    //Ryu hp barre
    SDL_Texture* ryu_hp;
    SDL_Texture* ryu_hp_fill;

    //Ryu victory pose
    SDL_Texture* ryu_victory;
    SDL_Texture* ryu_victory1;
    SDL_Texture* ryu_victory2;

    SDL_Texture* ryu_ko;
    SDL_Texture* ryu_ko1;
    SDL_Texture* ryu_ko2;




    //Ken
    SDL_Texture* characTwo ;

    //Ken hp barre
    SDL_Texture* ken_hp;
    SDL_Texture* ken_hp_fill;

    //Ken_idle
    SDL_Texture* ken_idle ;
    SDL_Texture* ken_idle1 ;
    SDL_Texture* ken_idle2 ;
    SDL_Texture* ken_idle3 ;
    
    //ken_walking
    SDL_Texture* ken_walking;
    SDL_Texture* ken_walking1;
    SDL_Texture* ken_walking2;
    SDL_Texture* ken_walking3;
    SDL_Texture* ken_walking4;

    //ken_hadouken
    SDL_Texture* ken_hadouken; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ken_hadouken1; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ken_hadouken2; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ken_hadouken3; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ken_hadouken4; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ken_hadouken5; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ken_hadouken6; /*!<Texture liée à l'image du perso. */


    //ken_hit
    SDL_Texture* ken_hit;
    SDL_Texture* ken_hit1;
    SDL_Texture* ken_hit2;
    SDL_Texture* ken_hit3;

    //KEn_l-punch
    SDL_Texture* ken_lpunch; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ken_lpunch1; /*!<Texture liée à l'image du perso. */

    //ken_l-kick
    SDL_Texture* ken_lkick; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ken_lkick1; /*!<Texture liée à l'image du perso. */

    //ken_crouch_lpunch
    SDL_Texture* ken_crouch_lpunch; /*!<Texture liée à l'image du perso. */
    SDL_Texture* ken_crouch_lpunch2; /*!<Texture liée à l'image du perso. */

    //ken victory pose
    SDL_Texture* ken_victory;
    SDL_Texture* ken_victory1;
    SDL_Texture* ken_victory2;

    //menu
    //ken qui perd
    SDL_Texture* ken_Ko;
    SDL_Texture* ken_Ko1;
    SDL_Texture* ken_Ko2;

    SDL_Texture* hadouken; /*!<Texture liée à l'image d'un tir de projectile' */
	TTF_Font* font; /*!<Police utilisée pour l'affichage */
    SDL_Texture* menu_1; /*!<Texture liée à l'image du fond du menu principal */
    SDL_Texture* titre_p; /*!<Texture liée au titre du menu principal */
    SDL_Texture* exit_normal; /*!<Texture liée au titre du bouton exit */
    SDL_Texture* exit_select; /*!<Texture liée au titre du bouton exit */
    SDL_Texture* pvp_normal; /*!<Texture liée au titre du bouton pvp */
    SDL_Texture* pvp_select; /*!<Texture liée au titre du bouton pvp */
    SDL_Texture* pvb_normal; /*!<Texture liée au titre du bouton pvb */
    SDL_Texture* pvb_select; /*!<Texture liée au titre du bouton pvb */

    //menu des maps
    SDL_Texture* flecheg;
    SDL_Texture* fleched;
    SDL_Texture* map1min;
    SDL_Texture* map2min;
    SDL_Texture* map3min;

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


void  init_textures_ken(SDL_Renderer *renderer, textures_t *textures);

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
 * \brief La fonction rafraichit le menu en fonction de l'état des données du monde
 * \param renderer le renderer lié à l'écran de jeu
 * \param world les données du monde
 * \param textures les textures
 */

void refresh_graphics_menu(SDL_Renderer *renderer, world_t *world,textures_t *textures);
void refresh_graphics_choix_maps(SDL_Renderer *renderer, world_t *world,textures_t *textures);

/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param texture la texture liée au fond
*/

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);



#endif
