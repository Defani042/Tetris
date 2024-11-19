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
  piece p1,p2;
  piece *pp1 = &p1;
  piece *pp2 = &p2;

  setPieceLine(pp1);
  setPieceSquare(pp2);



  
  printf("p1 :\n");
  printpiece(pp1);
  printf("p2 : \n");
  printpiece(pp2);

  printf("p1 aprés rotation : \n");
  rotate_anticlockwise(pp1);
  printpiece(pp1);
  
  
  printf("p2 aprés rotation : \n");
  rotate_anticlockwise(pp2);
  printpiece(pp2);
  
/*Test MainWindows*/  
  SetMainWindow();
  exit(EXIT_SUCCESS);
}
