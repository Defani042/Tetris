#ifndef _GAMEWINDOW_H_
#define _GAMEWINDOW_H_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

/*local lib*/
#include "save.h"
#include "plateau.h"
#include "MainWindow.h"
#include "scoreboard.h"
#include "MainWindow.h"

/*macro*/
#define SCORE_PRINT 32

void input(plateau *p,int compteur);

void affichage_pixel(plateau *p,int t,int w,int h);

int gameoverWindow(plateau *p,int id_fich);

void createGame(plateau *p, int conteur_speed);

void afficherPlateau(plateau *p,int t,int w,int h);

void printTime(char* t,MLV_Font* font,plateau *p);

void createGameWindow(int w,int h,MLV_Image* background);

void stopWindow(int w, int h);

int setStopWindow(int w,int h,plateau *p,MLV_Image* background);

void setGameWindow(plateau *p,int fich);

#endif /*_MAINWINDOW_H_*/
