#ifndef _PLATEAU_H_
#define _PLATEAU_H_

/*std lib*/
#include <stdio.h>
#include <stdlib.h>

/*Macro*/
#define LARGEUR_P 10
#define LONGUEUR_P 22

/*local lib*/
#include "piece.h"

/*Structure Plateau*/
typedef struct{
  int plateau[LONGUEUR_P][LARGEUR_P]; /*réprésentation du plateau si case = 1 il y a une pièces sinon case =0 */
  int gameover;     /*0 si la partie continue  1 si la partie est terminé*/
  tabpiece tpiece;  /*tableau de pièce*/
  piece p_cur;      /*piece qu'on est entrain de jouer*/
  piece p_next;     /*piece qui viens ensuite */
  int score;        /*score du tetris*/
  int speed;        /*vitesse des piéces*/
}plateau;

int gameIsOver(plateau* p);

int lineIsFull(plateau* p, int n);

void setPlateau(plateau *p);

void printPlateau(plateau *p);

void clearLine(plateau *p, int n);

int checkPlateauState(plateau* p);

void filledline(plateau *p, int n);

void gapline(plateau *p);

void setcase(plateau *p , int n , int m, int value);

int lineIsEmpty(plateau* p, int n);

int canPlacePiece(plateau *plat, piece *p);

void Plateaucpy(plateau *p1,plateau *p2);

void integratePiece(plateau *plat);

int descendPiece(plateau *plat);

void generateNewPiece(plateau *plat);

void increaseScore(plateau *p);

void increaseSpeed(plateau *p);

#endif /*_PLATEAU_H_*/
