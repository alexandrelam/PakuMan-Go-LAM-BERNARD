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
    mapXmin = x / ELT_SIZE;
    mapYmin = y / ELT_SIZE;
	// Récupération des coordonnées (mapXmax, mapYmax) de la map correspondant au coin Bas-Droit du pakuman en utilisant les coordonnées (x,y) du pakuman dans le repère écran et la taille du pakuman
    mapXmax = (x + PAKU_SIZE)/ELT_SIZE;
    mapYmax = (y + PAKU_SIZE)/ELT_SIZE;
	// Teste si les coins Haut-Gauche, Haut-Droit, Bas-Gauche et Bas-Droit sont dans une case de mur
	if (map[mapYmin][mapXmin]==1)
        return 0;
    if (map[mapYmin][mapXmax]==1)
        return 0;
    if (map[mapYmax][mapXmin]==1)
        return 0;
    if (map[mapYmax][mapXmax]==1)
        return 0;
    else {
        return 1;
    }
}

void pakumanMove(character *c, int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX], int newDirection,int screenWidth,int screenHeight){
		int newX, newY;
		// Initialisation des nouvelles coordonnées (newX,newY) en fonction des coordonnées du pakuman
        newX = (*c).p.x;
        newY = (*c).p.y;

		// Affectation de la nouvelle direction à la direction du pakuman
        (*c).direction = newDirection;

		// Si la direction est DROITE et si le pakuman ne sort pas de l'écran,
        if ((newDirection == RIGHT) && (newX < screenWidth)){
                // on incrémente newX
                newX ++;
        }
		// Même principe pour la GAUCHE
        if (newDirection == LEFT && newX > 0 ){
                // on incrémente newX
                newX --;
        }
		// Même principe pour le BAS
        if (newDirection == DOWN && newY < screenHeight){
                // on incrémente newX
                newY ++;
        }
		// Même principe pour le HAUT
        if (newDirection == UP && newY > 0){
                // on incrémente newX
                newY --;
        }
		// Si la nouvelle position n'entre pas en collision avec un mur
        if (pakumanWallCollisionNewPos(newX,newY,(*c).size,map) == 1){
                    // on affecte les nouvelles coordonnées (newX, newY) au pakuman
                (*c).p.x = newX;
                (*c).p.y = newY;
        }

}

void pakumanChangeDirectionAI(character *c,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]){
	// C'est à vous de proposer votre propre solution changement de direction intelligent !

}

void pakumanMoveAI(character *c, int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX], int screenWidth, int screenHeight){
	// C'est à vous de proposer votre propre solution de déplacement de pakuman intelligent

}

int pakumanGhostCollision(character PakuMan,character Ghost){

	// Le pakuman et le fantome sont contenus dans deux rectangles. Si ces rectangles se chevauchent
    if ((PakuMan.p.x < Ghost.p.x + GHOST_SIZE) &&
   PakuMan.p.x + PAKU_SIZE > Ghost.p.x &&
   PakuMan.p.y < Ghost.p.y + GHOST_SIZE &&
   PakuMan.p.y + PAKU_SIZE > Ghost.p.y) {
    // collision détectée !
        return 1;
    }
    else{
        return 0;
    }
		// on retourne vrai

	// sinon

		// on retourne faux
}

int pakumanEatSomething(character c,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]){
	int mapXmin, mapYmin, mapXmax, mapYmax;
	int food=0;
	// Récupération des coordonnées (mapXmin, mapYmin) de la map correspondant au coin Haut-Gauche du pakuman en utilisant les coordonnées (x,y) du pakuman dans le repère écran
    mapXmin = c.p.x / ELT_SIZE;
    mapYmin = c.p.y / ELT_SIZE;
	// Récupération des coordonnées (mapXmax, mapYmax) de la map correspondant au coin Bas-Droit du pakuman en utilisant les coordonnées (x,y) du pakuman dans le repère écran et la taille du pakuman
    mapXmax = (c.p.x + PAKU_SIZE)/ELT_SIZE;
    mapYmax = (c.p.y + PAKU_SIZE)/ELT_SIZE;
	// Si le coins Haut-Gauche n'est ni dans une case de mur, ni une case vide
    if (map[mapYmin][mapXmin]!=0 && map[mapYmin][mapXmin]!=1){
            // On récupère ce qu'il y a dans la case
            food = map[mapYmin][mapXmin];
            // On "vide" la case (élément EMPTY)
            map[mapYmin][mapXmin]=0;
    }
	// Idem pour le coins Bas-Droit
    if (map[mapYmax][mapXmax]!=0 && map[mapYmax][mapXmax]!=1){
        food = map[mapYmax][mapXmax];
        map[mapYmax][mapXmax] = 0;
    }

	// Idem pour le coins Haut-Droit
    if (map[mapYmin][mapXmax]!=0 && map[mapYmin][mapXmax]!=1){
        food = map[mapYmin][mapXmax];
        map[mapYmin][mapXmax] = 0;
    }
	// Idem pour le coins Bas-Gauche n'est ni dans une case de mur, ni une case vide
    if (map[mapYmax][mapXmin]!=0 && map[mapYmax][mapXmin]!=1){
        food = map[mapYmax][mapXmin];
        map[mapYmax][mapXmin] = 0;
    }
	return food;
}


