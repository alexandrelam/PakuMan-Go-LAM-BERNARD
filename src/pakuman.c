/*
 * character.c
 *
 *  Created on: 26 nov. 2018
 *      Author: José Mennesson
 */

#include "pakuman.h"


//////////////////////////////////////////////////////////////////////////
/////           IL FAUT MODIFIER CE FICHIER                         //////
//////////////////////////////////////////////////////////////////////////

character pakumanInit(int x, int y, int direction,int size){
	// Création du personnage
	character c;
	// Initialisation du personnage
	c.p.x = x;
	c.p.y = y;
	c.direction = direction;
	c.size = size;

	return c;
}

void pakumanGetArrayCoord(int x, int y,int *mapX, int* mapY){
    // conversion des coordonnées (x,y) en repère écran en coordonnées (mapX, mapY) en repère map

    *mapX = x / ELT_SIZE;
    *mapY = y / ELT_SIZE;


}
int pakumanWallCollisionNewPos( int x, int y,int size,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]){
	int mapXmin, mapYmin, mapXmax, mapYmax;
	// Récupération des coordonnées (mapXmin, mapYmin) de la map correspondant au coin Haut-Gauche du pakuman en utilisant les coordonnées (x,y) du pakuman dans le repère écran

	// Récupération des coordonnées (mapXmax, mapYmax) de la map correspondant au coin Bas-Droit du pakuman en utilisant les coordonnées (x,y) du pakuman dans le repère écran et la taille du pakuman

	// Teste si les coins Haut-Gauche, Haut-Droit, Bas-Gauche et Bas-Droit sont dans une case de mur
    return 0;
}

void pakumanMove(character *c, int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX], int newDirection,int screenWidth,int screenHeight){
		int newX, newY;
		// Initialisation des nouvelles coordonnées (newX,newY) en fonction des coordonnées du pakuman
        newX = *c.p.x;
        newY = *c.p.y;

		// Affectation de la nouvelle direction à la direction du pakuman
        newDirection = *c.direction;

		// Si la direction est DROITE et si le pakuman ne sort pas de l'écran,
        if (newDirection == RIGHT && newX > 0 && newX < MAP_WIDTH_MAX){
                // on incrémente newX
                newX ++;
        }
		// Même principe pour la GAUCHE
        if (newDirection == LEFT && newX > 0 && newX < MAP_WIDTH_MAX){
                // on incrémente newX
                newX -= 1;
        }
		// Même principe pour le BAS
        if (newDirection == DOWN && newY > 0 && newY < MAP_HEIGHT_MAX){
                // on incrémente newX
                newY ++;
        }
		// Même principe pour le HAUT
        if (newDirection == UP && newY > 0 && newY < MAP_HEIGHT_MAX){
                // on incrémente newX
                newX -= 1;
        }
		// Si la nouvelle position n'entre pas en collision avec un mur

                    // on affecte les nouvelles coordonnées (newX, newY) au pakuman

}

void pakumanChangeDirectionAI(character *c,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]){
	// C'est à vous de proposer votre propre solution changement de direction intelligent !

}

void pakumanMoveAI(character *c, int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX], int screenWidth, int screenHeight){
	// C'est à vous de proposer votre propre solution de déplacement de pakuman intelligent

}

int pakumanGhostCollision(character PakuMan,character Ghost){
	// Le pakuman et le fantome sont contenus dans deux rectangles. Si ces rectangles se chevauchent

		// on retourne vrai

	// sinon

		// on retourne faux

	return 0;
}

int pakumanEatSomething(character c,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]){
	int mapXmin, mapYmin, mapXmax, mapYmax;
	int food=0;
	// Récupération des coordonnées (mapXmin, mapYmin) de la map correspondant au coin Haut-Gauche du pakuman en utilisant les coordonnées (x,y) du pakuman dans le repère écran

	// Récupération des coordonnées (mapXmax, mapYmax) de la map correspondant au coin Bas-Droit du pakuman en utilisant les coordonnées (x,y) du pakuman dans le repère écran et la taille du pakuman

	// Si le coins Haut-Gauche n'est ni dans une case de mur, ni une case vide

            // On récupère ce qu'il y a dans la case

            // On "vide" la case (élément EMPTY)

	// Idem pour le coins Bas-Droit

	// Idem pour le coins Haut-Droit

	// Idem pour le coins Bas-Gauche n'est ni dans une case de mur, ni une case vide

	return food;
}


