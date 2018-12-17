/*
 * character.h
 *
 *  Created on: 26 nov. 2018
 *      Author: José Mennesson
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "ressources.h"

//////////////////////////////////////////////////////////////////////////
/////           IL NE FAUT PAS MODIFIER CE FICHIER                  //////
//////////////////////////////////////////////////////////////////////////

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
