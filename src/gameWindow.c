#ifndef _GAMEWINDOW_C_
#define _GAMEWINDOW_C_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <MLV/MLV_all.h>
#include <time.h>

/*local lib*/
#include "gameWindow.h"
#include "save.h"
#include "plateau.h"
#include "piece.h"

/*Macro*/

/*
R : affiche le plateau avec MLV
E : pointeur vers plateau, taille case (t), taille de l'ecran
S : rien
*/

void afficherPlateau(plateau *p,int t,int w,int h){
    int k,j;
    printf("intégration de la piece \n");
    integratePiece(p);
    for(k=2;k<LARGEUR_P-2;k++){
            for(j=2;j<LONGUEUR_P-2;j++){
                if (p->plateau[j][k]>0){
		  MLV_draw_filled_rectangle((w/2)-(5*t)-4+(t+1)*(k-2),(h/2)-(11*t)+(t+1)*(j-2),t,t,MLV_rgba(p->p_cur.r,p->p_cur.g,p->p_cur.b,p->p_cur.a));
                }
                else {
		  MLV_draw_filled_rectangle((w/2)-(5*t)-4+(t+1)*(k-2),(h/2)-(11*t)+(t+1)*(j-2),t,t,MLV_rgba(10,10,10,255));
                }
            }
        }

    for(k=0;k<ROW;k++){
        for(j=0;j<COLUMN;j++){
            if (p->p_next.piece[j][k]>0){
                MLV_draw_filled_rectangle((w/20)*13+(t+1)*k,(h/20)*2+(t+1)*j,t,t,MLV_rgba(p->p_next.r,p->p_next.g,p->p_next.b,p->p_next.a));
            }
            else {
                MLV_draw_filled_rectangle((w/20)*13+(t+1)*k,(h/20)*2+(t+1)*j,t,t,MLV_rgba(10,10,10,255));
            }
        }
    }
}

/*
R: affiche le temps 
E: temps en hh:mm:ss en tableau de char et le font
S: rien
*/

void printTime(char* t,MLV_Font* font){
    int h = MLV_get_desktop_height();  /*recupere la taille de l'ecran*/
    int w = MLV_get_desktop_width();
    MLV_draw_filled_rectangle((w/20)*2, h/3+20,(w/20)*2,25,MLV_COLOR_BLACK);
        MLV_draw_text_with_font(
            (w/20)*2, h/3+25,
            t,         /*affiche le temps aux bonnes coordonnées*/
            font, MLV_COLOR_WHITE
        );

}

/*
R: créer la fenêtre de jeu
E: taille de l'ecran
S: rien
*/

void createGameWindow(int w,int h){
    int t;
    MLV_Font* font=NULL;
    if(MLV_path_exists( FONT_PATH)){
        font = MLV_load_font(FONT_PATH, 20 );
    }
    t=h/24;
    MLV_clear_window( MLV_COLOR_BLACK );
    MLV_draw_rectangle((w/2)-(5*t)-5,(h/2)-(11*t)-1,t*10+11,t*22+23,MLV_COLOR_WHITE); /*contour grille*/
    MLV_draw_rectangle((w/20)*13-1,(h/20)*2-1,t*4+5,t*4+5,MLV_COLOR_BLUE);                 /*contour prochaine pièce*/
    MLV_draw_filled_rectangle(w/10,h/10,100,30,MLV_COLOR_BLUE);          /*carré pause*/                   
    MLV_draw_text_with_font(
        (w/10)+5, h/10 +5,
        "PAUSE  ESC", /*affiche PAUSE et ESC aux bonnes coordonnées*/
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        (w/20)*13+25, h/20,
        "NEXT",         /*affiche NEXT aux bonnes coordonnées*/
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        (w/20)*2, h/3,
        "TIME",         /*affiche TIME aux bonnes coordonnées*/
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        (w/20)*16, h/2-100,
        "SCORE",        /*affiche SCORE aux bonnes coordonnées*/
        font, MLV_COLOR_WHITE
    );
}

/*
R: créer la fenetre de pause
E: taille x et y de la fenetre
S: rien
*/

