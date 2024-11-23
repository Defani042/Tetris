#ifndef _GAMEWINDOW_C_
#define _GAMEWINDOW_C_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <time.h>

/*local lib*/
#include "gameWindow.h"
#include "save.h"
#include "plateau.h"

/*Macro*/
#define LARGEUR_P 10
#define LONGUEUR_P 22

/*
R: créer la fenetre de jeu
E: taille x et y de la fenetre
S: rien
*/

void createGameWindow(int w,int h){
    int t;
    MLV_Font* font = MLV_load_font( "../fich/04B_30__.TTF" , 20 );
    t=30;
    MLV_clear_window( MLV_COLOR_BLACK );
    MLV_draw_rectangle((w/2)-(5*t)-5,(h/2)-(11*t)-1,t*10+11,t*22+23,MLV_COLOR_WHITE); /*contour grille*/
    MLV_draw_rectangle((w/20)*13-1,(h/20)*2-1,t*4+5,t*4+5,MLV_COLOR_BLUE);                 /*contour prochaine pièce*/
    MLV_draw_filled_rectangle(w/10,h/10,100,30,MLV_COLOR_BLUE);          /*carré pause*/                   
    MLV_draw_text_with_font(
        (w/10)+5, h/10 +5,
        "PAUSE  ESC", 
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        (w/20)*13+25, h/20,
        "NEXT", 
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        (w/20)*16, h/2-100,
        "SCORE", 
        font, MLV_COLOR_WHITE
    );
}

/*
R: créer la fenetre de pause
E: taille x et y de la fenetre
S: rien
*/

void stopWindow(int w, int h){
    MLV_Font* font = MLV_load_font( "../fich/04B_30__.TTF" , 30 );
    MLV_draw_filled_rectangle(w/5,h/5,(w/5)*3,(h/10)*7,MLV_COLOR_BLACK);     /*carré pause*/
    MLV_draw_rectangle(w/5,h/5,(w/5)*3,(h/10)*7,MLV_COLOR_BLUE);             /*contour pause*/
    MLV_draw_filled_rectangle(w/2-w/10,h/2-h/10,w/5,50,MLV_COLOR_BLUE);     /*carré RESUME*/
    MLV_draw_filled_rectangle(w/2-w/10,h/2-h/10+130,w/5,50,MLV_COLOR_BLUE); /*carré SAVE */
    MLV_draw_filled_rectangle(w/2-w/10,h/2-h/10+260,w/5,50,MLV_COLOR_RED);  /*carré LEAVE*/
    MLV_draw_text_with_font(
        (w/2)-70, h/2-h/4,
        "PAUSE", 
        font, MLV_COLOR_BLUE
    );
    font = MLV_load_font( "../fich/04B_30__.TTF" , 20 );
    MLV_draw_text_with_font(
        (w/2)-45, h/2-h/10+275,
        "LEAVE", 
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        (w/2)-40, h/2-h/10+145,
        "SAVE", 
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        (w/2)-55, h/2-h/10+15,
        "RESUME", 
        font, MLV_COLOR_WHITE
    );
    MLV_actualise_window();
}

int setStopWindow(int w,int h,plateau* p){
    int x,y,i=1,j=1;
    MLV_Font* font = MLV_load_font( "../fich/04B_30__.TTF" , 20 );
    stopWindow(w,h);
    while(i){
        MLV_wait_mouse(&x,&y);
        if (x>(w/2-w/10) && x<(w/2-w/10+w/5) && y>(h/2-h/10) && y<(h/2-h/10+50)){
            i=0;
        }
        if (x>(w/2-w/10) && x<(w/2-w/10+w/5) && y>(h/2-h/10+130) && y<(h/2-h/10+50+130)){
            setSaveMenu(2,p);
            MLV_clear_window(MLV_COLOR_BLACK);
            stopWindow(w,h);

        }
        if (x>(w/2-w/10) && x<(w/2-w/10+w/5) && y>(h/2-h/10+260) && y<(h/2-h/10+50+310)){
            MLV_draw_filled_rectangle(w/5,h/5,(w/5)*3,(h/10)*7,MLV_COLOR_BLACK); /*carré exit*/
            MLV_draw_rectangle(w/5,h/5,(w/5)*3,(h/10)*7,MLV_COLOR_BLUE);         /*contour exit*/
            MLV_draw_filled_rectangle(w/5+(w/25)*3,h/2-h/10+260,(w/25)*3,50,MLV_COLOR_RED);
            /*carré yes*/
            MLV_draw_filled_rectangle(w/5+(w/25)*9,h/2-h/10+260,(w/25)*3,50,MLV_COLOR_BLUE);
            /*carré no*/

            MLV_draw_text_with_font(
                (w/2)-275, h/2-h/10+15,
                "ALL NON SAVED DATA WILL BE LOST", 
                font, MLV_COLOR_RED
            );
            MLV_draw_text_with_font(
                (w/2)-80, h/2-h/10+145,
                "CONTINUE ?", 
                font, MLV_COLOR_WHITE
            );
            MLV_draw_text_with_font(
                (w/2)-195, h/2-h/10+275,
                "YES", 
                font, MLV_COLOR_WHITE
            );
            MLV_draw_text_with_font(
                (w/2)+140, h/2-h/10+275,
                "NO", 
                font, MLV_COLOR_WHITE
            );

            MLV_actualise_window();
            j=1;
            while (j){
                MLV_wait_mouse(&x,&y);
                if (x>(w/5+(w/25)*3) && x<(w/5+(w/25)*6) && y>(h/2-h/10+260) && y<(h/2-h/10+50+310)){
                        srand(time(NULL));return 0;
                }
                if (x>(w/5+(w/25)*9) && x<(w/5+(w/25)*12) && y>(h/2-h/10+260) && y<(h/2-h/10+50+310)){
                    j=0;
                }
            }
            
        }
        stopWindow(w,h);
        MLV_actualise_window();
    }
    return 1;
}

/*
R: fonc qui appelle les fonction pour créer le fenetre et bloque dans un boucle infini
E: rien
S: rien
*/

void setGameWindow(plateau *p){
    int i,width,height,j,k,t,w,h;
    i=1;
    t=30;
    srand(time(NULL));
    height = MLV_get_desktop_height();
    width = MLV_get_desktop_width();
    h=height;
    w=width;
    createGameWindow(width,height);
    MLV_actualise_window();
    while(i){
        MLV_actualise_window();
        if (MLV_get_keyboard_state(MLV_KEYBOARD_ESCAPE)== MLV_PRESSED){
            i=setStopWindow(width,height,p);
            MLV_clear_window(MLV_COLOR_BLACK);
            createGameWindow(width,height);
        }
        for(k=0;k<10;k++){
            for(j=0;j<22;j++){
                MLV_draw_filled_rectangle((w/2)-(5*t)-4+31*k,(h/2)-(11*t)+31*j,t,t,MLV_rgba(rand()%256,rand()%256,rand()%256,255));
                /*test grille*/
            }
        }
        for(k=0;k<4;k++){
            for(j=0;j<4;j++){
                MLV_draw_filled_rectangle((w/20)*13+31*k,(h/20)*2+31*j,t,t,MLV_rgba(rand()%256,rand()%256,rand()%256,255));
                /*test grille prochaine pièce*/
            }
        }   
        MLV_wait_milliseconds(33);
    }
}

#endif /*_GAMEWINDOW_C_*/