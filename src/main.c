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
  piece p1;
  piece* pp1 = &p1;
  

  /*Srand*/
  srand(time(NULL));
  
/*Put the main code here*/
  setPlateau(pp);/*init le plateau*/
  printTabPiece(pp->tpiece);

/*Test MainWindows*/  
  SetMainWindow(pp);
  exit(EXIT_SUCCESS);
}
