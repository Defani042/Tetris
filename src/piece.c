#ifndef _PIECE_C_
#define _PIECE_C_

/*std lib*/
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>

/*lib local*/
#include "piece.h"

/*
R: fonction de remise à zero de la piece
E: un pointeur piece
S: vide
*/

void SetPiece(piece *p){
  int i,j;
  /*on parcourps le plateau de jeux */
  for(i=0;i < ROW ;i++){
    for(j=0;j < COLUMN ;j++){
      /*on met la case à l'indice i,j à 0 */
      p->piece[i][j] = 0;
    }
  }
}

/*
R: fonction d'affichage de la piece
E: 1 pointeur vers piece
S: vide 
*/

void printpiece(piece *p){
  int i,j;
  /*on parcourps le tableau et on afiche la case indince i,j*/
  /*on parcourps le tableau à l'envers sur les lignes pour que la case 2 soit la seconde en partant du bas du tableau*/
  for(i=0;i<ROW;i++){
    for(j=0;j<COLUMN;j++){
      printf(" %d",p->piece[i][j]);
    }
    printf("\n");
  }
}



/*
R: fonction pour faire la piece ligne
E: un pointeur piece
S: vide
*/

void setPieceLine(piece *p){
  SetPiece(p); /*mise à zero de la piece*/
  /* couleur de la pièce */
  p->r=43;
  p->g=255;
  p->b=255;
  p->a=255;
  /* aspect de la pièce */  
  p->piece[0][2]=1;
  p->piece[1][2]=1;
  p->piece[2][2]=1;
  p->piece[3][2]=1;
  /*position de la piece*/
  p->x= INITX;
  p->y= INITY+1;
  /*id de la piece*/
  p->id = 1;
}

/*
R: fonction pour faire la piece ligne
E: un pointeur piece
S: vide
*/

void setPieceSquare(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  /* couleur de la pièce */
  p->r=255;
  p->g=255;
  p->b=0;
  p->a=255;
  /* aspect de la pièce */
  p->piece[1][1]=2;
  p->piece[1][2]=2;
  p->piece[2][1]=2;
  p->piece[2][2]=2;
  /*position de la piece*/
  p->x= INITX;
  p->y= INITY;
  /*id de la piece*/
  p->id = 2;
}

/*
R: fonction pour faire la piece en forme de T
E: un pointeur piece
S: vide
*/

void setPieceT(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  /* couleur de la pièce */
  p->r=238;
  p->g=130;
  p->b=238;
  p->a=255;
  /* aspect de la pièce */
  p->piece[1][2]=3;
  p->piece[2][3]=3;
  p->piece[2][2]=3;
  p->piece[2][1]=3;
  /*position de la piece*/
  p->x= INITX;
  p->y= INITY;
  /*id de la piece*/
  p->id = 3;
}

/*
R: fonction pour faire la piece en forme de Z
E: un pointeur piece
S: vide
*/

void setPieceZ(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  /* couleur de la pièce */
  p->r=255;
  p->g=0;
  p->b=0;
  p->a=255;
  /* aspect de la pièce */
  p->piece[1][2]=4;
  p->piece[2][1]=4;
  p->piece[2][2]=4;
  p->piece[3][1]=4;
  /*position de la piece*/
  p->x= INITX;
  p->y= INITY;
  /*id de la piece*/
  p->id = 4;
}

/*
R: fonction pour faire la piece len forme de Z inversé
E: un pointeur piece
S: vide
*/

void setPieceZinv(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  /* couleur de la pièce */
  p->r=0;
  p->g=255;
  p->b=0;
  p->a=255;
  /* aspect de la pièce */
  p->piece[1][1]=5;
  p->piece[2][2]=5;
  p->piece[2][1]=5;
  p->piece[3][2]=5;
  /*position de la piece*/
  p->x= INITX;
  p->y= INITY;
  /*id de la piece*/
  p->id = 5;
}

/*
R: fonction pour faire la piece en forme de L
E: un pointeur piece
S: vide
*/

void setPieceL(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  /* couleur de la pièce */
  p->r=255;
  p->g=128;
  p->b=0;
  p->a=255;
  /* aspect de la pièce */
  p->piece[0][1]=6;
  p->piece[1][1]=6;
  p->piece[2][1]=6;
  p->piece[2][2]=6;
  /*position de la piece*/
  p->x= INITX;
  p->y= INITY+1;
  /*id de la piece*/
  p->id = 6;
}

