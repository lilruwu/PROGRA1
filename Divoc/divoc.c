#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "database.h"
#include "inout.h"



int main() {
  struct aPatient thePatients[100];
  
  char code;
  int fin=0;
  int numPatients=0;
  stripe('-', 50);
  headline("DIVOC_",'|', 50);
  stripe('-', 50);

  read_file(thePatients, &numPatients);

  do{
  fprintf (stdout, "\n\nR) Register a patient\nS) Search for a patient\nD) Discharge a patient\nL) List patients by age\nP) Mark positive\n\nX) Exit the program\n\n");
    code=get_character("RSDLPX", "Choose an option");
    
    
    switch (code){
    case 'R':
      p_register(thePatients,&numPatients);
      break;
    case 'S':
      p_search(thePatients, &numPatients);
      break;
    case 'D':
      p_discharge(thePatients, &numPatients);
      break;
    case 'L':
      p_list(thePatients, &numPatients);
      break;
    case 'P':
      p_mark(thePatients, &numPatients);
      break;
    case 'X':
      fin=p_exit(thePatients, &numPatients);
      break;
    default:
      fprintf (stdout, "You have chosen an invalid option\n");
      break;
    }
  }while(fin==0);
  return 0;
}
