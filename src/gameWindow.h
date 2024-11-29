#ifndef _GAMEWINDOW_H_
#define _GAMEWINDOW_H_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

/*local lib*/
#include "save.h"
#include "plateau.h"

void printTime(char* t,MLV_Font* font);

void createGameWindow(int w,int h);

void stopWindow(int w, int h);

int setStopWindow(int w,int h,plateau *p);

void setGameWindow(plateau *p);

#endif /*_MAINWINDOW_H_*/