#include "mainPaku.h"
#include "character.h"
#define EMTSIZE  30

void pakumanChangeDirectionAI(character *c,int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX], Game g){
	// C'est à vous de proposer votre propre solution changement de direction intelligent !


	//on va rajouter des capteurs autour de notre perso pour pouvoir detecter les trucs autour de lui

	//on commence par prendre les coord du centre du paku
    int centre_x = (*c).p.x + (EMTSIZE / 2);
    int centre_y = (*c).p.y + (EMTSIZE / 2);

    //capteur de coord x , y en coord du repere
    int haut[2] = {centre_x / EMTSIZE, (centre_y - EMTSIZE)/ EMTSIZE};
    int bas[2] = {centre_x / EMTSIZE, (centre_y + EMTSIZE)/ EMTSIZE};
    int gauche[2] = {(centre_x - EMTSIZE) / EMTSIZE, centre_y/ EMTSIZE};
    int droite[2] = {(centre_x + EMTSIZE) / EMTSIZE, centre_y/ EMTSIZE};

    //check sur quelle case est le capteur








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
            (*c).direction = DOWN; //La detection des murs marchent.
        }
}

int main(int argc, char * argv[]){
    pakumanGo(&pakumanMoveAI);
    return 0;
}
