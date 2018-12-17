/*
 * game.h
 *
 *  Created on: 26 nov. 2018
 *      Author: José Mennesson
 */

#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include <SDL2/SDL.h>
// Inclusion des headers
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "ressources.h"
#include "texture.h"
#include "map.h"

// Déclaration de la structure contenant les paramètres du jeu, la map, le pakuman et les 4 fantomes
struct GameSt{
	int screenWidth;	// La largeur de l'écran
	int screenHeight;	// La hauteur de l'écran
	int countdown;		// Le compte à rebours avant la fin du jeu
	int score;			// Le score
	int life;			// Le nombre de vies
	character PakuMan;	// le pakuman
	character Ghost1;	// Le fantome 1
	character Ghost2;	// Le fantome 2
	character Ghost3;	// Le fantome 3
	character Ghost4;	// Le fantome 4
	Map myMap;			// La map
};
typedef struct GameSt Game;

/**
* Initialise le jeu, l'état du rendu graphique, la fenetre
* @param ren Un pointeur vers le pointeur sur une structure contenant l'état du rendu
* @param win Un pointeur vers le pointeur sur une structure contenant l'état du fenetre
* @param La largeur de la map
* @param La heuteur de la map
* @return Une structure de jeu
*/
Game init_game(SDL_Renderer **ren, SDL_Window   **win, int mapWidth, int mapHeight);

/**
* Gère le clavier et la souris.
* @param pdirection un pointeur vers la nouvelle direction correspondant à la touche du clavier pressée
* @param pbool Un pointeur vers un booléen qui devient vrai si un clic droit a été effectué
*/
void processKeyboardNMouse(int *pdirection, int *pbool);
/**
* Permet de faire une pause bloquante. Attends que l'utilisateur tape sur la touche Enter
*/
void pauseBloquante();
/**
* Récupère le temps en millisecondes depuis le démarrage du programme
* @return le temps en millisecondes depuis le démarrage du programme
*/
int getCurrentTimeMilliSec();

/**
* Affiche le panneau des scores en bas de l'écran
* @param g Le jeu
* @param ren Un pointeur sur une structure contenant l'état du rendu
*/
void addScorePanelToRenderer(Game g, SDL_Renderer *ren);
/**
* Affiche l'écran de Game Over et fait une pause
* @param g Le jeu
* @param ren Un pointeur sur une structure contenant l'état du rendu
*/
void displayEndPanel(Game g, SDL_Renderer *ren);
/**
* Affiche l'écran de démarrage du jeu et fait une pause
* @param g Le jeu
* @param ren Un pointeur sur une structure contenant l'état du rendu
*/
void displayStartPanel(Game g, SDL_Renderer *ren);


/* Ferme la bibliothèque graphique et supprime l'espace mémoire alloué pour les textures, la fenetre et le rendu
 * @param ren Un pointeur vers le pointeur sur une structure contenant l'état du rendu
 * @param win Un pointeur vers le pointeur sur une structure contenant l'état du fenetre
 */
void quitGame(SDL_Renderer **ren, SDL_Window   **win);

/**
* Permet de faire une pause de quelques millisecondes
*/
void pause(int timeInMillisec);

#endif /* GAME_H_ */
