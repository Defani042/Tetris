#ifndef _MAINWINDOW_C_
#define _MAINWINDOW_C_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

/*local lib*/
#include "MainWindow.h"

/*Macro*/
#define LINE_MAX 32


/* 
R: Permet de creer le logo
E: Vide
S: Vide
*/

void setLogo(){
    MLV_Font* font = MLV_load_font( "04B_30__.TTF" , 100 );
    MLV_draw_text_with_font(
        200, 100,
        "TETRIS", 
        font, MLV_COLOR_WHITE
    );
    font = MLV_load_font( "04B_30__.TTF" , 15 );
        MLV_draw_text_with_font(
        473, 935,
        "Created by Adrien Defay and Gaultier Peyrard", 
        font, MLV_COLOR_BLUE
    );
        font = MLV_load_font( "04B_30__.TTF" , 35 );
        MLV_draw_text_with_font(
            675, 175,
            "LIKE", 
            font, MLV_COLOR_BLUE
            );
}

/* 
R: Permet de creer le tableau de score
E: Nom du fichier
S: Vide
*/

void setScoreboard(char *filename){
    int i=0, linelen=0;
    char line[LINE_MAX];
    MLV_Font* font = MLV_load_font( "04B_30__.TTF" , 17 );
    FILE* fich;
    MLV_draw_filled_rectangle(300,400,400,100,MLV_COLOR_WHITE);
    MLV_draw_text_with_font(
       825, 350,
        "SCOREBOARD", 
        font, MLV_COLOR_BLUE
    );
    font = MLV_load_font( "04B_30__.TTF" , 15 );
    fich = fopen(filename,"r");
    if (fich == NULL) {
        MLV_draw_filled_rectangle(300,400,400,100,MLV_COLOR_WHITE);
        MLV_draw_text_with_font(
            875, 350,
            "No data", 
            font, MLV_COLOR_WHITE
        );
    }
    else{
        while (i<3 && fgets(line,LINE_MAX,fich) != NULL){
            linelen = strlen(line)-1;
            if(line[linelen] == '\n') line[strlen(line)-1] = '\0';
            MLV_draw_filled_rectangle(300,400,400,100,MLV_COLOR_WHITE);
            MLV_draw_text_with_font(
                880, 350+(i+1)*25,
                line, 
                font, MLV_COLOR_WHITE
                );
            i++;
        }
    }
}

/* 
R: Permet de creer le bouton start
E: Vide
S: Vide
*/
void setButonStart(){
    MLV_Font* font = MLV_load_font( "04B_30__.TTF" , 30 );
    MLV_draw_filled_rectangle(300,400,400,100,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        307, 435,
        "START NEW GAME", 
        font, MLV_COLOR_WHITE
    );
}

/* 
R: Permet de creer le bouton load
E: Vide
S: Vide
*/
void setButonLoad(){
     MLV_Font* font = MLV_load_font( "04B_30__.TTF" , 25 );
     MLV_draw_filled_rectangle(350,550,300,75,MLV_COLOR_BLUE);
     MLV_draw_text_with_font(
        372, 575,
        "LOAD A GAME", 
        font, MLV_COLOR_WHITE
    );
}

/* 
R: Permet de creer le bouton load
E: Vide
S: Vide
*/
void setButonOption(){
    MLV_Font* font = MLV_load_font( "04B_30__.TTF" , 25 );
    MLV_draw_filled_rectangle(350,675,300,75,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        430, 700,
        "OPTION", 
        font, MLV_COLOR_WHITE
    );
}

/* 
R: Permet de creer le bouton load
E: Vide
S: Vide
*/
void setButonExit(){
    MLV_Font* font = MLV_load_font( "04B_30__.TTF" , 80 );
    MLV_draw_filled_rectangle(900,0,100,100,MLV_COLOR_RED);
    MLV_draw_text_with_font(
        920, 8,
        "x", 
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
R: permet d'afficher le menu principale
E: vide
S: vide
*/

void SetMainWindow(){
    int x,y,i/*,height,width*/;
    /*height = MLV_get_desktop_height();
      width = MLV_get_desktop_width();*/
    i=1;
    MLV_create_window("rectangle","rectangle2",1000,950);
    setLogo();
    setScoreboard("scoreboard.txt");
    setButonStart();
    setButonLoad();
    setButonOption();
    setButonExit();
    MLV_actualise_window();

    while(i){
        MLV_wait_mouse(&x,&y);
        if (x>300 && x<700 && y>400 && y<500){
            startGame();
        }
        if (x>350 && x<650 && y>550 && y<625){
            loadGame();
        }
        if (x>350 && x<650 && y>675 && y<750){
            option();
        }
        if (x>900 && x<1000 && y>0 && y<100){
            i=0;
        }
        MLV_actualise_window();
    }
    MLV_free_window();
}


#endif /*_PLATEAU_C_*/
