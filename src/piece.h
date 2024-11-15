#ifndef _PIECE_H_
#define _PIECE_H_

/*std lib*/
#include <stdio.h>
#include <stdlib.h>

/*Macro*/
#define ROW 4
#define COLUMN 4

/*Structure piece*/
typedef struct{
  int piece[ROW][COLUMN];/*réprésentation piece  si case = 1 il y a une pièces sinon case =0 */
}piece;

/*Déclaration d'un tableau de piece*/
typedef piece tabpiece[10];


void SetPiece(piece *p);

void printpiece(piece *p);

void setPieceLine(piece *p);

void setPieceSquare(piece *p);

void setPieceT(piece *p);

void setPieceZ(piece *p);

void setPieceZinv(piece *p);

void setPieceL(piece *p);

void transpose(piece *p);

void reverse_rows(piece *p);

void rotate_anticlockwise(piece *p);

void reverse_columns(piece *p);

void rotate_clockwise(piece *p);

#endif /*_PIECE_H_*/
