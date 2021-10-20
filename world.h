#ifndef __WORLD__H__
#define __WORLD__H__


/**
* \brief Représentation des sprites .
*\param x abscisse du sprite
*\param y ordonnée du sprite
*\param w largueur du sprite
*\param h hauteur du sprite
*/

struct sprite_s { 
	int x;	/*!<Abscisse du sprite */
	int y;	/*!<Ordonnée du sprite */	
	int h;	/*!<Hauteur du sprite */	
	int w;	/*!<Largeur du sprite */
};
/**
* \brief Type qui correspond aux textures du sprite.
*/

typedef struct sprite_s sprite_t;


/**
 * \brief Représentation du monde du jeu
 * \param gameover Champ indiquant si l'on est à la fin du jeu
*/


struct world_s{
	sprite_t* sprite;	/*!<sprite devient un pointeur de sprite_t */
	sprite_t* projectile;	/*!<projectile devient un pointeur de sprite_t */
    int gameover;
	int mouvement;
};

/**
 * \brief Type qui correspond aux données du monde
 */

typedef struct world_s world_t;


/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */


void init_data(world_t * world);

/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */


void clean_data(world_t *world);
/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world);


/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param world données du monde
 */

void update_data(world_t *world);


/**
 * \brief Fonction qui empêche le perso de sortir de l'écran
 * \param world les données du monde
*/
 
void limite(world_t* world);


/**
*\brief  La fonction initialise le sprite avec les valeurs données en paramètres.
*\param sprite données du sprite
*\param x abscisse du sprite
*\param y ordonnée du sprite
*\param w largueur du sprite
*\param h hauteur du sprite
*/

void init_sprite(sprite_t* sprite, int x, int y, int w, int h);





#endif

