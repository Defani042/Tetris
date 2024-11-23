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
    MLV_draw_filled_rectangle(width*3/20,(height/40)*5,(width*6)/20,(height*6)/20,MLV_COLOR_BLUE);
    w=(200*width)/1000;
    h=(150*height)/1000;
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
    MLV_draw_filled_rectangle((width*11)/20,(height/40)*5,(width*6)/20,(height*6)/20,MLV_COLOR_BLUE);
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
    h=(550*height)/1000;
    MLV_draw_filled_rectangle((width*11)/20,(height/40)*21,(width*6)/20,(height*6)/20,MLV_COLOR_BLUE);
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
    MLV_draw_filled_rectangle(width*3/20,(height/40)*21,(width*6)/20,(height*6)/20,MLV_COLOR_BLUE);
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
    h1=(900*h)/1000;
    h2=(75*h)/1000;
    h3=(920*h)/1000;
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
E: la taille de l'ecran, le nom du fichier et le n°du fichier
S: rien
*/

void saveScore(int w,int h,char* fichier,int num_save){
    int j,w1,w2,h1,h2;
    MLV_Font* font;
    FILE* fich;
    char line[LINE_MAX];
    w1=0;
    w2=0;
    h1=0;
    h2=0;
    font = MLV_load_font( "../fich/04B_30__.TTF" , 50 );
    switch (num_save){
        case 1: w1=w*210/1000;h1=h*325/1000;w2=w*245/1000;h2=h*325/1000;break;
        case 2: w1=w*610/1000;h1=h*325/1000;w2=w*645/1000;h2=h*325/1000;break;
        case 3: w1=w*210/1000;h1=h*725/1000;w2=w*245/1000;h2=h*725/1000;break;
        case 4: w1=w*610/1000;h1=h*725/1000;w2=w*645/1000;h2=h*725/1000;break;
    }
    fich = fopen(fichier,"a+");
    if (fich == NULL){
        MLV_draw_text_with_font(
			    w1, h1,
			    "EMPTY", 
			    font, MLV_COLOR_RED
			    );
    }
    else{
        if (fgets(line,LINE_MAX,fich) == NULL){
                MLV_draw_text_with_font(
			        w1, h1,
			        "EMPTY", 
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
			            w2, h2,
			            line, 
			            font, MLV_COLOR_WHITE
			            );
            fclose(fich);
        }
    }
}

/*
R: créer la fenetre sauvegarde
E: rien
S: rien
*/

void setSaveMenu(int page){
    int i,width,height,x,y;
    i=1;
    height = MLV_get_desktop_height();
    width = MLV_get_desktop_width();
    setSaveButton(width,height);
    setButonBack(width,height);
    saveScore(width,height,"../fich/save1.txt",1);
    saveScore(width,height,"../fich/save2.txt",2);
    saveScore(width,height,"../fich/save3.txt",3);
    saveScore(width,height,"../fich/save4.txt",4);
    MLV_actualise_window();
    while (i){
        MLV_wait_mouse(&x,&y);
            if (x>(width*3/20) && x<(width*3/20+((width*6)/20)) && y>((height/40)*5) && y<((height/40)*5+((height*6)/20))){
                if (page == 1){
                    printf("load fichier1\n");
                }
                else {
                    printf("save fichier1\n");
                }
            }
            if (x>(width*11/20) && x<(width*11/20+((width*6)/20)) && y>((height/40)*5) && y<((height/40)*5+((height*6)/20))){
                if (page == 1){
                    printf("load fichier2\n");
                }
                else {
                    printf("save fichier2\n");
                }
            }
            if (x>(width*3/20) && x<(width*3/20+((width*6)/20)) && y>((height/40)*21) && y<((height/40)*21+((height*6)/20))){
                if (page == 1){
                    printf("load fichier3\n");
                }
                else {
                    printf("save fichier3\n");
                }
            }
            if (x>(width*11/20) && x<(width*11/20+((width*6)/20)) && y>(height/40)*21 && y<(((height/40)*21+(height*6)/20))){
                if (page == 1){
                    printf("load fichier4\n");
                }
                else {
                    printf("save fichier4\n");
                }
            }
            if (x>(350*width/1000) && x<(650*width/1000) && y>(900*height/1000) && y<(975*height/1000)){
            i=0;
        }
    }
}

#endif /*_SAVE_C_*/
