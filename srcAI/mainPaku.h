/*
 * main.h
 *
 *  Created on: 13 déc. 2018
 *      Author: mennesson
 */


#ifndef SRC_MAINPAKU_H_
#define SRC_MAINPAKU_H_

#include "character.h"
#include "game.h"

int pakumanGo(void (*pakumanAI)(character*, int [MAP_HEIGHT_MAX][MAP_WIDTH_MAX], int, int,Game));

#endif /* SRC_MAINPAKU_H_ */
