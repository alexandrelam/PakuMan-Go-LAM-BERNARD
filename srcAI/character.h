/*
 * character.h
 *
 *  Created on: 26 nov. 2018
 *      Author: José Mennesson
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

// Taille maximum de la map
#define MAP_WIDTH_MAX   100
#define MAP_HEIGHT_MAX  100

// Directions des personnages
#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

#define WALL 1

// Taille d'un élément (d'une case) du jeu
#define ELT_SIZE 30

/* Structure contenant une position x,y dans l'écran*/
struct PositionSt{
	int x,y;
};
typedef struct PositionSt Position;

/* Structure contenant les données d'un personnage du jeu*/
struct characterSt{
	Position p;						// Position du personnage dans l'écran
	int direction;					// Direction du personnage
	int size;						// Taille du personnage (les personnage sont carrés)
};
typedef struct characterSt character;

#endif /* CHARACTER_H_ */
