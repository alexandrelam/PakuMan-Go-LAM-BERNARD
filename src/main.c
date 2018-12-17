/*
 * main.c
 *
 *  Created on: 26 nov. 2018
 *      Author: José Mennesson
 */
#include <stdio.h>
#include "ressources.h"
#include "game.h"
#include "ghost.h"
#include "pakuman.h"

//////////////////////////////////////////////////////////////////////////
/////           IL FAUT MODIFIER CE FICHIER                         //////
//////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv){

	// Déclaration des variables
	int direction=RIGHT;
	SDL_Renderer *ren;
	SDL_Window   *win;
    int precTime = 0, currTime = 0;
	int gameOver=0;
	int mapWidth=19;
	int mapHeight=21;
	Game g;
	int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]={
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1},
				{1,2,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,2,1},
				{1,3,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,3,1},
				{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
				{1,2,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,2,1},
				{1,2,2,2,2,1,3,2,2,1,2,2,3,1,2,2,2,2,1},
				{1,1,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,1,1},
				{1,1,1,1,2,1,0,0,0,0,0,0,0,1,2,1,1,1,1},
				{1,1,1,1,2,1,0,1,1,0,1,1,0,1,2,1,1,1,1},
				{1,1,1,1,2,2,0,1,0,0,0,1,0,2,2,1,1,1,1},
				{1,1,1,1,2,1,0,1,1,1,1,1,0,1,2,1,1,1,1},
				{1,1,1,1,2,1,0,0,0,0,0,0,0,1,2,1,1,1,1},
				{1,1,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,1,1},
				{1,2,2,2,2,1,3,2,2,1,2,2,3,1,2,2,2,2,1},
				{1,2,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,2,1},
				{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
				{1,3,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,3,1},
				{1,2,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,2,1},
				{1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};


	//////////////////////////////////// INITIALISATION
	// Initialisation du jeu
    g = init_game(&ren, &win, mapWidth, mapHeight);
    g.countdown = DEADLINE;
    g.score = 0;


	// Initialisation de la map du jeu
    g.myMap = initMAP( map, MAP_WIDTH_MAX, MAP_HEIGHT_MAX);

	// Initialisation du pakuman et des fantomes du jeu
    g.PakuMan = pakumanInit(ELT_SIZE +5, ELT_SIZE + 5, direction, PAKU_SIZE);
    g.Ghost1 = ghostInit(270, 300, UP, GHOST_SIZE);
    g.Ghost2 = ghostInit(270, 300, DOWN, GHOST_SIZE);
    g.Ghost3 = ghostInit(270, 300, RIGHT, GHOST_SIZE);
    g.Ghost4 = ghostInit(270, 300, LEFT, GHOST_SIZE);


	// Affichage de l'écran de démarrage du jeu
	displayStartPanel( g, ren);


	//////////////////////////////////// DEBUT DU JEU
	while (!gameOver){
		// Récupérer le nombre de millisecondes depuis le lancement du programme dans le temps courant
        currTime = getCurrentTimeMilliSec();
		// Récupérer les actions de la souris et du clavier pour changer la direction du pacman
        processKeyboardNMouse(&g.PakuMan.direction,0);

		// Déplacement des personnages présents dans le jeu g suivant leur nouvelle direction
        pakumanMove(&g.PakuMan, g.myMap.map, g.PakuMan.direction , MAP_WIDTH_MAX * ELT_SIZE , ELT_SIZE *MAP_HEIGHT_MAX);
        ghostMoveAleat(&g.Ghost1, g.myMap.map, MAP_WIDTH_MAX,MAP_HEIGHT_MAX);
        ghostMoveAleat(&g.Ghost2, g.myMap.map, MAP_WIDTH_MAX,MAP_HEIGHT_MAX);
        ghostMoveAleat(&g.Ghost3, g.myMap.map, MAP_WIDTH_MAX,MAP_HEIGHT_MAX);
        ghostMoveAleat(&g.Ghost4, g.myMap.map, MAP_WIDTH_MAX,MAP_HEIGHT_MAX);
        if (pakumanEatSomething(g.PakuMan,g.myMap.map)==1){
                // on incrémente le nombre de points en conséquence
                g.score += GUM_PTS;
        }

		// Si c'est une BigGum
        if (pakumanEatSomething(g.PakuMan,g.myMap.map)==2){
                // on incrémente le nombre de points en conséquence
                g.score += BIG_GUM_PTS;
        }
		// Si c'est une cerise
		if (pakumanEatSomething(g.PakuMan,g.myMap.map)==3){

                // on incrémente le nombre de points en conséquence
                g.score += CHERRY_PTS;
		}


		// Si PakuMan meurt en rentrant en collision avec un des 4 fantomes,

			//on décrémente les vies du pakuman de 1

			//on réinitialise le pakuMan et des fantomes


		// Si le temps écoulé est supérieur à 1 seconde (1000 millisecondes)
        if(currTime - precTime>=1000){
			//On décrémente le compte à rebours de 1
            g.countdown -= 1;
			//Le temps précédent devient le temps courant
            precTime = currTime;
	}
			// Toutes les 30 secondes, on met aléatoirement une cerise sur le plateau


		// On récupére la chose mangée éventuellement par le pakuman

		// Si c'est une Gum



		//	vide le contenu du rendu
        clearRenderer(ren);
		// Mettre le panneau des scores dans le rendu
        addScorePanelToRenderer(g, ren);
		// Mettre la map dans le rendu
        addMapToRenderer(g.myMap, ren);
		// Mettre les personnages dans le rendu
        addPakumanToRenderer(g.PakuMan, ren);
        addGhostToRenderer(g.Ghost1, 1, ren);
        addGhostToRenderer(g.Ghost2, 2, ren);
        addGhostToRenderer(g.Ghost3, 3, ren);
        addGhostToRenderer(g.Ghost4, 4, ren);



		//On met à jour l'affichage à partir du rendu
        updateDisplay(ren);
		// Si le temps est écoulé ou si le nombre de vies de PakuMan est égal à 0

		//test fin de jeu
        if(currTime > TIMEBEFOREQUIT){
            quitGame(&ren, &win);
        }

                // c'est la fin du jeu


		// On fait une micro pause de 10 millisecondes

	}

	// on affiche l'écran de fin de jeu

	// On libère la mémoire et on ferme la bibliothèque graphique


	return 0;
}
