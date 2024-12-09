#ifndef _SAVE_C_
#define _SAVE_C_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <time.h>

/*local lib*/
#include "save.h"
#include "plateau.h"
#include "gameWindow.h"
#include "piece.h"
#include "MainWindow.h"


/*
R: créer la fenêtre de sauvegarde finie.
E: taille écran
S: rien 
*/
void WindowCheckSave(int w, int h){
    MLV_Font* font=NULL;
    if(MLV_path_exists( FONT_PATH)){
        font = MLV_load_font( FONT_PATH, 50 );
    }
    MLV_draw_filled_rectangle(w/5,h/5,(w/5)*3,(h/5)*3,MLV_COLOR_BLACK);     /*carré*/
    MLV_draw_rectangle(w/5,h/5,(w/5)*3,(h/5)*3,MLV_COLOR_BLUE);            /*contour*/
    MLV_draw_text_with_font(
        w/2-225, h/2-25,
        "SAVE DONE !",  /*affiche SAVE DONE ! aux bonnes coordonnées*/
        font, MLV_COLOR_GREEN
    );
    MLV_actualise_window(); /*actualise la fenêtre*/
    MLV_wait_seconds(3);    /*attends 3 secondes pendant le message de save */
}

/*
R: créer une sauvegarde dans un fichier
E: plateau, nom du fichier de save
S: rien
*/

void saveInFich(plateau* p, char* filename,int score){
    int i,j;                            /*creation indices*/
    FILE* fich;
    fich = fopen(filename,"w+");        /*ouvre le fichier en w+ (donc écrase)*/
    if (fich != NULL){
        fprintf(fich,"%d\n",score);     /*copie le score dans le fichier de save*/
        for(i=0;i<LONGUEUR_P;i++){
            for(j=0;j<LARGEUR_P;j++){
                fprintf(fich,"%d ",p->plateau[i][j]);   /*copie le tableau dans le fichier de save*/
            }                                           /*alignée séparé par des espace*/
        }
        fprintf(fich,"\n%d\n",p->speed);                   /*copie la speed dans le fichier de save*/
        for(i=0;i<ROW;i++){
            for(j=0;j<COLUMN;j++){
                fprintf(fich,"%d ",p->tpiece->piece[i][j]); /*copie le tab de piéce posée dans le fichier de save*/
            }
        }
        fprintf(fich,"\n%d %d %d %d %d %d\n",p->tpiece->r,p->tpiece->g,p->tpiece->b,p->tpiece->a,p->tpiece->x,p->tpiece->y);
        /*copie la couleur et le placement x et y dans la save*/
        for(i=0;i<ROW;i++){
            for(j=0;j<COLUMN;j++){
                fprintf(fich,"%d ",p->p_cur.piece[i][j]);/*copie la tab de la pièce actuelle dans la save*/
            }
        }
        /*copie la couleur et le placement x et y dans la save*/
        fprintf(fich,"\n%d %d %d %d %d %d\n",p->p_cur.r,p->p_cur.g,p->p_cur.b,p->p_cur.a,p->p_cur.x,p->p_cur.y);
        for(i=0;i<ROW;i++){
            for(j=0;j<COLUMN;j++){
                fprintf(fich,"%d ",p->p_next.piece[i][j]);/*copie la tab de la pièce suivante dans la save*/
            }
        }
        fprintf(fich,"\n%d %d %d %d %d %d\n",p->p_next.r,p->p_next.g,p->p_next.b,p->p_next.a,p->p_next.x,p->p_next.y);
        /*copie la couleur et le placement x et y dans la save*/
        fprintf(fich,"%d",p->temps_jeu);
        fclose(fich);
    }
}

/*
R: charge une sauvegarde dans un fichier
E: plateau, nom du fichier de save
S: rien
*/

