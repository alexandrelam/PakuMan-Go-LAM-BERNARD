/*
 * character.h
 *
 *  Created on: 26 nov. 2018
 *      Author: José Mennesson
 */

#ifndef GHOST_H_
#define GHOST_H_

#include "texture.h"
#include "ressources.h"
#include "character.h"
/**
* Initialise le fantome en position x,y dans le repère écran
* @param x La coordonnée x dans le repère écran
* @param y La coordonnée y dans le repère écran
* @param direction La direction du fantome (RIGHT,UP,LEFT,DOWN)
* @param Size la taille du fantome (Size x Size)
* @return Un fantome
*/
character ghostInit(int x, int y, int direction,int size);
/**
* Affiche le fantome
* @param c Le fantome
* @param ren Un pointeur vers une structure qui contient l'état du rendu graphique
* @param ghostNumber Le numéro du fantome (entre 1 et 4)
*/
void addGhostToRenderer(character c, int ghostNumber, SDL_Renderer *ren);

/**
* Change aléatoirement la direction du fantome
* @param pc Un pointeur vers le fantome
* @param map La carte du jeu
*/
void ghostChangeDirection(character *pc,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]);

/**
* Modifie les coordonnées et la direction du fantome aléatoirement
* @param pc Un pointeur vers le fantome
* @param map La carte du jeu
* @param screenWidth La largeur de l'écran
* @param screenHeight La hauteur de l'écran
*/
void ghostMoveAleat(character *pc, int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX], int screenWidth, int screenHeight);

/**
* Test si les nouvelles coordonnées (newX,newY) du fantome dans le repère écran entrent en collision avec un mur.
* Pour cela, on doit tester si les coins (haut,gauche) et (haut,droit) du fantome sont dans une case de la map contenant un mur.
* @param newX La possible nouvelle coordonnée x du fantome
* @param newY La possible nouvelle coordonnée y du fantome
* @param size La taille du fantome
* @param map  La map
*/
int ghostWallCollisionNewPos(int newX, int newY,int size,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]);

/**
* Récupère les coordonnées de la case du tableau correspondant aux coordonnées (x,y) dans le repère écran
* @param x Une coordonnée x dans le repère écran
* @param y Une coordonnée y dans le repère écran
* @param mapX Une coordonnée x dans le repère de la map
* @param mapY Une coordonnée y dans le repère de la map
*/
void ghostGetArrayCoord(int x, int y,int *mapX, int* mapY);

#endif /* GHOST_H_ */