/*
R: fonction pour faire la piece en forme de L inversé
E: un pointeur piece
S: vide
*/

void setPieceLinv(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  /* couleur de la pièce */
  p->r=0;
  p->g=0;
  p->b=255;
  p->a=255;
  /* aspect de la pièce */
  p->piece[0][2]=7;
  p->piece[1][2]=7;
  p->piece[2][1]=7;
  p->piece[2][2]=7;
  /*position de la piece*/
  p->x= INITX;
  p->y= INITY+1;
  /*id de la piece*/
  p->id = 7;
}


/*
R: fonction de remplissage du tableau avec les pieces de base du tetris
E: un tableau de piece
S: vide
*/

void setTabpiece(tabpiece t){
  setPieceLine(&t[0]);       /*Piece ligne*/
  setPieceSquare(&t[1]);     /*Piece carrer*/
  setPieceT(&t[2]);          /*Piece T*/
  setPieceZ(&t[3]);          /*Piece Z*/
  setPieceZinv(&t[4]);       /*Piece Z inversé*/
  setPieceL(&t[5]);          /*Piece L*/
  setPieceLinv(&t[6]);       /*Piece L inversé*/
	    
}

/*
R: fonction d'affichage du tableau de piece
E: un pointeur piece
S: vide
*/

void printTabPiece(tabpiece t){
  int i;
  /*on parcours le tableau*/
  for(i=0;i<NB_PIECE;i++){
    printf("piece %d : \n",i);
    printpiece(&t[i]); /*afichage de la piece indice i*/
    printf("\n");

  }

}

/*
R: fonction pour générer un nombre compris entre 0 et 6 (indice des piece du tableau)
E: vide
S: 1 entier (compris entre 0 et 6)
*/

int SelectPiece(){
  return rand() % 7;
}

/*
R: copié une pièce dans un autre  
E: 2 pointeurs vers pièces ( dest,sourc)
S: vide
*/

void piececpy(piece* p1, piece *p2){
  int i,j;
  /* copy de la piece */
  for (i = 0; i < COLUMN; i++) {
    for (j = 0; j < ROW; j++) {
      p1->piece[i][j] = p2->piece[i][j];
    }
  }
  /* copy des champs de couleurs de la piece */
  p1->r=p2->r; /* niveau de ROUGE */
  p1->g=p2->g; /* niveau de BLEU */
  p1->b=p2->b; /* niveau de VERT */
  p1->a=p2->a; /* niveau d' OPPACITE */

  /* copy pos piece */
  p1->y=p2->y; /*position Y de la piece*/
  p1->x=p2->x; /*position X de la piece*/
  p1->id=p2->id; /*copy de l'id */
  
}




/*
R: Fait tourner la pièce de 90 degrés dans la direction spécifiée
E: 1 pointeur vers une structure pièce et 1 entier pour la direction (1 pour horaire, -1 pour anti-horaire)
S: vide
*/
void rotatePieceArray(piece *p, int direction) {
    int temp[ROW][COLUMN];
    int i, j;
    
    /* Transposer la matrice */
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            temp[j][i] = p->piece[i][j];
        }
    }
    
    /* Inverser les lignes pour une rotation horaire ou les colonnes pour une rotation anti-horaire */
    if (direction == 1) {
        /* Rotation horaire */
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COLUMN / 2; j++) {
                int tmp = temp[i][j];
                temp[i][j] = temp[i][COLUMN - 1 - j];
                temp[i][COLUMN - 1 - j] = tmp;
            }
        }
    } else if (direction == -1) {
        /* Rotation anti-horaire */
        for (i = 0; i < ROW / 2; i++) {
            for (j = 0; j < COLUMN; j++) {
                int tmp = temp[i][j];
                temp[i][j] = temp[ROW - 1 - i][j];
                temp[ROW - 1 - i][j] = tmp;
            }
        }
    }
    
    /* Copier la matrice tournée dans le tableau original de la pièce */
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            p->piece[i][j] = temp[i][j];
        }
    }
}




#endif /*_PIECE_C_*/
