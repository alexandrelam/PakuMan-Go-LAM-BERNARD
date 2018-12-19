#include "mainPaku.h"
#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define EMTSIZE  30

int detectionCapteur(int capteur[], int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]){
    int detectedNode = map[capteur[1]][capteur[0]];
    if(detectedNode > 1){
        return 1;
    }
    else{
        return 0;
    }
}

int collisionPoint(int px,int py,int rx, int ry, int width,int height){
    if ((px >= rx) && (px <= width) && (py >= ry) && (py <= height)) {
        return 1;
    }
    else{
        return 0;
    }

}
int capteurFantomes(int capteur[], character fantomes){
    //pass
    int x = fantomes.p.x;
    int y = fantomes.p.y;
    int width = x + EMTSIZE;
    int height = y + EMTSIZE;

    if(collisionPoint(capteur[0],capteur[1],x,y,width,height)){
        return 1;
    }
    else{
        return 0;
    }
}

int noWallCollisionCapteur(int capteur[], int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]){
    if(map[capteur[1]/EMTSIZE][capteur[0]/EMTSIZE] != 1){
        return 1;
    }
    else{
        return 0;
    }
}
void pakumanChangeDirectionAIGhost(character *c,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX], Game g){

    int px = (*c).p.x;
    int py = (*c).p.y;

    int centre_x = px + (EMTSIZE / 2);
    int centre_y = py + (EMTSIZE / 2);

    int hautf[2] = {centre_x, (centre_y - EMTSIZE)};
    int basf[2] = {centre_x , (centre_y + EMTSIZE)};
    int gauchef[2] = {(centre_x - EMTSIZE) , centre_y};
    int droitef[2] = {(centre_x + EMTSIZE) , centre_y};

    if(capteurFantomes(hautf, g.Ghost1) || capteurFantomes(hautf, g.Ghost2) ||capteurFantomes(hautf, g.Ghost3) ||capteurFantomes(hautf, g.Ghost4)){
        if(noWallCollisionCapteur(basf, map)){
            (*c).direction = DOWN;
        }
        else if(noWallCollisionCapteur(gauchef, map)){
            (*c).direction = LEFT;
        }
        else if(noWallCollisionCapteur(droitef, map)){
            (*c).direction = RIGHT;
        }
        printf("Ghost : ^\n");
    }
    else if(capteurFantomes(basf, g.Ghost1) || capteurFantomes(basf, g.Ghost2) ||capteurFantomes(basf, g.Ghost3) ||capteurFantomes(basf, g.Ghost4)){
        if(noWallCollisionCapteur(hautf, map)){
            (*c).direction = UP;
        }
        else if(noWallCollisionCapteur(gauchef, map)){
            (*c).direction = LEFT;
        }
        else if(noWallCollisionCapteur(droitef, map)){
            (*c).direction = RIGHT;
        }
        printf("Ghost : v\n");
    }
    else if(capteurFantomes(gauchef, g.Ghost1) || capteurFantomes(gauchef, g.Ghost2) ||capteurFantomes(gauchef, g.Ghost3) ||capteurFantomes(gauchef, g.Ghost4)){
        if(noWallCollisionCapteur(basf, map)){
            (*c).direction = DOWN;
        }
        else if(noWallCollisionCapteur(hautf, map)){
            (*c).direction = UP;
        }
        else if(noWallCollisionCapteur(droitef, map)){
            (*c).direction = RIGHT;
        }
        printf("Ghost : <\n");
    }
    else if(capteurFantomes(droitef, g.Ghost1) || capteurFantomes(droitef, g.Ghost2) ||capteurFantomes(droitef, g.Ghost3) ||capteurFantomes(droitef, g.Ghost4)){
        if(noWallCollisionCapteur(basf, map)){
            (*c).direction = DOWN;
        }
        else if(noWallCollisionCapteur(gauchef, map)){
            (*c).direction = LEFT;
        }
        else if(noWallCollisionCapteur(hautf, map)){
            (*c).direction = UP;
        }
        printf("Ghost : >\n");
    }
    // !! safe way == retourner dans la direction opposée

    }

