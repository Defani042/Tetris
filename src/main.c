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
  plateau p; /* variable plateau*/
  plateau* pp = &p; /* pointeur vers la variable plateau*/ 
  
/*Test plateau*/
  printf("RAZ tableau \n");
  setPlateau(pp);
  printf("Affichage : \n");
  printPlateau(pp);
/*Test MainWindows*/  
  SetMainWindow();
  exit(EXIT_SUCCESS);
}
