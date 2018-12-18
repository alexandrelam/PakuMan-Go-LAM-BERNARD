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
#include "character.h"

//////////////////////////////////////////////////////////////////////////
/////           IL FAUT MODIFIER CE FICHIER                         //////
//////////////////////////////////////////////////////////////////////////




int main(int argc, char** argv){

// Déclaration des variables
	int direction=RIGHT;
	SDL_Renderer *ren;
	SDL_Window   *win;
    int precTime = 0, currTime = 0, precTimeCherry = 0;
	int gameOver=0;
	int mapWidth=19;
	int mapHeight=21;
	Game g;
/*
    int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX]={
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
*/
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
    g.countdown = 120;
    g.score = 0;



	// Initialisation de la map du jeu
    g.myMap = initMAP( map, MAP_WIDTH_MAX, MAP_HEIGHT_MAX);

	// Initialisation du pakuman et des fantomes du jeu
    g.PakuMan = pakumanInit(PAKU_SPAWN, PAKU_SPAWN, direction, PAKU_SIZE);
    g.Ghost1 = ghostInit(GHOST_SPAWN_X, GHOST_SPAWN_Y, UP, GHOST_SIZE);
    g.Ghost2 = ghostInit(GHOST_SPAWN_X, GHOST_SPAWN_Y, UP, GHOST_SIZE);
    g.Ghost3 = ghostInit(GHOST_SPAWN_X, GHOST_SPAWN_Y, UP, GHOST_SIZE);
    g.Ghost4 = ghostInit(GHOST_SPAWN_X, GHOST_SPAWN_Y, UP, GHOST_SIZE);


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

        ghostMoveAleat(&g.Ghost1, g.myMap.map,MAP_WIDTH_MAX * ELT_SIZE,ELT_SIZE *MAP_HEIGHT_MAX);
        ghostMoveAleat(&g.Ghost2, g.myMap.map, MAP_WIDTH_MAX * ELT_SIZE,ELT_SIZE *MAP_HEIGHT_MAX);
        ghostMoveAleat(&g.Ghost3, g.myMap.map, MAP_WIDTH_MAX * ELT_SIZE,ELT_SIZE *MAP_HEIGHT_MAX);
        ghostMoveAleat(&g.Ghost4, g.myMap.map, MAP_WIDTH_MAX * ELT_SIZE,ELT_SIZE *MAP_HEIGHT_MAX);


        // Si c'est une Gum
                // on incrémente le nombre de points en conséquence
		// Si c'est une BigGum
                // on incrémente le nombre de points en conséquence
		// Si c'est une cerise
                // on incrémente le nombre de points en conséquence

        switch(pakumanEatSomething(g.PakuMan,g.myMap.map)){
            case 2:
                g.score += GUM_PTS;
                break;

            case 3:
                g.score += BIG_GUM_PTS;

                break;

            case 4:
                g.score += CHERRY_PTS;
                break;


        }

		// Si PakuMan meurt en rentrant en collision avec un des 4 fantomes,

        if(pakumanGhostCollision(g.PakuMan,g.Ghost1) || pakumanGhostCollision(g.PakuMan,g.Ghost2) ||pakumanGhostCollision(g.PakuMan,g.Ghost3) ||pakumanGhostCollision(g.PakuMan,g.Ghost4)){
            //on décrémente les vies du pakuman de 1
            g.life --;
            //on réinitialise le pakuMan et des fantomes
            g.PakuMan.p.x = PAKU_SPAWN;
            g.PakuMan.p.y = PAKU_SPAWN;
            g.PakuMan.direction = RIGHT;
            g.Ghost1.p.x = GHOST_SPAWN_X;
            g.Ghost1.p.y = GHOST_SPAWN_Y;
            g.Ghost2.p.x = GHOST_SPAWN_X;
            g.Ghost2.p.y = GHOST_SPAWN_Y;
            g.Ghost3.p.x = GHOST_SPAWN_X;
            g.Ghost3.p.y = GHOST_SPAWN_Y;
            g.Ghost4.p.x = GHOST_SPAWN_X;
            g.Ghost4.p.y = GHOST_SPAWN_Y;
        }


        // Si le temps écoulé est supérieur à 1 seconde (1000 millisecondes)
        if(currTime - precTime>=1000){

            //On décrémente le compte à rebours de 1
            g.countdown -= 1;
            //Le temps précédent devient le temps courant
            precTime = currTime;
        }


        // Toutes les 30 secondes, on met aléatoirement une cerise sur le plateau
        if(currTime - precTimeCherry>=30000){


            putRandomCherry(&g.myMap);

            precTimeCherry = currTime;
        }


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
        if ( g.countdown == 0 || g.life == 0){
                // c'est la fin du jeu
                gameOver=1;
        }
        // On fait une micro pause de 10 millisecondes
        pause(10);

	}

	// on affiche l'écran de fin de jeu
    displayEndPanel(g, ren);
	// On libère la mémoire et on ferme la bibliothèque graphique
	quitGame(&ren, &win);

	return 0;
}