void stopWindow(int w, int h){
    MLV_Font* font=NULL;
    if(MLV_path_exists( FONT_PATH)){
        font = MLV_load_font(  FONT_PATH , 30 );
    }
    MLV_draw_filled_rectangle(w/5,h/5,(w/5)*3,(h/10)*7,MLV_COLOR_BLACK);     /*carré pause*/
    MLV_draw_rectangle(w/5,h/5,(w/5)*3,(h/10)*7,MLV_COLOR_BLUE);             /*contour pause*/
    MLV_draw_filled_rectangle(w/2-w/10,h/2-h/10,w/5,50,MLV_COLOR_BLUE);     /*carré RESUME*/
    MLV_draw_filled_rectangle(w/2-w/10,h/2-h/10+130,w/5,50,MLV_COLOR_BLUE); /*carré SAVE */
    MLV_draw_filled_rectangle(w/2-w/10,h/2-h/10+260,w/5,50,MLV_COLOR_RED);  /*carré LEAVE*/
    MLV_draw_text_with_font(
        (w/2)-70, h/2-h/4,
        "PAUSE",    /*affiche PAUSE aux bonnes coordonnées*/
        font, MLV_COLOR_BLUE
    );
    font = MLV_load_font(  FONT_PATH, 20 );
    MLV_draw_text_with_font(
        (w/2)-45, h/2-h/10+275,
        "LEAVE",    /*affiche LEAVE aux bonnes coordonnées*/
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        (w/2)-40, h/2-h/10+145,
        "SAVE",     /*affiche SAVE aux bonnes coordonnées*/
        font, MLV_COLOR_WHITE
    );
    MLV_draw_text_with_font(
        (w/2)-55, h/2-h/10+15,
        "RESUME",   /*affiche RESUME aux bonnes coordonnées*/
        font, MLV_COLOR_WHITE
    );
    MLV_actualise_window();
}

/*
R: créer le menu pause
E: taille de l'écran et le plateau
S: rien
*/

int setStopWindow(int w,int h,plateau* p){
    int x,y,i=1,j=1; /*initialise i et j à vrai*/
    MLV_Font* font=NULL;
    if(MLV_path_exists( FONT_PATH)){
        font = MLV_load_font(  FONT_PATH , 20 );
    }
    stopWindow(w,h);
    while(i){
        MLV_wait_mouse(&x,&y);
        if (x>(w/2-w/10) && x<(w/2-w/10+w/5) && y>(h/2-h/10) && y<(h/2-h/10+50)){
            i=0;    /*si on clique sur RESUME alors i = faux */
        }
        if (x>(w/2-w/10) && x<(w/2-w/10+w/5) && y>(h/2-h/10+130) && y<(h/2-h/10+50+130)){
            setSaveMenu(2,p);
            MLV_clear_window(MLV_COLOR_BLACK);
            stopWindow(w,h);
            /*si on clique sur SAVE alors ouvre le menu de sauvegarde */

        }
        if (x>(w/2-w/10) && x<(w/2-w/10+w/5) && y>(h/2-h/10+260) && y<(h/2-h/10+50+310)){
            /*si on clique sur EXIT alors ouvre le menu de confirmation pour quitter */
            MLV_draw_filled_rectangle(w/5,h/5,(w/5)*3,(h/10)*7,MLV_COLOR_BLACK); /*carré exit*/
            MLV_draw_rectangle(w/5,h/5,(w/5)*3,(h/10)*7,MLV_COLOR_BLUE);         /*contour exit*/
            MLV_draw_filled_rectangle(w/5+(w/25)*3,h/2-h/10+260,(w/25)*3,50,MLV_COLOR_RED);
            /*carré yes*/
            MLV_draw_filled_rectangle(w/5+(w/25)*9,h/2-h/10+260,(w/25)*3,50,MLV_COLOR_BLUE);
            /*carré no*/

            MLV_draw_text_with_font(
                (w/2)-275, h/2-h/10+15,
                "ALL NON SAVED DATA WILL BE LOST",  /*affichage aux bonne coordonnées*/
                font, MLV_COLOR_RED
            );
            MLV_draw_text_with_font(
                (w/2)-80, h/2-h/10+145,
                "CONTINUE ?",                       /*affichage aux bonne coordonnées*/
                font, MLV_COLOR_WHITE
            );
            MLV_draw_text_with_font(
                w/5+(w/25)*4, h/2-h/10+275,
                "YES",                              /*affichage aux bonne coordonnées*/
                font, MLV_COLOR_WHITE
            );
            MLV_draw_text_with_font(
                w/5+(w/25)*10+w/200, h/2-h/10+275,
                "NO",                               /*affichage aux bonne coordonnées*/
                font, MLV_COLOR_WHITE
            );

            MLV_actualise_window();
            j=1;
            while (j){
                MLV_wait_mouse(&x,&y);
                if (x>(w/5+(w/25)*3) && x<(w/5+(w/25)*6) && y>(h/2-h/10+260) && y<(h/2-h/10+50+310)){
                        srand(time(NULL));return 0;
                        /*si on clique sur yes, alors reviens au menu proncipale ou à la save*/
                }
                if (x>(w/5+(w/25)*9) && x<(w/5+(w/25)*12) && y>(h/2-h/10+260) && y<(h/2-h/10+50+310)){
                        /*si on clique sur no, reviens au menu pause*/
                    j=0;/*j passe à faux*/
                }
            }
            
        }
        stopWindow(w,h);    /*lance la fonc pour afficher le menu pause*/
        MLV_actualise_window(); /*actualise la fenêtre*/
    }
    return 1;
}

