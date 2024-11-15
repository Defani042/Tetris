#ifndef _SAVE_C_
#define _SAVE_C_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

/*local lib*/
#include "save.h"

/*Macro*/
#define LINE_MAX 32

/*
R: creer les bouttons sauvegarde
E: longueur ecran,hauteur ecran
S: rien
*/

void setSaveButton(int width, int height){
    int w,h;
    MLV_Font* font;
    MLV_clear_window( MLV_COLOR_BLACK );
    font = MLV_load_font( "../fich/04B_30__.TTF" , 50 );
    MLV_draw_filled_rectangle(width*3/20,height/20,(width*6)/20,(height*6)/20,MLV_COLOR_BLUE);
    w=(200*width)/1000;
    h=(50*height)/1000;
    MLV_draw_text_with_font(
        w, h,
        "FILE 1", 
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        w, h+50,
        "SCORE:", 
        font, MLV_COLOR_WHITE
    );
    w=((600*width)/1000);
    MLV_draw_filled_rectangle((width*11)/20,height/20,(width*6)/20,(height*6)/20,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        w, h,
        "FILE 2", 
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        w, h+50,
        "SCORE:", 
        font, MLV_COLOR_WHITE
    );
    h=(450*height)/1000;
    MLV_draw_filled_rectangle((width*11)/20,(height*9)/20,(width*6)/20,(height*6)/20,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        w, h,
        "FILE 4", 
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        w, h+50,
        "SCORE:", 
        font, MLV_COLOR_WHITE
    );
    w=(200*width)/1000;
    MLV_draw_filled_rectangle(width*3/20,(height*9)/20,(width*6)/20,(height*6)/20,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        w, h,
        "FILE 3", 
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        w, h+50,
        "SCORE:", 
        font, MLV_COLOR_WHITE
    );
}

/* 
R: Permet de creer le bouton exit
E: longueur ecran,hauteur ecran
S: Vide
*/
void setButonBack(int w,int h){
    int w1,w2,w3,h1,h2,h3,p;
    MLV_Font* font;
    w1=(350*w)/1000;
    w2=(300*w)/1000;
    w3=(455*w)/1000;
    h1=(800*h)/1000;
    h2=(75*h)/1000;
    h3=(820*h)/1000;
    p=(25*w)/1000;
    font = MLV_load_font( "../fich/04B_30__.TTF" , p );
    MLV_draw_filled_rectangle(w1,h1,w2,h2,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        w3, h3,
        "BACK", 
        font, MLV_COLOR_WHITE
    );
}

/*
R: affiche les scores sur les saves
E: 
*/

void saveScore(int w,int h){
    int j;
    MLV_Font* font;
    FILE* fich;
    char line[LINE_MAX];
    font = MLV_load_font( "../fich/04B_30__.TTF" , 50 );
    fich = fopen("../fich/save1.txt","a+");
    if (fgets(line,LINE_MAX,fich) == NULL){
            MLV_draw_text_with_font(
			    w*225/1000, h*225/1000,
			    "-----", 
			    font, MLV_COLOR_WHITE
			    );
    }
    else{   
        j=0;
        do {
                if(line[j] == '\n') line[j] = '\0';
                j++;
            } while(line[j]!='\0');
        MLV_draw_text_with_font(
			    w*245/1000, h*225/1000,
			    line, 
			    font, MLV_COLOR_WHITE
			    );
    }
    fclose(fich);
}

/*
R: créer la fenetre sauvegarde
E: rien
S: rien
*/

void setSaveMenu(){
    int i,width,height,x,y;
    i=1;
    height = MLV_get_desktop_height();
    width = MLV_get_desktop_width();
    setSaveButton(width,height);
    setButonBack(width,height);
    saveScore(width,height);
    MLV_actualise_window();
    while (i){
        MLV_wait_mouse(&x,&y);


            if (x>(350*width/1000) && x<(650*width/1000) && y>(800*height/1000) && y<(875*height/1000)){
            i=0;
        }
    }
}

#endif /*_SAVE_C_*/