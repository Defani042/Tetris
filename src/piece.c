#ifndef _PIECE_C_
#define _PIECE_C_

/*std lib*/
#include <stdio.h>
#include <stdlib.h>

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
R: fonction d
E:
S: 
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
  p->piece[0][3]=1;
  p->piece[1][3]=1;
  p->piece[2][3]=1;
  p->piece[3][3]=1;
}

/*
R: fonction pour faire la piece ligne
E: un pointeur piece
S: vide
*/

void setPieceSquare(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  p->piece[2][3]=1;
  p->piece[2][2]=1;
  p->piece[3][3]=1;
  p->piece[3][2]=1;
}

/*
R: fonction pour faire la piece en forme de T
E: un pointeur piece
S: vide
*/

void setPieceT(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  p->piece[2][2]=1;
  p->piece[3][3]=1;
  p->piece[3][2]=1;
  p->piece[3][1]=1;

}

/*
R: fonction pour faire la piece en forme de Z
E: un pointeur piece
S: vide
*/

void setPieceZ(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  p->piece[1][2]=1;
  p->piece[2][2]=1;
  p->piece[2][3]=1;
  p->piece[3][3]=1;

}

/*
R: fonction pour faire la piece len forme de Z inversé
E: un pointeur piece
S: vide
*/

void setPieceZinv(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  p->piece[1][3]=1;
  p->piece[2][2]=1;
  p->piece[2][3]=1;
  p->piece[3][2]=1;

}

/*
R: fonction pour faire la piece en forme de L
E: un pointeur piece
S: vide
*/

void setPieceL(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  p->piece[1][2]=1;
  p->piece[2][2]=1;
  p->piece[2][3]=1;
  p->piece[3][3]=1;

}

/*
R: fonction pour faire la piece en forme de L inversé
E: un pointeur piece
S: vide
*/

void setPieceLinv(piece *p){
  SetPiece(p);/*mise à zero de la piece*/
  p->piece[1][3]=1;
  p->piece[2][3]=1;
  p->piece[2][3]=1;
  p->piece[3][3]=1;

}

/*
R: fonction pour faire une transpose d'une piece
E: un pointeur piece
S: vide
*/

void transpose(piece *p) {
  int i,j,tmp;
  for(i = 0; i < ROW; i++) {
    for (j = i + 1; j < ROW; j++) {
      tmp = p->piece[i][j];
      p->piece[i][j] = p->piece[j][i];
      p->piece[j][i] = tmp;
    }
  }
}

/*
R: fonction pour faire une inverse d'une piece en fonction des lignes
E: un pointeur piece
S: vide
*/

void reverse_rows(piece *p) {
  int i,j,tmp;
  for (i = 0; i < ROW / 2; i++) {
    for (j = 0; j < ROW; j++) {
      tmp = p->piece[i][j];
      p->piece[i][j] = p->piece[COLUMN - i - 1][j];
      p->piece[ROW - i - 1][j] = tmp;
    }
  }
}

/*
R: fonction pour faire une inverse d'une piece
E: un pointeur piece
S: vide
*/

void rotate_anticlockwise(piece *p) {
    transpose(p);
    reverse_rows(p);
}

/*
R: fonction pour faire une inverse d'une piece en fonction des colomnes
E: un pointeur piece
S: vide
*/

void reverse_columns(piece *p) {
  int i,j,tmp;
  for (i = 0; i < COLUMN; i++) {
    for (j = 0; j < COLUMN / 2; j++) {
      tmp = p->piece[i][j];
      p->piece[i][j] = p->piece[i][COLUMN - j - 1];
      p->piece[i][COLUMN - j - 1] = tmp;
    }
  }
}

void rotate_clockwise(piece *p) {
    transpose(p);
    reverse_columns(p);
}
#endif /*_PIECE_C_*/
