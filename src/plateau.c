#ifendef _PLATEAU_C_
#define _PLATEAU_C_

/*std lib*/
#include <stdio.h>
#include <stdlib.h>

/*Macro*/
#define LARGEUR_P 10
#define LONGUEUR_P 22

/*local lib*/
#include "plateau.h"

/*
R: déterminer si la partie est finie renvoi 1 si partie fini sinon 0
E: 1 structure plateau
S: 1 entier (1 si la partie est terminé) (0 si la partie est en cours)
*/

int gameIsOver(plateau p){
  int i;
  for(i=0;i<LARGEUR_P;i++){
    if(p[LONGUEUR][i] == 1){
      return 1;
    }
  }
  return 0;

}

/*
R: vérifie si une ligne est complète 
E: 1 plateau et 1 entier (le numéro de la ligne)
S: 1 entier (1 si la ligne est complète)(sinon 0)
*/


int lineIsFull(plateau p, int n){
  

}
#endif /*_PLATEAU_C_*/
