#ifndef _PLATEAU_H_
#define _PLATEAU_H_

/*std lib*/
#include <stdio.h>
#include <stdlib.h>

/*Macro*/
#define LARGEUR_P 10
#define LONGUEUR_P 22

/*local lib*/
#include "plateau.h"

/*Structure Plateau*/
typedef struct{
  int plateau[LONGUEUR_P][LARGEUR_P]; /*réprésentation du plateau si case = 1 il y a une pièces sinon case =0 */
  int gameover; /*0 si la partie continue  1 si la partie est terminé*/
  
}plateau;

int gameIsOver(plateau* p);

int lineIsFull(plateau* p, int n);

#endif /*_PLATEAU_H_*/
