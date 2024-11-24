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
<<<<<<< HEAD
  setPlateau(pp);/*init le plateau*/
=======
plateau p;
plateau* pp = &p;
setPlateau(pp);

>>>>>>> Gaultier
  
/*Test MainWindows*/  
  SetMainWindow(pp);
  exit(EXIT_SUCCESS);
}
