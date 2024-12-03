#ifndef _PIECE_H_
#define _PIECE_H_

/*std lib*/
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

/*Macro*/
#define ROW 4
#define COLUMN 4
#define NB_PIECE 7
#define INITY 1
#define INITX 4

/*Structure piece*/
typedef struct{
  int piece[ROW][COLUMN];/*réprésentation piece  si case = 1 il y a une pièces sinon case =0 */
  int r,g,b,a; /*niveau de coleur(r,g,b) et oppacité(a) */
  int x,y; /*position de la piece dans le plateau*/
  int id; /*id de la piece*/
}piece;

/*Déclaration d'un tableau de piece*/
typedef piece tabpiece[NB_PIECE];


void SetPiece(piece *p);

void printpiece(piece *p);

void setPieceLine(piece *p);

void setPieceSquare(piece *p);

void setPieceT(piece *p);

void setPieceZ(piece *p);

void setPieceZinv(piece *p);

void setPieceL(piece *p);

void setPieceLinv(piece *p);

void transpose(piece *p);

void reverse_rows(piece *p);

void rotate_anticlockwise(piece *p);

void reverse_columns(piece *p);

void rotate_clockwise(piece *p);

void printTabPiece(tabpiece t);

void setTabpiece(tabpiece t);

int SelectPiece();

void piececpy(piece* p1, piece *p2);

#endif /*_PIECE_H_*/
