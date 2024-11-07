#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

/* 
R: Permet de creer le bouton start
E: Vide
S: Vide
*/
void setButonStart(){
    MLV_draw_filled_rectangle(300,400,400,100,MLV_COLOR_GREEN);
    MLV_draw_text(300,400,"Start new game",MLV_COLOR_WHITE);
}

/* 
R: Permet de creer le bouton load
E: Vide
S: Vide
*/
void setButonLoad(){
     MLV_draw_filled_rectangle(350,550,300,75,MLV_COLOR_GREEN);
}

/* 
R: Permet de creer le bouton load
E: Vide
S: Vide
*/
void setButonOption(){
    MLV_draw_filled_rectangle(350,675,300,75,MLV_COLOR_GREEN);
}

/* 
R: Permet de creer le bouton load
E: Vide
S: Vide
*/
void setButonExit(){
    MLV_draw_filled_rectangle(900,0,100,100,MLV_COLOR_RED);
}

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
    int x,y,i;
    i=1;
    MLV_create_window("rectangle","rectangle2",1000,1000);
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

int main(){
    SetMainWindow();
    exit(EXIT_SUCCESS);
}