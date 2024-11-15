#ifndef _MAINWINDOW_C_
#define _MAINWINDOW_C_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <unistd.h>

/*local lib*/
#include "MainWindow.h"
#include "save.h"

/*Macro*/
#define LINE_MAX 32


/* 
R: Permet de creer le logo
E: longueur ecran,hauteur ecran
S: Vide
*/

void setLogo(int h, int w){
    int h1,h2,h3,w1,w2,w3,p1,p2,p3;
    MLV_Font* font;
    h1=(100*h)/1000;
    h2=(0*h)/1000;
    h3=(230*h)/1000;
    w1=(200*w)/1000;
    w2=(0*w)/1000;
    w3=(675*w)/1000;
    p1=(100*w)/1000;
    p2=(15*w)/1000;
    p3=(35*w)/1000;
    font= MLV_load_font( "../fich/04B_30__.TTF" , p1 );
    MLV_draw_text_with_font(
        w1,h1,
        "TETRIS", 
        font, MLV_COLOR_WHITE
    );
    font = MLV_load_font( "../fich/04B_30__.TTF" , p2 );
        MLV_draw_text_with_font(
        w2, h2,
        "Created by Adrien Defay and Gaultier Peyrard", 
        font, MLV_COLOR_BLUE
    );
        font = MLV_load_font( "../fich/04B_30__.TTF" , p3 );
        MLV_draw_text_with_font(
            w3, h3,
            "LIKE", 
            font, MLV_COLOR_BLUE
            );
}

/* 
R: Permet de creer le tableau de score
E: Nom du fichier,longueur ecran,hauteur ecran
S: Vide
*/

void printScore(char *filename,int w,int h){
    int i=0,j=0;
    int w1,h1,p;
    MLV_Font* font;
    char line[LINE_MAX];
    FILE* fich;
    w1=(825*w)/1000;
    h1=(350*h)/1000;
    p=(17*w)/1000;
    font = MLV_load_font( "../fich/04B_30__.TTF" , p );
    MLV_draw_text_with_font(
       w1, h1,
        "SCOREBOARD", 
        font, MLV_COLOR_BLUE
    );
    w1=(880*w)/1000;
    p=(15*w)/1000;
    font = MLV_load_font( "../fich/04B_30__.TTF" , p );
    fich = fopen(filename,"a+");
    while (i<10){
        h1=((350+((i+1)*35))*h)/1000;
        if (fgets(line,LINE_MAX,fich) == NULL){
            MLV_draw_text_with_font(
			    w1, h1,
			    "-----", 
			    font, MLV_COLOR_WHITE
			    ); 
        }
        else{
            printf("%s", line);
            j = 0;
            do {
                if(line[j] == '\n') line[j] = '\0';
                j++;
            } while(line[j]!='\0');

            MLV_draw_text_with_font(
			    w1, h1,
			    line, 
			    font, MLV_COLOR_WHITE
			); 
        }
      i++;
    }
}

/* 
R: Permet de creer le bouton start
E: longueur ecran,hauteur ecran
S: Vide
*/
void setButonStart(int w,int h){
    int w1,w2,w3,h1,h2,h3,p;
    MLV_Font* font;
    w1=(300*w)/1000;
    w2=(307*w)/1000;
    w3=(400*w)/1000;
    h1=(400*h)/1000;
    h2=(427*h)/1000;
    h3=(100*h)/1000;
    p=(30*w)/1000;
    font = MLV_load_font( "../fich/04B_30__.TTF" , p );
    MLV_draw_filled_rectangle(w1,h1,w3,h3,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        w2, h2,
        "START NEW GAME", 
        font, MLV_COLOR_WHITE
    );
}

/* 
R: Permet de creer le bouton load
E: longueur ecran,hauteur ecran
S: Vide
*/
void setButonLoad(int w,int h){
    int w1,w2,w3,h1,h2,h3,p;
     MLV_Font* font;
    w1=(350*w)/1000;
    w2=(300*w)/1000;
    w3=(372*w)/1000;
    h1=(550*h)/1000;
    h2=(75*h)/1000;
    h3=(567*h)/1000;
    p=(25*w)/1000;
    font = MLV_load_font( "../fich/04B_30__.TTF" , p );
     MLV_draw_filled_rectangle(w1,h1,w2,h2,MLV_COLOR_BLUE);
     MLV_draw_text_with_font(
        w3, h3,
        "LOAD A GAME", 
        font, MLV_COLOR_WHITE
    );
}

/* 
R: Permet de creer le bouton load
E: longueur ecran,hauteur ecran
S: Vide
*/
void setButonOption(int w,int h){
    int w1,w2,w3,h1,h2,h3,p;
    MLV_Font* font;
    w1=(350*w)/1000;
    w2=(300*w)/1000;
    w3=(430*w)/1000;
    h1=(675*h)/1000;
    h2=(75*h)/1000;
    h3=(692*h)/1000;
    p=(25*w)/1000;
    font = MLV_load_font( "../fich/04B_30__.TTF" , p );
    MLV_draw_filled_rectangle(w1,h1,w2,h2,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        w3,h3,
        "OPTION", 
        font, MLV_COLOR_WHITE
    );
}

/* 
R: Permet de creer le bouton exit
E: longueur ecran,hauteur ecran
S: Vide
*/
void setButonExit(int w,int h){
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
    MLV_draw_filled_rectangle(w1,h1,w2,h2,MLV_COLOR_RED);
    MLV_draw_text_with_font(
        w3, h3,
        "EXIT", 
        font, MLV_COLOR_WHITE
    );
}

/*3 fonctions test*/ 
void startGame(){
    printf("Start a new game\n");
}

void loadGame(){
    printf("Load game\n");
}

void option(){
    printf("Option\n");
}


/*
R: Permet de creer le fentre
E: rien
S:rien
*/

void createWindow(){
    int width,height;
    height = MLV_get_desktop_height();
    width = MLV_get_desktop_width();
    setLogo(height,width);
    printScore("../fich/scoreboard.txt",width,height);
    setButonStart(width,height);
    setButonLoad(width,height);
    setButonOption(width,height);
    setButonExit(width,height);
    MLV_actualise_window();
}

/*
R: permet d'afficher le menu principale
E: vide
S: vide
*/
void SetMainWindow(){
    int x,y,i,width,height;
    height = MLV_get_desktop_height();
    width = MLV_get_desktop_width();
    i=1;
    MLV_create_window("Tetris","Tetris-like",width,height);
    createWindow();

    while(i){
        MLV_wait_mouse(&x,&y);
        if (x>(300*width/1000) && x<(700*width/1000) && y>(400*height/1000) && y<(500*height/1000)){
            startGame();
        }
        if (x>(350*width/1000) && x<(650*width/1000) && y>(550*height/1000) && y<(625*height/1000)){
            loadGame();
            setSaveMenu();
            MLV_clear_window( MLV_COLOR_BLACK );
            createWindow();
        }
        if (x>(350*width/1000) && x<(650*width/1000) && y>(675*height/1000) && y<(750*height/1000)){
            option();
        }
        if (x>(350*width/1000) && x<(650*width/1000) && y>(800*height/1000) && y<(875*height/1000)){
            i=0;
        }
        MLV_actualise_window();
    }
    MLV_free_window();
}



#endif /*_MAINWINDOW_C_*/
