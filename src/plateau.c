#ifndef _PLATEAU_C_
#define _PLATEAU_C_

/*std lib*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>/*permet de faire des sleep*/


/*local lib*/
#include "plateau.h"
#include "piece.h"

/*
R: déterminer si la partie est finie renvoi 1 si partie fini sinon 0
E: 1  pointeur structure plateau
S: 1 entier (1 si la partie est terminé) (0 si la partie est en cours)
*/

int gameIsOver(plateau* p){
  int i;
  /*on regarde toutes les case de la denière ligne du plateau*/
  for(i=2;i<LARGEUR_P-2;i++){
    /*si une case = 1 game over*/
    if(p->plateau[0][i] == 1){
      return 1;
    }
  }
  return 0;

}

/*
R: vérifie si une ligne est complète (que des 1)
E: 1 pointeur plateau et 1 entier (le numéro de la ligne)
S: 1 entier (1 si la ligne est complète)(sinon 0)
*/


int lineIsFull(plateau* p, int n){
  int i, casefull = 0;
  /*on regarde si les cases de la ligne n sont égale à 1*/
  for(i=2;i<LARGEUR_P-2;i++){
    /*récupération du nombre de case pleinne*/
    if(p->plateau[n][i] != 0){
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
      if (i < 2 || i >= LONGUEUR_P - 2 || j < 2 || j >= LARGEUR_P - 2) {
	p->plateau[i][j] = 9; /* Bordure*/
            } else {
	p->plateau[i][j] = 0; /* Espace de jeu */
            }
    }
  }
  setTabpiece(p->tpiece); /*set le plateau de piece*/
  p->gameover = 0; /* on met la variable gameover à 0 */
  setTabpiece(p->tpiece); /*on créait le tableau de piece*/
  p->score = 0; /*le score est à 0 de base*/
  p->speed = 1; /*speed est à 1*/
  piececpy(&(p->p_cur),&(p->tpiece[SelectPiece()])); /*piece courente séléctionner aléatoirement*/
  piececpy(&(p->p_next),&(p->tpiece[SelectPiece()])); /*piece suivante courente séléctionner aléatoirement*/
}

/*
R: afficher le plateau dans le terminal
E: 1  pointeur Plateau
S: vide 
*/

void printPlateau(plateau *p){
  int i,j;
  /*on parcourps le tableau et on afiche la case indince i,j*/
  /*on parcourps le tableau à l'envers sur les lignes pour que la case 2 soit la seconde en partant du bas du tableau*/
  for(i=0;i<LONGUEUR_P;i++){
    for(j=0;j<LARGEUR_P;j++){
      printf(" %d",p->plateau[i][j]);
    }
    printf("\n");
  }
}

/*
R: netoyage d' une ligne n (toutes les case de ligne[n] passe à 0 )
E: 1  pointeur Plateau et 1 entier (numéro de la ligne)
S: vide
*/

void clearLine(plateau *p, int n){
  int i;
  /*on parcourps la ligne n*/
  for(i=2;i<LARGEUR_P-2;i++){
    p->plateau[n][i] = 0;
  }

}

/*
R: parcourps toute les ligne du tableau pour vérifier si elle sont remplie
E: 1  pointeur Plateau
S: 1 entier (nb ligne qui ont été clear)
*/


int checkPlateauState(plateau* p){
  int i,nb_line= 0;
  /*on parcourps toute les lignes du plateau*/
  for(i=LONGUEUR_P-1;i >= 0;i--){
    /*si une ligne est remplie*/
    if(lineIsFull(p,i)){
      clearLine(p,i); /*on la remet à zero*/
      nb_line++; /*incrémentation de la variable nb_line*/ 
    }
    
  }
  gapline(p);
  return nb_line;
}

/*
R: fonction Test pour remplir une ligne du plateau à 1
E: 1 pointeur Plateau et 1 entier le numéro de la ligne 
S: vide 
*/

void filledline(plateau *p, int n){
  int i;
  /*on parcourps la ligne n*/
  for(i=2;i<LARGEUR_P-2;i++){
    p->plateau[n-1][i] = 1;
  }

}

/*
R: fonction qui permet de décaller une ligne du plateau
E: 1 pointeur Plateau 
S: vide
*/

void gapline(plateau *p) {
  int i,j,dec=0;
  for(i=2;i<LONGUEUR_P-2;i++){
    if(lineIsEmpty(p,i)){
      dec++;
    }
    else if (dec > 0) {
      for(j=0;j<LARGEUR_P;j++){
	p->plateau[i-dec][j] = 	p->plateau[i][j];	
      }
      clearLine(p,i);
    }
  }    
}
/*
R: Fonction permettant d'insérer une valeur dans une case d'indice n,m
E: 1 pointeur plateau et 3 entiers (n et m indice de la case dans le plateau) (valeur de la case) 
S: vide
*/  

void setcase(plateau *p, int n , int m, int value){
  if(n > LONGUEUR_P || m > LARGEUR_P){
    printf("erreur n doit >= %d et m doit >= %d <\n",LONGUEUR_P,LARGEUR_P);
  }
  if(value == 0 || value == 1 ){
    p->plateau[n-1][m-1] = value;
  }
  else{
    printf("valeur hors champs le plateau n'accepte que 1 ou 0\n");
  }
}

/*
R: vérifie si une ligne est vide (que des 0)
E: 1 pointeur plateau et 1 entier (le numéro de la ligne)
S: 1 entier (1 si la ligne est complète)(sinon 0)
*/


