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
	sprite_t* spriteAttack;  /*sprite qui attack*/
	sprite_t* spriteTwo;
	sprite_t* menu;		/*!<menu devient un pointeur de sprite_t */
	sprite_t* titre;	/*!<titre devient un pointeur de sprite_t */
	sprite_t* exit;	/*!<exit devient un pointeur de sprite_t */
	sprite_t* exit2;	/*!<exit2 devient un pointeur de sprite_t */
	sprite_t* playervsplayer;	/*!<playervsplayer devient un pointeur de sprite_t */
	sprite_t* playervsplayer2;	/*!<playervsplayer2 devient un pointeur de sprite_t */
	sprite_t* playervsbot;	/*!<playervsbot devient un pointeur de sprite_t */
	sprite_t* playervsbot2;	/*!<playervsbot2 devient un pointeur de sprite_t */
	sprite_t* ryu_hp_barre;
	sprite_t* ken_hp_barre;
	sprite_t ryu_hp[20];
	sprite_t ken_hp[20];
	int ryu_pv;
	int ken_pv;
	int hitted;
	int stun;
	int addw;
	int addh;
	float compteur;
	float compteur_menu;
	int gameover;
	int defeat_or_win;
	int etat_menu;
	int mouvement;
	int mouvement2;
	int test;
	int on;
	int nbr_hadouken; 
	float timerLastAttack; // temps depuis la derniere attaque.
	int timerlastshoot ; //temps depuis le dernier hadouken 
	int firerate ; //temps entre chaque hadouken
	char* text;
	sprite_t hadouken[10] ;
	sprite_t hadouken_ken[10];
	int vy;
	int crouch;
	int state;
	int state_ken;
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
void gravity(world_t *world);
void attack(world_t *world);




/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param world données du monde
 */

void update_data(world_t *world);

void update_hadouken(sprite_t *hadouken, world_t *world);

int sprites_collide(sprite_t *sp1, sprite_t *sp2);

void handle_sprites_collision_hadoken(sprite_t *sp1, sprite_t *sp2, world_t *world);

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
void init_hadouken(world_t* world);
void init_pv(world_t* world);
void receive_damage(world_t *world);



#endif

