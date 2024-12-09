#ifndef _PLATEAU_H_
#define _PLATEAU_H_

/*std lib*/
#include <stdio.h>
#include <stdlib.h>

/*Macro*/
#define LARGEUR_P 14
#define LONGUEUR_P 26

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
  int temps_jeu; /*temps passé en jeu*/
}plateau;

int gameIsOver(plateau* p);

int lineIsFull(plateau* p, int n);

void setPlateau(plateau *p);

void printPlateau(plateau *p);

void clearLine(plateau *p, int n);

int checkPlateauState(plateau* p);

void filledline(plateau *p, int n);

void gapline(plateau *p,int n);

void setcase(plateau *p , int n , int m, int value);

int lineIsEmpty(plateau* p, int n);

int canPlacePiece(plateau *plat, piece *p);

void Plateaucpy(plateau *p1,plateau *p2);

void integratePiece(plateau *plat);

int descendPiece(plateau *plat);

void generateNewPiece(plateau *plat);

void updateScore(plateau* p, int linesCleared);

void increaseSpeed(plateau *p);

void supprPiece(plateau *p);

void movepiece(plateau *p, char c);

void rotateCurrentPiece(plateau *plat, int direction);

#endif /*_PLATEAU_H_*/
