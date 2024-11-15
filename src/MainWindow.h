#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

/*local lib*/


/* Fonctions */

void printScore(char *filename,int w,int h);

void setLogo(int h, int w);

void setButonStart(int w,int h);

void setButonLoad(int w,int h);

void setButonOption(int w,int h);

void setButonExit(int w,int h);

void startGame();

void loadGame();

void option();

void createWindow();

void SetMainWindow();

#endif /*_PLATEAU_H_*/
