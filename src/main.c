/*librairie standart*/
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <unistd.h>/*permet de faire des sleep*/

/*librairie local*/
#include "plateau.h"
#include "MainWindow.h"
#include "piece.h"

int main(){
/*Put the main code here*/
plateau p;
plateau* pp = &p;
setPlateau(pp);

  
/*Test MainWindows*/  
  SetMainWindow(pp);
  exit(EXIT_SUCCESS);
}