void loadInFich(plateau* p,char* filename,int id_fich){
    int i,j;    /*def indice*/
    FILE* fich;
    fich = fopen(filename,"r+"); /*ouverture en r+*/
    if (fich != NULL){
        if (fscanf(fich,"%d\n",&(p->score))==0){  /*copie du score du fich au tableau*/
            p->score=0; /*tous les .....=0 servent à ne pas mettre le warning su fscanf*/
                        /*si la valeur n'as pas été trouvée ce sera celle mise par défault*/
        }
        for(i=0;i<LONGUEUR_P;i++){
            for(j=0;j<LARGEUR_P;j++){
                if (fscanf(fich,"%d ",&(p->plateau[i][j]))==0){ /*copie des elts du tableau du fich au tableau*/
                    p->plateau[i][j]=0;
                }
            }
        }
        if (fscanf(fich,"\n%d\n",&(p->speed))!=1){ /*copie du speed du fich au tableau*/
            printf("0");
        }
        for(i=0;i<ROW;i++){
            for(j=0;j<COLUMN;j++){
                if (fscanf(fich,"%d ",&(p->tpiece->piece[i][j])) !=1){
                    printf("0");        /*copie des pièces posées du fich au tableau*/
                }
            }
        }
        if (fscanf(fich,"\n%d %d %d %d %d %d\n",&(p->tpiece->r),&(p->tpiece->g),&(p->tpiece->b),&(p->tpiece->a),&(p->tpiece->x),&(p->tpiece->y))!=6){
            printf("0"); /*copie des couleur et axes du fich au tableau*/
        }
        for(i=0;i<ROW;i++){
            for(j=0;j<COLUMN;j++){
                if (fscanf(fich,"%d ",&(p->p_cur.piece[i][j]))!=1){
                    printf("0");        /*copie de la pièce courrante du fich au tableau*/
                }
            }
        }
        if (fscanf(fich,"\n%d %d %d %d %d %d\n",&(p->p_cur.r),&(p->p_cur.g),&(p->p_cur.b),&(p->p_cur.a),&(p->p_cur.x),&(p->p_cur.y))!=6){
            printf("0");                /*copie des couleur et axes du fich au tableau*/
        }
        for(i=0;i<ROW;i++){
            for(j=0;j<COLUMN;j++){
                if (fscanf(fich,"%d ",&(p->p_next.piece[i][j]))!=1){
                    printf("0");        /*copie des couleurs et axes du fich au tableau*/
                }
            }
        }
        if (fscanf(fich,"\n%d %d %d %d %d %d\n",&(p->p_next.r),&(p->p_next.g),&(p->p_next.b),&(p->p_next.a),&(p->p_next.x),&(p->p_next.y))!=6){
            printf("0\n");/*copie des couleurs et axes du fich au tableau*/
        }
        if (fscanf(fich,"%d",&(p->temps_jeu))!=1){
                    printf("0");        /*copie du temps du fich au tableau*/
                }
        fclose(fich);
        switch(id_fich){
            case 1: setGameWindow(p,1);break;/*lance le jeu*/
            case 2: setGameWindow(p,2);break;
            case 3: setGameWindow(p,3);break;
            case 4: setGameWindow(p,4);break;
            default:setGameWindow(p,0);break;
        }
    }
}

/*
R: creer les bouttons sauvegarde
E: longueur ecran,hauteur ecran
S: rien
*/

