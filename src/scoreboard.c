#ifndef _SCOREBOARD_C_
#define _SCOREBOARD_C_

/*std lib*/
#include <stdlib.h>
#include <stdio.h>

/*local lib*/
#include "scoreboard.h"

/*Macro*/
#define NB_MAX 15
#define LINE_MAX 32

/*
R: Met dans les tableau les scores actuels.
E: Nom du fichier, tableau des éléments, nouvel element
S: Rien
*/

void readFich(char* filename,int tab[NB_MAX], int new_score){
    int i;
    FILE* fich;
    char line[LINE_MAX];
    i=0;
    fich = fopen(filename,"a+");
    while (i<11){
        if (fich == NULL){
            tab[i]= -1;
        }
        else{
            if (i==10){
                tab[i]=new_score;
            }
            else{
                if (fgets(line,LINE_MAX,fich) == NULL) tab[i]=0;
                else tab[i]=atoi(line);
            }
        }
        i++;
    }
    fclose(fich);
}

/*
R: tri le tableau avec le nouveau score
E: nouveau score, tableau des scores
S: Rien
*/

void tri(int tab[NB_MAX]){
    int i,j,cmp;
    for (i=10;i>0;i--){
        for (j=0;j<i;j++){
            if (tab[j+1]>tab[j]){
                cmp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=cmp;
            }
        }
    }
}

/*
R: met le tableau trié dans le fichier
E: nom du fichier, tableau de score
S: rien
*/
void printfichier(char* filename,int tab[NB_MAX]){
    int i;
    FILE* fich;
    i=0;
    fich = fopen(filename,"w+");
    if (fich != NULL){
        while (i<11){
            if (tab[i]!=0){
            fprintf(fich,"%d\n",tab[i]);
            }
            i++;
        }
        fclose(fich);
    }
}

/*
Fonction test


void testaffichage(int tab[NB_MAX]){
    int i=0;
    while (i<11){
        printf("%d ",tab[i]);
        i++;
    }
    printf("\n");
}
*/

/*
R: fonction principale du programme
E: nouveau score
S: rien
*/

void setScoreboard(int new_score){
    int tab[NB_MAX];
    readFich("../fich/scoreboard.txt",tab,new_score);
    /*testaffichage(tab);*/
    tri(tab);
    /*testaffichage(tab);*/
    printfichier("../fich/scoreboard.txt",tab);
}

/*Main de test
int main(){
    setScoreboard(12);
    exit(EXIT_SUCCESS);
}*/

#endif /*_SCOREBOARD_C_*/