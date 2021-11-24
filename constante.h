#ifndef __CONSTANTE__H__
#define __CONSTANTE__H__

/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 1280

/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 900

/**
 * \brief Largeur du titre principal
 */
#define TITLE_WIDTH 1000

/**
 * \brief Hauteur du titre principal
 */
#define TITLE_HEIGHT 300

/**
 * \brief Largeur des sprites boutons du menu principal
 */
#define BOUTON_WIDTH 300

/**
 * \brief Hauteur des sprites boutons du menu principal
 */
#define BOUTON_HEIGHT 50

/**
 * \brief Taille d'un perso
 */

#define VERTICAL_SIZE 361

/**
 * \brief Taille d'un perso
 */

#define HORIZONTAL_SIZE 220


/**
 * \brief Taille d'un projectile
 */

#define PROJECTILE_SIZE 64


/**
 * \brief Pas de déplacement horizontal 
*/

#define MOVING_STEP 10


/**
  * \brief Vitesse initiale de déplacement vertical des éléments du jeu 
*/

#define INITIAL_SPEED 3
// constante pour world->state
#define REST 0
#define REST_KEN 0
#define FALL 1
#define JUMP 2
#define HADOUKEN 3
#define HADOUKEN_KEN 33
#define CROUCH 4
#define RISE 5
#define ATTACK 6
#define ATTACKED 7

//constate pour world->typeOfAttack

#define LKICK 51
#define LPUNCH 52
#define CROUCH_LPUNCH 53


#endif
