/*librairie standart*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <unistd.h>/*permet de faire des sleep*/
#include <time.h> 


/*librairie local*/
#include "plateau.h"
#include "MainWindow.h"
#include "piece.h"

int main(){
/*Variable*/

  plateau p;
  plateau* pp = &p;


  /*Srand*/
  srand(time(NULL));
  
/*Put the main code here*/
  setPlateau(pp);/*init le plateau*/
  printf("salut je viens d'init le tab\n");
  printPlateau(pp);

/*Test MainWindows*/
  printf("avant de set la mainwindows\n");
  SetMainWindow(pp);
  exit(EXIT_SUCCESS);
}