/*
R: fonc qui appelle les fonction pour créer le fenetre et bloque dans un boucle infini
E: rien
S: rien
*/

void setGameWindow(plateau *p){
    int i,width,height,t,hours,minutes,seconds;
    struct timespec debut, fin,debut_jeu,mid_jeu,tmp_pause_deb,tmp_pause_fin;
    MLV_Font* font=NULL;
    char text[32];
    int unsigned temps,temps_pause;
    temps_pause=0;
    if(MLV_path_exists( FONT_PATH)){
        font = MLV_load_font( FONT_PATH , 20 );
    }
    i=1;
    srand(time(NULL));
    height = MLV_get_desktop_height();  /*recupere la taille de l'ecran*/
    width = MLV_get_desktop_width();
    t=height/24;                             /*taille des carré de Tetris par rapport à la hauteur de l'écran*/
    createGameWindow(width,height);
    MLV_actualise_window();
    clock_gettime(CLOCK_REALTIME, &debut_jeu);
    while(i){
        MLV_actualise_window();
        clock_gettime(CLOCK_REALTIME, &debut);
        if (MLV_get_keyboard_state(MLV_KEYBOARD_ESCAPE)== MLV_PRESSED){
            clock_gettime(CLOCK_REALTIME, &tmp_pause_deb);
            /*si on appuie sur echap, alors on ouvre le menu pause*/
            i=setStopWindow(width,height,p);
            MLV_clear_window(MLV_COLOR_BLACK);
            createGameWindow(width,height);
            clock_gettime(CLOCK_REALTIME, &tmp_pause_fin);
            temps_pause+=(((tmp_pause_fin.tv_sec*1000)+(tmp_pause_fin.tv_nsec/1000000))-((tmp_pause_deb.tv_sec*1000)+(tmp_pause_deb.tv_nsec/1000000)));
        }
        afficherPlateau(p,t,width,height);
        /*partie par rapport au temps*/
        clock_gettime(CLOCK_REALTIME, &mid_jeu);
        temps = (((mid_jeu.tv_sec*1000)+(mid_jeu.tv_nsec/1000000))-((debut_jeu.tv_sec*1000)+(debut_jeu.tv_nsec/1000000)));
        temps -=temps_pause;
        temps/=1000;
        hours = temps / 3600;
        minutes = (temps % 3600) / 60;
        seconds = temps % 60;
        sprintf(text, "%02d:%02d:%02d", hours, minutes, seconds); /* Met un texte avec des int dans une variable "string"*/
        printTime(text,font);
        clock_gettime(CLOCK_REALTIME, &fin);
        if((1000/30)-(((fin.tv_sec*1000)+(fin.tv_nsec/1000000))-((debut.tv_sec*1000)+(debut.tv_nsec/1000000)))>0) MLV_wait_milliseconds((1000/30)-(((fin.tv_sec*1000)+(fin.tv_nsec/1000000))-((debut.tv_sec*1000)+(debut.tv_nsec/1000000))));
    }
}

#endif /*_GAMEWINDOW_C_*/
