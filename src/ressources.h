/*
 * ressources.h
 *
 *  Created on: 26 nov. 2018
 *      Author: José Mennesson
 */

 #define TIMEBEFOREQUIT 60000

#ifndef RESSOURCES_H_
#define RESSOURCES_H_

// Taille d'un élément (d'une case) du jeu
#define ELT_SIZE 30

// Taille maximum de la map
#define MAP_WIDTH_MAX   100
#define MAP_HEIGHT_MAX  100

// Taille des personnages
#define PAKU_SIZE ELT_SIZE-10
#define GHOST_SIZE ELT_SIZE

// Nombre de fantomes
#define NB_GHOST 4

// Elements de la map
#define EMPTY 0
#define WALL 1
#define GUM 2
#define BIG_GUM 3
#define CHERRY 4

// Points correspondants aux gums, big gums et cherrys
#define GUM_PTS 10
#define BIG_GUM_PTS 50
#define CHERRY_PTS	100

// Directions des personnages
#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

// Temps limite pour faire le maximum de points
#define DEADLINE 120

// Nombre de vies
#define LIFE 3


#endif /* RESSOURCES_H_ */
