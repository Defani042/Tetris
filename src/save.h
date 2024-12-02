#ifndef _SAVE_H_
#define _SAVE_H_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

/*local lib*/
#include "plateau.h"

/*Macro*/
#define LINE_MAX 32
#define FILE1 "fich/save1.txt"
#define FILE2 "fich/save2.txt"
#define FILE3 "fich/save3.txt"
#define FILE4 "fich/save4.txt"

void setSaveButton(int width, int height);

void setButonBack(int w,int h);

void saveScore(int w,int h,char* fichier,int num_save);

void setSaveMenu(int page, plateau* p);

void createAllSaveMenu(int width,int height);

void saveInFich(plateau* p, char* filename,int score);

#endif /*_SAVE_H_*/