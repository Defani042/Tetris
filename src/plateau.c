#ifndef _PLATEAU_C_
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

int gameIsOver(plateau* p){
  int i;
  /*on regarde toutes les case de la denière ligne du plateau*/
  for(i=0;i<LARGEUR_P;i++){
    /*si une case = 1 game over*/
    if(p->plateau[LONGUEUR_P -1][i] == 1){
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


int lineIsFull(plateau* p, int n){
  int i, casefull = 0;
  /*on regarde si les cases de la ligne n sont égale à 1*/
  for(i=0;i<LARGEUR_P;i++){
    /*récupération du nombre de case = 1*/
    if(p->plateau[n-1][i]){
      casefull++;
    }
    
  }
  if( casefull == LARGEUR_P){
    return 1;
  }
  return 0;
}

/*
R: permet d'initialiser les case du plateau (elle permet de faire une remise à zero du plateau)
E: 1 Plateau 
S: vide  
*/

void setPlateau(plateau *p){
  int i,j;
  /*on parcourps le plateau de jeux */
  for(i=0;i < LONGUEUR_P ;i++){
    for(j=0;j < LARGEUR_P ;j++){
      /*on met la case à l'indice i,j à 0 */
      p->plateau[i][j] = 0;
    }
  }
  p->gameover = 0; /* on met la variable gameover à 0 */
}

/*
R: afficher le plateau dans le terminal
E: 1 Plateau
S: vide 
*/
void printPlateau(plateau *p){
  int i,j;
  /*on parcourps le tableau et on afiche la case indince i,j*/
  /*on parcourps le tableau à l'envers sur les lignes pour que la case 2 soit la seconde en partant du bas du tableau*/
  for(i=LONGUEUR_P-1;i>=0;i--){
    for(j=0;j<LARGEUR_P;j++){
      printf(" %d",p->plateau[i][j]);
    }
    printf("\n");
  }
} 


#endif /*_PLATEAU_C_*/
