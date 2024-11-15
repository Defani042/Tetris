#ifndef _SAVE_H_
#define _SAVE_H_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

/*Macro*/
#define LINE_MAX 32

void setSaveButton(int width, int height);

void setButonBack(int w,int h);

void saveScore(int w,int h);

void setSaveMenu();

#endif /*_SAVE_H_*/