void pakumanChangeDirectionAIWall(character *c,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX], Game g){
	// C'est à vous de proposer votre propre solution changement de direction intelligent !


	//on va rajouter des capteurs autour de notre perso pour pouvoir detecter les trucs autour de lui

	//on commence par prendre les coord du centre du paku
    int centre_x = (*c).p.x + (EMTSIZE / 2);
    int centre_y = (*c).p.y + (EMTSIZE / 2);

    //capteur de coord x , y en coord du repere pour les gums
    int haut[2] = {centre_x / EMTSIZE, (centre_y - EMTSIZE)/ EMTSIZE};
    int bas[2] = {centre_x / EMTSIZE, (centre_y + EMTSIZE)/ EMTSIZE};
    int gauche[2] = {(centre_x - EMTSIZE) / EMTSIZE, centre_y/ EMTSIZE};
    int droite[2] = {(centre_x + EMTSIZE) / EMTSIZE, centre_y/ EMTSIZE};

    int hautf[2] = {centre_x, (centre_y - EMTSIZE)};
    int basf[2] = {centre_x , (centre_y + EMTSIZE)};
    int gauchef[2] = {(centre_x - EMTSIZE) , centre_y};
    int droitef[2] = {(centre_x + EMTSIZE) , centre_y};

    printf("haut : %d\n",detectionCapteur(haut,map));
    printf("bas : %d\n",detectionCapteur(bas,map));
    printf("droite : %d\n",detectionCapteur(droite,map));
    printf("gauche : %d\n",detectionCapteur(gauche,map));
    printf("\n\n");

    /*
    printf("hautf : %d %d %d %d\n",capteurFantomes(hautf, g.Ghost1),capteurFantomes(hautf, g.Ghost2),capteurFantomes(hautf, g.Ghost3),capteurFantomes(hautf, g.Ghost4));
    printf("basf : %d %d %d %d\n",capteurFantomes(basf, g.Ghost1),capteurFantomes(basf, g.Ghost2),capteurFantomes(basf, g.Ghost3),capteurFantomes(basf, g.Ghost4));
    printf("droitef : %d %d %d %d\n",capteurFantomes(droitef, g.Ghost1),capteurFantomes(droitef, g.Ghost2),capteurFantomes(droitef, g.Ghost3),capteurFantomes(droitef, g.Ghost4));
    printf("gauchef : %d %d %d %d\n",capteurFantomes(gauchef, g.Ghost1),capteurFantomes(gauchef, g.Ghost2),capteurFantomes(gauchef, g.Ghost3),capteurFantomes(gauchef, g.Ghost4));
    printf("\n\n");
    */

    //check sur quelle case est le capteur
    if(detectionCapteur(bas,map)){
        (*c).direction = DOWN;
    }
    else if(g.score < 700)
    {
        if(detectionCapteur(droite,map)){
            (*c).direction = RIGHT;
        }
        else if(detectionCapteur(gauche,map)){
            (*c).direction = LEFT;
        }
        else if(detectionCapteur(haut,map)){
        (*c).direction = UP;
        }
        else{
            (*c).direction = rand() % 4;
        }
    }

    else if(g.score > 700){
        if(detectionCapteur(gauche,map)){
            (*c).direction = LEFT;
        }
        else if(detectionCapteur(droite,map)){
            (*c).direction = RIGHT;
        }
        else if(detectionCapteur(haut,map)){
        (*c).direction = UP;
        }
        else{
            (*c).direction = rand() % 4;
        }

}
}

void pakumanMoveAI(character *c, int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX], int screenWidth, int screenHeight, Game g){
	// C'est à vous de proposer votre propre solution de déplacement de pakuman intelligent

	//si le pakuman touche un mur il faut changer sa direction.
        int newX, newY;
		// Initialisation des nouvelles coordonnées (newX,newY) en fonction des coordonnées du pakuman
        newX = (*c).p.x;
        newY = (*c).p.y;

		// Affectation de la nouvelle direction à la direction du pakuman
        int newDirection = (*c).direction;

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
        if (pakumanWallCollisionNewPos(newX,newY,(*c).size,map) == 0){
                    // on affecte les nouvelles coordonnées (newX, newY) au pakuman
                (*c).p.x = newX;
                (*c).p.y = newY;
        }else if(pakumanWallCollisionNewPos(newX,newY,(*c).size,map) == 1){
            pakumanChangeDirectionAIWall(c,map,g); //La detection des murs marchent.
        }
        pakumanChangeDirectionAIGhost(c,map,g);
}

int main(int argc, char * argv[]){
    pakumanGo(&pakumanMoveAI);
    return 0;
}