int lineIsEmpty(plateau* p, int n){
  int i, emptycase = 0;
  /*on regarde si les cases de la ligne n sont égale à 1*/
  for(i=2;i<LARGEUR_P-2;i++){
    /*récupération du nombre de case = 0*/
    if(p->plateau[n][i]==0){
      emptycase++;
    }
  }
  /*on vérifie que le nombre de case est égale à la largeur du plateau*/
  /*si oui = 1 sinon = 0 */
  if( emptycase == LARGEUR_P-4){
    return 1;
  }
  return 0;
}

/*
R: Vérifie si la pièce peut être placée à la position actuelle
E: 1 pointeur vers plateau et 1 pointeur vers piéces
S: 1 entier 0 si la piéce ne peut êtres placé sinon 1
*/

int canPlacePiece(plateau *plat, piece *p) {
  int newX,newY,i,j;  
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COLUMN; j++) {
      if (p->piece[i][j]>0) {
	newX = p->x + j;
	newY = p->y + i;
	if (newX < 2 || newX >= LARGEUR_P-2 || newY < 2 || newY >= LONGUEUR_P-2 || plat->plateau[newY][newX] >0) {
	  return 0;
	}
      }
    }
  }
  return 1;
}

/*
R: Intègre la pièce dans le plateau 
E: 1 pointeur vers plateau 
S: vide
*/

void integratePiece(plateau *plat) {
  int i,j;
  piece *p = &plat->p_cur;
  if (canPlacePiece(plat, p)) {
    for (i = 0; i < ROW; i++) {
      for (j = 0; j < COLUMN; j++) {
                if (p->piece[i][j] > 0) {
                    plat->plateau[p->y + i][p->x + j] = plat->p_cur.id;
                }
            }
        }
    }
}

/*
R: copié une pièce dans un autre  
E: 2 pointeurs vers pièces ( dest,sourc)
S: vide
*/

void Plateaucpy(plateau *p1,plateau *p2){
  int i,j;
  /*on parcourps le plateau de jeux */
  /*on copy le plateau 2 dans le plateau 1*/
  for(i=0;i < LONGUEUR_P ;i++){
    for(j=0;j < LARGEUR_P ;j++){
      p1->plateau[i][j] =p2->plateau[i][j];
    }
  }
  /* copy des champs simple du plateau */
  p1->gameover = p2->gameover;
  p1->score = p2->score;
  p1->speed = p2->speed;

  /* copy des pieces */
  piececpy(&(p1->p_cur),&(p2->p_cur));
  piececpy(&(p1->p_next),&(p2->p_next));
}

/*
R: Fait descendre la pièce d'une ligne
E: 1 pointeur vers plateau
S: 1 entier 1 la piece peut décendre sinon 0
*/

int descendPiece(plateau *plat) {
    piece *p = &plat->p_cur;
    p->y++;  /* Essaye de descendre la pièce */
    if (canPlacePiece(plat, p)) {
      return 1; /* La pièce peut descendre */
    } else {
      p->y--; /* Remonte la pièce à sa position précédente */
      integratePiece(plat); /* Intègre la pièce dans le plateau */
        return 0; /* La pièce ne peut plus descendre */
    }
}

/*
R: charger la nouvelle piece dans le jeux
E: 1 pointeur vers plateau
S: vide
*/

void generateNewPiece(plateau *plat) {
    /*la piece suivante devient p_cur*/
    piececpy(&(plat->p_cur),&(plat->p_next));
    /*nouvelle valuer pour p_next*/
    piececpy(&(plat->p_next),&(plat->tpiece[SelectPiece()]));

    if (!canPlacePiece(plat, &plat->p_cur)) {
      plat->gameover = 1; /* Si la nouvelle pièce ne peut pas être placée, le jeu est terminé */
    }
}

/*
R: incrémenter le score en fonction des ligne qui ont été nétoyer
E: 1 pointeur vers plateau
S: vide
*/

void increaseScore(plateau *p){
  int lineclear;
  lineclear = checkPlateauState(p);
  switch(lineclear){
  /* si on a clear 1 ligne*/
  case 1:
    p->score+=10;
    break;
  /* si on a clear 2 lignes*/   
  case 2:
    p->score+=25;
    break;
  /* si on a clear 3 lignes*/
  case 3:
    p->score+=50;
    break;
  /* si on a clear 4 ligne*/
  case 4:
    p->score+=100;
    break;
  /* cas default */
  default:
    break;
  }
}

/*
R: augmenter la vitesse en fonction du score
E: 1 pointeur vers plateau
S: vide
*/

void increaseSpeed(plateau *p){
  if(p->score >= 0 && p->score < 500) p->speed = 0;           /*  level 0  */
  if(p->score >= 500 && p->score < 1000) p->speed = 1;        /*  level 1  */
  if(p->score >= 1000 && p->score < 2000) p->speed = 2;       /*  level 2  */
  if(p->score >= 2000 && p->score < 4000) p->speed = 3;       /*  level 3  */
  if(p->score >= 4000 && p->score < 8000) p->speed = 4;       /*  level 4  */
  if(p->score >= 8000 && p->score < 16000) p->speed = 5;      /*  level 5  */
  if(p->score >= 16000 && p->score < 32000) p->speed = 6;     /*  level 6  */
  if(p->score >= 32000 && p->score < 64000) p->speed = 7;     /*  level 7  */
  if(p->score >= 64000 && p->score < 128000) p->speed = 8;    /*  level 8  */
  if(p->score >= 128000 && p->score < 256000) p->speed = 9;   /*  level 9  */
  if(p->score > 256000) p->speed = 10;                        /*  level 10 */
}
#endif /*_PLATEAU_C_*/

