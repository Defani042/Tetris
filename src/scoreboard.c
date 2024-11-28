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
S: Rienprécédent
*/

void readFich(char* filename,int tab[NB_MAX], int new_score){
    int i;
    FILE* fich;
    char line[LINE_MAX];
    i=0;    /*initialise l'indice à 0*/
    fich = fopen(filename,"a+");
    while (i<11){
        if (fich == NULL){
            tab[i]= 0; /*si le fichier n'existe pas, met 0 dans le tableau pour tous les scores*/
        }
        else{
            if (i==10){
                tab[i]=new_score;    /*ajouter le nouveau score en 11 élément de la liste des score si i==10*/
            }
            else{
                if (fgets(line,LINE_MAX,fich) == NULL) tab[i]=0; /*si il manque des ligne au fichier, met 0*/
                else tab[i]=atoi(line);   /*sinon, met l'équivalent entier du score qui est sur la ligne*/
            }                             /*je sais que atoi c argument to int mais j'ai pas d'erreur */
        }
        i++; /*augmente l'indice de 1*/
    }
    fclose(fich); /*ferme le fichier*/
}

/*
R: tri le tableau avec le nouveau score
E: nouveau score, tableau des scores
S: Rien
*/

void tri(int tab[NB_MAX]){
    int i,j,cmp;    /*initialise les indices et la variable temporaire*/
    for (i=10;i>0;i--){
        for (j=0;j<i;j++){
            if (tab[j+1]>tab[j]){ /*algorthme du tri à bulle*/
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
    i=0;        /*initialise l'indice à 0*/
    fich = fopen(filename,"w+");
    if (fich != NULL){ /*si le fich existe*/
        while (i<11){
            if (tab[i]!=0){     /*si le nombre est égal à 0, ne lecopie pas dans les scores*/
            fprintf(fich,"%d\n",tab[i]);    /*copie les scores triés dans le fichier de save*/
            }
            i++;    /*incrémente i de 1*/
        }
        fclose(fich);/*ferme le fichier*/
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
    int tab[NB_MAX]; /*defini le tableau des scores*/
    readFich("../fich/scoreboard.txt",tab,new_score); /*copie les données du fichier dans le tableau*/
    /*testaffichage(tab);*/
    tri(tab);                                         /*tri le tableau*/
    /*testaffichage(tab);*/
    printfichier("../fich/scoreboard.txt",tab);       /*met le tableau dans le fichier*/
}

/*Main de test
int main(){
    setScoreboard(12);
    exit(EXIT_SUCCESS);
}*/

#endif /*_SCOREBOARD_C_*/