/*
 * main.c
 *
 *  Created on: 26 nov. 2018
 *      Author: Jos� Mennesson
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

	// D�claration des variables
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

    int durationSinceStart = 0;

	//////////////////////////////////// INITIALISATION
	// Initialisation du jeu
    g = init_game(&ren, &win, mapWidth, mapHeight);

	// Initialisation de la map du jeu
    g.myMap = initMAP( map, MAP_WIDTH_MAX, MAP_HEIGHT_MAX);

	// Initialisation du pakuman et des fantomes du jeu
    g.PakuMan = pakumanInit(ELT_SIZE, ELT_SIZE, direction, PAKU_SIZE);

	// Affichage de l'�cran de d�marrage du jeu
	displayStartPanel( g, ren);


	//////////////////////////////////// DEBUT DU JEU
	while (!gameOver){
		// R�cup�rer le nombre de millisecondes depuis le lancement du programme dans le temps courant
        durationSinceStart = getCurrentTimeMilliSec();
		// R�cup�rer les actions de la souris et du clavier pour changer la direction du pacman
        processKeyboardNMouse(g.PakuMan.direction,0);

		// D�placement des personnages pr�sents dans le jeu g suivant leur nouvelle direction


		// On r�cup�re la chose mang�e �ventuellement par le pakuman

		// Si c'est une Gum

                // on incr�mente le nombre de points en cons�quence

		// Si c'est une BigGum

                // on incr�mente le nombre de points en cons�quence

		// Si c'est une cerise

                // on incr�mente le nombre de points en cons�quence

		// Si PakuMan meurt en rentrant en collision avec un des 4 fantomes,

			//on d�cr�mente les vies du pakuman de 1

			//on r�initialise le pakuMan et des fantomes


		// Si le temps �coul� est sup�rieur � 1 seconde (1000 millisecondes)

			//On d�cr�mente le compte � rebours de 1

			//Le temps pr�c�dent devient le temps courant

			// Toutes les 30 secondes, on met al�atoirement une cerise sur le plateau



		//	vide le contenu du rendu
        clearRenderer(ren);
		// Mettre le panneau des scores dans le rendu

		// Mettre la map dans le rendu
        addMapToRenderer(g.myMap, ren);
		// Mettre les personnages dans le rendu
        addPakumanToRenderer(g.PakuMan, ren);

		//On met � jour l'affichage � partir du rendu
        updateDisplay(ren);
		// Si le temps est �coul� ou si le nombre de vies de PakuMan est �gal � 0

		//test fin de jeu
        if(durationSinceStart > TIMEBEFOREQUIT){
            quitGame(&ren, &win);
        }

                // c'est la fin du jeu


		// On fait une micro pause de 10 millisecondes

	}

	// on affiche l'�cran de fin de jeu

	// On lib�re la m�moire et on ferme la biblioth�que graphique


	return 0;
}
