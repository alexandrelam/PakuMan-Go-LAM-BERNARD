/*
 * map.h
 *
 *  Created on: 26 nov. 2018
 *      Author: mennesson
 */

#ifndef MAP_H_
#define MAP_H_

#include <SDL2/SDL.h>
#include <stdlib.h>
#include "ressources.h"

// La structure de Map contenant la map et les dimensions de la map
struct MapSt{
	int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX];	// la map
	int width;								// la largeur de la map
	int height;								// la hauteur de la map
};
typedef struct MapSt Map;

/* Initialise une structure Map à partir d'une de map donnée en paramètre et initialise la lageur et la hauteur de la map
 * @param map Un tableau d'entiers à deux dimensions représentant la map
 * @param mapWidth La largeur de la map
 * @param mapHeight La hauteur de la map
 * @return une structure de Map
 */
Map initMAP(int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX],int mapWidth, int mapHeight);

/* Place une cerise de manière aléatoire dans la map. Elle ne doit pas apparaître dans un mur.
 * @param un pointeur vers une structure Map m
 */
void putRandomCherry(Map *m);

#endif /* MAP_H_ */
