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

/*
R: créer la fenetre de jeu
E: taille x et y de la fenetre
S: rien
*/

void createGameWindow(int w,int h){
    int t,i,j;
    MLV_Font* font = MLV_load_font( "../fich/04B_30__.TTF" , 20 );
    t=30;
    MLV_clear_window( MLV_COLOR_BLACK );
    MLV_draw_rectangle((w/2)-(5*t)-5,((h/20)*9)-(11*t)-1,t*10+11,t*22+23,MLV_COLOR_WHITE);
    MLV_draw_rectangle((w/20)*13-1,(h/20)*2-1,t*4+5,t*4+5,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        (w/20)*13+25, h/20,
        "NEXT", 
        font, MLV_COLOR_WHITE
    );
    for(i=0;i<10;i++){
        for(j=0;j<22;j++){
            MLV_draw_filled_rectangle((w/2)-(5*t)-4+31*i,((h/20)*9)-(11*t)+31*j,t,t,MLV_rgba(rand()%256,rand()%256,rand()%256,255));
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            MLV_draw_filled_rectangle((w/20)*13+31*i,(h/20)*2+31*j,t,t,MLV_rgba(rand()%256,rand()%256,rand()%256,255));
        }
    }
}

/*
R: fonc qui appelle les fonction pour créer le fenetre et bloque dans un boucle infini
E: rien
S: rien
*/

void setGameWindow(){
    int i,width,height,x,y;
    i=1;
    srand(time(NULL));
    height = MLV_get_desktop_height();
    width = MLV_get_desktop_width();
    createGameWindow(width,height);
    MLV_actualise_window();
    while(i){
        MLV_wait_mouse(&x,&y);
        MLV_actualise_window();
    }
}

#endif /*_GAMEWINDOW_C_*/