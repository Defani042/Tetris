#ifndef _SCOREBOARD_H_
#define _SCOREBOARD_H_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>

/*local lib*/
#include "scoreboard.h"

/*Macro*/
#define NB_MAX 15
#define LINE_MAX 32
#define SCORE_SAVE "fich/scoreboard.txt"


void readFich(char* filename,int tab[NB_MAX], int new_score);

void tri(int tab[NB_MAX]);

void printfichier(char* filename,int tab[NB_MAX]);

void setScoreboard(int new_score);

#endif /*_SCOREBOARD_H_*/
