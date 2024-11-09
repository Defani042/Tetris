/*librairi standart*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>

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
  printf("Affichage : \n");
  printPlateau(pp);
  /*remplissage des lignes  1, 2, 3, 5*/
  filledline(pp,1);
  filledline(pp,2);
  filledline(pp,3);
  filledline(pp,5);
  
  printf("Affichage du tableau remplie : \n");
  printPlateau(pp);

  printf("Tableau aprés 1er vérification : \n");
  lineclear = checkPlateauState(pp);
  printf("%d ligne clear \n",lineclear);
  printPlateau(pp);

   printf("Tableau aprés seconde vérification : \n");
  lineclear = checkPlateauState(pp);
  printf("%d ligne clear \n",lineclear);
  printPlateau(pp);
  
/*Test MainWindows*/  
  SetMainWindow();
  exit(EXIT_SUCCESS);
}
