/*
 * map.c
 *
 *  Created on: 26 nov. 2018
 *      Author: José Mennesson
 */

#include "map.h"
#include <time.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
/////           IL FAUT MODIFIER CE FICHIER                         //////
//////////////////////////////////////////////////////////////////////////

Map initMAP(int map[MAP_HEIGHT_MAX][MAP_WIDTH_MAX],int mapWidth, int mapHeight){
	// Déclaration de la structure Map
    Map m;
	// Initialisation de la largeur et de la hauteur de la map
    m.width = mapWidth;
    m.height = mapHeight;

	// Parcours du tableau map donnée en paramètre et copie dans la map de la structure Map
    int i,j;
    for(i = 0; i < MAP_WIDTH_MAX; i++){
        for(j = 0 ; j < MAP_HEIGHT_MAX; j++){
            m.map[j][i] = map[j][i];
        }
    }

	return m;
}



void putRandomCherry(Map *m){
	// Initialisation aléatoire de la cerise
	int test = 0;
	int posx,posy;
	while(test == 0){
        srand(time(NULL));
        posx = rand() % ((*m).width-1);
        posy = rand() % ((*m).height-1);
        if((*m).map[posx][posy] != 1){
            test = 1;
        }
	}
	// Tant que l'on est sur un mur
    // On défini de nouvelles coordonnées pour la cerise
	// Enfin, on met une cerise dans la map aux coordonnées calculées précédemment
    (*m).map[posx][posy] = CHERRY;
}
