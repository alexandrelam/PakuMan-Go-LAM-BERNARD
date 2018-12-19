/*
 * character.h
 *
 *  Created on: 26 nov. 2018
 *      Author: José Mennesson
 */

#ifndef PAKUMAN_H_
#define PAKUMAN_H_


#include <math.h>
#include <stdlib.h>
#include "ressources.h"
#include "character.h"


/**
* Initialise le pakuman en position x,y dans le repère écran
* @param x La coordonnée x
* @param y La coordonnée y
* @param direction La direction du pakuman (RIGHT,UP,LEFT,DOWN)
* @param size la taille du pakuman (size x size)
* @return Un pakuman
*/
character pakumanInit(int x, int y, int direction, int size);


/**
* Récupère les coordonnées de la case du tableau correspondant aux coordonnées (x,y) dans le repère écran
* @param x Une coordonnée x dans le repère écran
* @param y Une coordonnée y dans le repère écran
* @param mapX Une coordonnée x dans le repère de la map
* @param mapY Une coordonnée y dans le repère de la map
*/
void pakumanGetArrayCoord(int x, int y,int *mapX, int* mapY);

/**
* Modifie les coordonnées et la direction du pakuman en fonction de la direction donnée en paramètre
* @param pc Un pointeur vers le pakuman
* @param map La carte du jeu
* @param newDirection La nouvelle direction du pakuman
* @param screenWidth  La largeur de l'écran
* @param screenHeight La hauteur de l'écran
*/
void pakumanMove(character *pc, int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX], int newDirection, int screenWidth, int screenHeight);

/**
* Teste si le pakuman entre en collision avec un fantome
* @param Pakuman Le pakuman
* @param Ghost Un fantome
* @return Un booleen indiquant s'il y a une collision (vrai) ou non (faux) avec un fantome
*/
int pakumanGhostCollision(character pakuman,character Ghost);
/**
* Teste si le pakuman entre en collision avec un fantome dans le repère écran
* @param x La coordonnée x du pakuman dans le repère écran
* @param y La coordonnée y du pakuman dans le repère écran
* @param size La taille du pakuman
* @param map La carte du jeu
* @return Un booleen indiquant s'il y a une collision (vrai) ou non (faux) avec un mur
*/
int pakumanWallCollisionNewPos(int x, int y,int size,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]);
/**
* Teste si le pakuman mange quelque chose sur sa position et retourne la chose mangée
* @param c Le pakuman
* @param map La carte du jeu
* @return La chose qui a été mangée (GUM, BIG_GUM, CHERRY)
*/
int pakumanEatSomething(character c,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]);



#endif /* PAKUMAN_H_ */
