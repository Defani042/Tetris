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
  /*on vérifie que le nombre de case est égale à la largeur du plateau*/
  /*si oui = 1 sinon = 0 */
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

/*
R: netoyage d' une ligne n (toutes les case de ligne[n] passe à 0 )
E: 1 Plateau et 1 entier (numéro de la ligne)
S: vide
*/

void clearLine(plateau *p, int n){
  int i;
  /*on parcourps la ligne n*/
  for(i=0;i<LARGEUR_P;i++){
    p->plateau[n-1][i] = 0;
  }

}

/*
R: parcourps toute les ligne du tableau pour vérifier si elle sont remplie
E: 1 Plateau
S: 1 entier (nb ligne qui ont été clear)
*/


int checkPlateauState(plateau* p){
  int i,nb_line= 0;
  /*on parcourps toute les lignes du plateau*/
  for(i=0;i < LONGUEUR_P ;i++){
    /*si une ligne est remplie*/
    if(lineIsFull(p,i)){
      clearLine(p,i); /*on la remet à zero*/
      nb_line++; /*incrémentation de la variable nb_line*/ 
    }
    
  }
  return nb_line;
}

/*
R: fonction Test pour remplir une ligne du plateau à 1
E: 1 Plateau et 1 entier le numéro de la ligne 
S: vide 
*/

void filledline(plateau *p, int n){
  int i;
  /*on parcourps la ligne n*/
  for(i=0;i<LARGEUR_P;i++){
    p->plateau[n-1][i] = 1;
  }

}

#endif /*_PLATEAU_C_*/
