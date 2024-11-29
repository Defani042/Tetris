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
<<<<<<< HEAD
  printTabPiece(pp->tpiece);

=======
  
>>>>>>> 68a50e3848acb0fc2172a14e273a4685d9e70fb1
/*Test MainWindows*/  
  SetMainWindow(pp);
  exit(EXIT_SUCCESS);
}
