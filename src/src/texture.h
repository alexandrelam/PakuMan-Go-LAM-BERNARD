/*
 * win.hpp
 *
 *  Created on: 26 sept. 2017
 *      Author: José Mennesson
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "ressources.h"
#include "character.h"
#include "map.h"
#include "game.h"

#define NB_TEX 4

#define pakumanTexpath  "res/pakuman"
#define ghost1Texpath  "res/ghost1"
#define ghost2Texpath  "res/ghost2"
#define ghost3Texpath  "res/ghost3"
#define ghost4Texpath  "res/ghost4"
#define imagePathWall  "res/wall.bmp"
#define cherryPath  "res/cherry.bmp"
#define gumPath  "res/gum.bmp"
#define bigGumPath  "res/bigGum.bmp"
#define fontPath "res/DejaVuSans-Bold.ttf"

SDL_Texture  *pakumanTex[NB_TEX];
SDL_Texture  *ghostsTex[NB_GHOST][NB_TEX];
SDL_Texture  *wallTexture;
SDL_Texture  *cherryTexture;
SDL_Texture  *gumTexture;
SDL_Texture  *bigGumTexture;

TTF_Font* Sans;
SDL_Color Yellow;

/**
* Charge une texture dans le rendu graphique
* @param file Le chemin vers la texture
* @param ren Un pointeur vers la structure contenant le rendu
*/
SDL_Texture* loadTexture(const char* file, SDL_Renderer *ren);
/**
* Met la texture de la map dans le rendu graphique à une position (x,y) dans le repère écran avec une taille de size
* @param tex La texture à mettre dans le rendu
* @param ren Un pointeur vers la structure contenant le rendu
* @param mapX La coordonnée X dans le repère map
* @param mapY La coordonnée Y dans le repère map
* @param size La taille de la texture sur l'écran
*/
void renderMapTexture(SDL_Texture *tex, SDL_Renderer *ren, int mapX, int mapY, int size);
/**
* Met la texture d'un personnage dans le rendu graphique à une position (x,y) dans le repère écran avec une taille de size
* @param tex La texture à mettre dans le rendu
* @param ren Un pointeur vers la structure contenant le rendu
* @param x La coordonnée x dans le repère écran
* @param y La coordonnée y dans le repère écran
* @param size La taille de la texture sur l'écran
*/
void renderCharacterTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int size);

/**
* Charge les 4 textures (Droite, Haut, Gauche, Bas) d'un personnage
* @param Texpath Le chemin vers les images des textures à charger
* @param Tex Un tableau de pointeurs de textures d'un personnage
* @param ren un pointeur vers une structure qui contient l'état du rendu graphique
*/
void characLoadTex(const char *Texpath,SDL_Texture *Tex[NB_TEX], SDL_Renderer *ren);

/**
* Met dans le rendu graphique un texte à la position (x,y) dans le repère écran avec une taille de (hsize x wsize)
* @param x La coordonnée x dans le repère écran
* @param y La coordonnée y dans le repère écran
* @param wsize La largeur du message sur l'écran
* @param hsize La hauteur du message sur l'écran
* @param ren un pointeur vers une structure qui contient l'état du rendu graphique
*/
void printText(int x,int y,char *texte, int wsize, int hsize, SDL_Renderer *ren);

/* Met le pakuman dans le rendu graphique
 * @param c Le pakuman
 * @param ren un pointeur vers une structure qui contient l'état du rendu graphique
 */
void addPakumanToRenderer(character c, SDL_Renderer *ren);

/* Met le fantome numéro ghostNumber dans le rendu graphique
 * @param c Un fantome
 * @param ghostNumber Le numéro du fantome
 * @param ren un pointeur vers une structure qui contient l'état du rendu graphique
 */
void addGhostToRenderer(character c, int ghostNumber, SDL_Renderer *ren);

/* Met la map dans le rendu graphique
 * @param m une structure Map
 * @param ren un pointeur vers une structure qui contient l'état du rendu graphique
 */
void addMapToRenderer(Map m, SDL_Renderer *ren);

/**
* Met à jour l'affichage de l'écran
* @param ren Un pointeur sur une structure contenant l'état du rendu
*/
void updateDisplay(SDL_Renderer *ren);

/* Vide le rendu graphique
 * @param ren Un pointeur sur une structure contenant l'état du rendu
 */
void clearRenderer(SDL_Renderer *ren);

#endif /* WIN_HPP_ */
