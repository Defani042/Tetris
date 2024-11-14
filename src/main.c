/*librairie standart*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <unistd.h>/*permet de faire des sleep*/

/*librairie local*/
#include "plateau.h"
#include "MainWindow.h"

int main(){
/*Put the main code here*/
/*variable*/
  int lineclear = 0;
  plateau p; /* variable plateau*/
  plateau* pp = &p; /* pointeur vers la variable plateau*/ 
  
/*Test plateau*/
  printf("RAZ tableau \n");
  setPlateau(pp);
  printf("\033[H\033[J");
  printf("1) Affichage : \n");
  printf("\n");
  printPlateau(pp);
  sleep(5);
  printf("\033[H\033[J");
  
  /*remplissage des lignes  1, 2, 3, 5*/
  filledline(pp,1);
  filledline(pp,2);
  filledline(pp,3);
  filledline(pp,5);
  setcase(pp,6,5,1);
  setcase(pp,6,6,1);
  setcase(pp,7,1,1);
  setcase(pp,7,9,1);
  
  printf("2) Affichage du tableau remplie : \n");
  printf("\n");
  printPlateau(pp);
  sleep(5);
  printf("\033[H\033[J");

  

  printf("3) Tableau aprés 1er vérification : \n");
  lineclear = checkPlateauState(pp);
  printf("%d ligne clear \n",lineclear);
  printPlateau(pp);
  sleep(5);
  printf("\033[H\033[J");
   
  printf("4) Tableau aprés seconde vérification : \n");
  lineclear = checkPlateauState(pp);
  printf("%d ligne clear \n",lineclear);
  printPlateau(pp);
  sleep(5);
  printf("\033[H\033[J");
  
/*Test MainWindows*/  
  SetMainWindow();
  exit(EXIT_SUCCESS);
}