void setSaveButton(int width, int height){
    int w,h;
    MLV_Font* font=NULL;
    MLV_clear_window( MLV_COLOR_BLACK );
    if(MLV_path_exists( FONT_PATH)){
        font = MLV_load_font(  FONT_PATH, 50 );    
    }
    drawCarreAuxBordArrondis(width*3/20,(height/40)*5,(width*6)/20,(height*6)/20,10,MLV_COLOR_BLUE);
    w=(200*width)/1000;                                 /*créer le carré pour les fichier de save*/
    h=(150*height)/1000;
    MLV_draw_text_with_font(
        w, h,
        "FILE 1",       
        font, MLV_COLOR_WHITE
    );      /*ecrit le fichier et le score au bon endroit */
    MLV_draw_text_with_font(
        w, h+50,
        "SCORE:", 
        font, MLV_COLOR_WHITE
    );
    w=((600*width)/1000);
    drawCarreAuxBordArrondis((width*11)/20,(height/40)*5,(width*6)/20,(height*6)/20,10,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        w, h,
        "FILE 2", 
        font, MLV_COLOR_WHITE
    );/*ecrit le fichier et le score au bon endroit */
    MLV_draw_text_with_font(
        w, h+50,
        "SCORE:", 
        font, MLV_COLOR_WHITE
    );
    h=(550*height)/1000;
    drawCarreAuxBordArrondis((width*11)/20,(height/40)*21,(width*6)/20,(height*6)/20,10,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        w, h,
        "FILE 4", 
        font, MLV_COLOR_WHITE
    );/*ecrit le fichier et le score au bon endroit */
    MLV_draw_text_with_font(
        w, h+50,
        "SCORE:", 
        font, MLV_COLOR_WHITE
    );
    w=(200*width)/1000;
    drawCarreAuxBordArrondis(width*3/20,(height/40)*21,(width*6)/20,(height*6)/20,10,MLV_COLOR_BLUE);
    MLV_draw_text_with_font(
        w, h,
        "FILE 3", 
        font, MLV_COLOR_WHITE
    );/*ecrit le fichier et le score au bon endroit */
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
    MLV_Font* font=NULL;
    w1=(350*w)/1000;    /*prends toutes les coordonnées h pour hauteur, w pour largeur et p pour police*/
    w2=(300*w)/1000;
    w3=(455*w)/1000;
    h1=(900*h)/1000;
    h2=(75*h)/1000;
    h3=(920*h)/1000;
    p=(25*w)/1000;
    if(MLV_path_exists( FONT_PATH)){
        font = MLV_load_font( FONT_PATH , p );
    }
    drawCarreAuxBordArrondis(w1,h1,w2,h2,10,MLV_COLOR_BLUE); /*crrer le carré du bouton back*/
    MLV_draw_text_with_font(
        w3, h3,
        "BACK",  /*affiche le back */
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
    MLV_Font* font=NULL;
    FILE* fich;
    char line[LINE_MAX];
    w1=0;
    w2=0;   /*initialise à 0 toutes les variables*/
    h1=0;
    h2=0;
    if(MLV_path_exists( FONT_PATH)){
        font = MLV_load_font( FONT_PATH , 50 );
    }
    switch (num_save){
        case 1: w1=w*210/1000;h1=h*325/1000;w2=w*245/1000;h2=h*325/1000;break;
        case 2: w1=w*610/1000;h1=h*325/1000;w2=w*645/1000;h2=h*325/1000;break;
        case 3: w1=w*210/1000;h1=h*725/1000;w2=w*245/1000;h2=h*725/1000;break;
        case 4: w1=w*610/1000;h1=h*725/1000;w2=w*645/1000;h2=h*725/1000;break;
    }       /*change la valeur des indices de hauteur et de largeur en fonc du fichier correspondant*/
    fich = fopen(fichier,"a+");
    if (fich == NULL){
        MLV_draw_text_with_font(
			    w1-55, h1,
			    "not found",        /*affiche not found si le fichier est inextant*/
			    font, MLV_COLOR_RED
			    );
    }
    else{
        if (fgets(line,LINE_MAX,fich) == NULL){
                MLV_draw_text_with_font(
			        w1, h1,
			        "EMPTY",        /*affiche empty si le fichier est vide*/
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
			            line,       /*affiche la ligne de score du fichier qd elle existe*/
			            font, MLV_COLOR_WHITE
			            );
            fclose(fich);
        }
    }
}

/*
R: créer les boutons de la fenetre sauvegarde
E: taille de l'écran
S: rien
*/

void createAllSaveMenu(int width,int height){
    setSaveButton(width,height);
    setButonBack(width,height);
    saveScore(width,height,FILE1,1); /*créer la fenêtre du bouton corespondant*/
    saveScore(width,height,FILE2,2);
    saveScore(width,height,FILE3,3);
    saveScore(width,height,FILE4,4);
    MLV_actualise_window();
}

/*
R: créer la fenetre sauvegarde
E: rien
S: rien
*/

void setSaveMenu(int page, plateau* p){
    int i,width,height,x,y; /*x et y sont la position de la souris*/
    height = MLV_get_desktop_height();
    width = MLV_get_desktop_width();
    createAllSaveMenu(width,height);
    i=1;        /*met i à vrai*/
    while (i){
        MLV_wait_mouse(&x,&y);
            if (x>(width*3/20) && x<(width*3/20+((width*6)/20)) && y>((height/40)*5) && y<((height/40)*5+((height*6)/20))){
                if (page == 1){ /*si on clique sur le bouton de la save 1*/
                    /*si depuis le menu savgarde du menu pricipale, alors lance le jeu avec les bonnes données*/
                    loadInFich(p,FILE1,1);
                    MLV_clear_window(MLV_COLOR_BLACK);
                    createAllSaveMenu(width,height);
                }
                else {
                    /*si depuis le menu save du jeu, alors sauvegarde la game*/
                    saveInFich(p,FILE1,p->score);
                    WindowCheckSave(width,height);
                    MLV_clear_window(MLV_COLOR_BLACK);
                    createAllSaveMenu(width,height);
                }
            }
            if (x>(width*11/20) && x<(width*11/20+((width*6)/20)) && y>((height/40)*5) && y<((height/40)*5+((height*6)/20))){
                if (page == 1){ /*si on clique sur le bouton de la save 2*/
                    /*si depuis le menu savgarde du menu pricipale, alors lance le jeu avec les bonnes données*/
                    loadInFich(p,FILE2,2);
                    MLV_clear_window(MLV_COLOR_BLACK);
                    createAllSaveMenu(width,height);
                }
                else {
                    /*si depuis le menu save du jeu, alors sauvegarde la game*/
                    saveInFich(p,FILE2,p->score);
                    WindowCheckSave(width,height);
                    MLV_clear_window(MLV_COLOR_BLACK);
                    createAllSaveMenu(width,height);
                }
            }
            if (x>(width*3/20) && x<(width*3/20+((width*6)/20)) && y>((height/40)*21) && y<((height/40)*21+((height*6)/20))){
                if (page == 1){ /*si on clique sur le bouton de la save 3*/
                    /*si depuis le menu savgarde du menu pricipale, alors lance le jeu avec les bonnes données*/
                    loadInFich(p,FILE3,3);
                    MLV_clear_window(MLV_COLOR_BLACK);
                    createAllSaveMenu(width,height);
                }
                else {
                    /*si depuis le menu save du jeu, alors sauvegarde la game*/
                    saveInFich(p,FILE3,p->score);
                    WindowCheckSave(width,height);
                    MLV_clear_window(MLV_COLOR_BLACK);
                    createAllSaveMenu(width,height);
                }
            }
            if (x>(width*11/20) && x<(width*11/20+((width*6)/20)) && y>(height/40)*21 && y<(((height/40)*21+(height*6)/20))){
                if (page == 1){ /*si on clique sur le bouton de la save 4*/
                    /*si depuis le menu savgarde du menu pricipale, alors lance le jeu avec les bonnes données*/
                    loadInFich(p,FILE4,4);
                    MLV_clear_window(MLV_COLOR_BLACK);
                    createAllSaveMenu(width,height);
                }
                else {
                    /*si depuis le menu save du jeu, alors sauvegarde la game*/
                    saveInFich(p,FILE4,p->score);
                    WindowCheckSave(width,height);
                    MLV_clear_window(MLV_COLOR_BLACK);
                    createAllSaveMenu(width,height);
                }
            }
            if (x>(350*width/1000) && x<(650*width/1000) && y>(900*height/1000) && y<(975*height/1000)){
                /*si on clique sur le bouton back, alors i = faux et fait revenir sur l'écran précédent*/
            i=0;
        }
        MLV_actualise_window(); /*actualise la fenêtre*/
    }
}

#endif /*_SAVE_C_*/
