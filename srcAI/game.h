/*
 * game.h
 *
 *  Created on: 26 nov. 2018
 *      Author: José Mennesson
 */

#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <SDL2/SDL.h>
// Inclusion des headers
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

// Déclaration de la structure contenant les paramètres du jeu, la map, le pakuman et les 4 fantomes
struct GameSt{
	int screenWidth;	// La largeur de l'écran
	int screenHeight;	// La hauteur de l'écran
	int countdown;		// Le compte à rebours avant la fin du jeu
	int score;			// Le score
	int life;			// Le nombre de vies
	character PakuMan;	// le pakuman
	character Ghost1;	// Le fantome 1
	character Ghost2;	// Le fantome 2
	character Ghost3;	// Le fantome 3
	character Ghost4;	// Le fantome 4
	Map myMap;			// La map
};
typedef struct GameSt Game;

#endif /* GAME_H_ */
