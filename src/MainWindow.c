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
#include "gameWindow.h"

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
    h1=(100*h)/1000;    /*prends toutes les coordonnées h pour hauteur, w pour largeur et p pour police*/
    h2=(965*h)/1000;    /* *1 pour le mot Tetris*/
    h3=(230*h)/1000;    /* *2 pour la phrase "Created by Adrien Defay and Gaultier Peyrard"*/
    w1=(200*w)/1000;    /* *3 pour le mot like*/
    w2=(35*w)/1000;
    w3=(675*w)/1000;
    p1=(100*w)/1000;
    p2=(15*w)/1000;
    p3=(35*w)/1000;
    font= MLV_load_font( "../fich/04B_30__.TTF" , p1 );
    MLV_draw_text_with_font(
        w1,h1,
        "TETRIS", 
        font, MLV_COLOR_WHITE
    ); /*affiche à l'ecran ce qu'il y a entre " " aux bonnes coordonées et à la bonne taille*/
    font = MLV_load_font( "../fich/04B_30__.TTF" , p2 );
        MLV_draw_text_with_font(
        w2, h2,
        "Created by Adrien Defay and Gaultier Peyrard", 
        font, MLV_COLOR_BLUE
    );/*affiche à l'ecran ce qu'il y a entre " " aux bonnes coordonées et à la bonne taille*/
        font = MLV_load_font( "../fich/04B_30__.TTF" , p3 );
        MLV_draw_text_with_font(
            w3, h3,
            "LIKE", 
            font, MLV_COLOR_BLUE
            );/*affiche à l'ecran ce qu'il y a entre " " aux bonnes coordonées et à la bonne taille*/
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
    );/*affiche à l'ecran ce qu'il y a entre " " aux bonnes coordonées et à la bonne taille*/
    w1=(886*w)/1000;
    p=(15*w)/1000;
    font = MLV_load_font( "../fich/04B_30__.TTF" , p );
    fich = fopen(filename,"a+");
    while (i<10){
        h1=((350+((i+1)*35))*h)/1000;
        if (fgets(line,LINE_MAX,fich) == NULL){     /*prends une ligne dans le fichier de scoreboard et regarde si elle est vide ou non*/
            MLV_draw_text_with_font(
			    w1, h1,
			    "-", 
			    font, MLV_COLOR_WHITE
			    ); /*affiche à l'ecran ce qu'il y a entre " " aux bonnes coordonées et à la bonne taille*/
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
			); /*affiche à l'ecran la ligne détéctee sur le fichier du scoreboard aux bonnes coordonées et à la bonne taille*/
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
    w1=(300*w)/1000;    /*prends toutes les coordonnées h pour hauteur, w pour largeur et p pour police*/
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
    );/*affiche START NEW GAME aux bonnes coordonnées at avec la bonne police*/
}

/* 
R: Permet de creer le bouton load
E: longueur ecran,hauteur ecran
S: Vide
*/
void setButonLoad(int w,int h){
    int w1,w2,w3,h1,h2,h3,p;
     MLV_Font* font;
    w1=(350*w)/1000;    /*prends toutes les coordonnées h pour hauteur, w pour largeur et p pour police*/
    w2=(300*w)/1000;
    w3=(372*w)/1000;
    h1=(550*h)/1000;
    h2=(75*h)/1000;
    h3=(567*h)/1000;
    p=(25*w)/1000;
    font = MLV_load_font( "../fich/04B_30__.TTF" , p );
     MLV_draw_filled_rectangle(w1,h1,w2,h2,MLV_rgba(0,0,255,255));
     MLV_draw_text_with_font(
        w3, h3,
        "LOAD A GAME",  /*affiche LOAD A GAME aux bonnes coordonnées*/
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
    w1=(350*w)/1000;    /*prends toutes les coordonnées h pour hauteur, w pour largeur et p pour police*/
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
        "OPTION",   /*affiche OPTION aux bonnes coordonnées*/
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
    w1=(350*w)/1000;    /*prends toutes les coordonnées h pour hauteur, w pour largeur et p pour police*/
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
        "EXIT",     /*affiche exit aux bonnes coordonnées*/
        font, MLV_COLOR_WHITE
    );
}

/*3 fonctions test*/ 
void startGame(){
    printf("Start a new game\n");
}

/*void loadGame(){
    printf("Load game\n");
}*/

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
    height = MLV_get_desktop_height(); /*prends la taille de l'ecran*/
    width = MLV_get_desktop_width();
    setLogo(height,width);              /*appelle toutes les fonc pour afficher le menu pricipale*/
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
void SetMainWindow(plateau *p){
    int x,y,i,width,height;
    height = MLV_get_desktop_height();  /*prend la hauteur de l'ecran*/
    width = MLV_get_desktop_width();    /*prends la largeur de l'ecran*/
    i=1;                                /*indice boucle while à vrai*/
    MLV_create_window("Tetris","Tetris-like",width,height);/*vréer le fenêtre*/
    MLV_enable_full_screen( );          /*met en plein écran*/
    createWindow();

    while(i){
        MLV_wait_mouse(&x,&y);
        if (x>(300*width/1000) && x<(700*width/1000) && y>(400*height/1000) && y<(500*height/1000)){
            /*prends les cordonées de la case pour lancer une game et lance si on clique*/
            setGameWindow(p);
            MLV_clear_window( MLV_COLOR_BLACK );
            createWindow();
        }
        if (x>(350*width/1000) && x<(650*width/1000) && y>(550*height/1000) && y<(625*height/1000)){
            /*prends les cordonées de la case pour charger une game et lance si on clique*/
            setSaveMenu(1,p);
            MLV_clear_window( MLV_COLOR_BLACK );
            createWindow();
        }
        if (x>(350*width/1000) && x<(650*width/1000) && y>(675*height/1000) && y<(750*height/1000)){
            /*prends les cordonné de case option et lance si on clique*/
            option();
        }
        if (x>(350*width/1000) && x<(650*width/1000) && y>(800*height/1000) && y<(875*height/1000)){
            i=0; /*prends les cordonné de case exit et met i à faux si on clique*/
        }
        MLV_actualise_window(); /*actualise la fenêtre*/
    }
    MLV_free_window(); /*ferme la fenêtre*/
}



#endif /*_MAINWINDOW_C_*/
