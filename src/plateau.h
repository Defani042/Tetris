#ifndef _PLATEAU_H_
#define _PLATEAU_H_

/*std lib*/
#include <stdio.h>
#include <stdlib.h>

/*Macro*/
#define LARGEUR_P 10
#define LONGUEUR_P 22


/*Structure Plateau*/
typedef struct{
  int plateau[LONGUEUR_P][LARGEUR_P]; /*réprésentation du plateau si case = 1 il y a une pièces sinon case =0 */
  int gameover; /*0 si la partie continue  1 si la partie est terminé*/
  int score;
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

#endif /*_PLATEAU_H_*/
