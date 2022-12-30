#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "database.h"
#include "inout.h"

int read_file(struct aPatient *table, int *number){
  char string[256];
  FILE *patients;
  patients=fopen("patients.txt","r"); 
  if (patients!=NULL){
   while((fgets (string, sizeof(string), patients)) != NULL) {
    sscanf(string, "%s%s%d%d%d %c", table[*number].N, table[*number].DNI, &table[*number].date, &table[*number].fever, &table[*number].cough, &table[*number].symptoms);
    (*number)++;
  }
   fclose(patients); } 
  return 0;
  }
  
  
  
void p_register(struct aPatient *table, int *number){
  int return_verify_DNI = 1;
  char N[25];
  char DNI[10];
  fprintf(stdout,"Register\n");
  fprintf (stdout, "\n");

  get_string("Name (1-24 char):  ",N, 1, 24);
  strcpy(table[*number].N, N);
  
  do {
  get_string("DNI (9-9 char):  ", DNI, 9, 9);
  return_verify_DNI = verify_DNI(DNI);
  }while(return_verify_DNI==0);
  strcpy(table[*number].DNI, DNI);

  table[*number].date = get_integer(1900, 2020, "Date[1900-2020]: ");

  table[*number].fever = yes_or_no("Fever (y/n): ");

  table[*number].cough = yes_or_no("Cough (y/n): ");

  table[*number].symptoms = get_character("FSTMN", "Symptom");
    
  fprintf(stdout, "New patient:\n");
  display_patient(table[*number]);
    
  (*number)++;
}

int p_search(struct aPatient *table, int *number) {
  char DNI_search[10];
  int i=0;  
  fprintf(stdout,"Search\n");
  fprintf (stdout, "\n");

  if (*number==0) {
    fprintf (stdout, "No patients yet\n");
  }
   
  else {
     get_string("DNI (9-9 char): ", DNI_search, 9, 9);
     for(i=0;i<*number;i++){
      if (strcmp(DNI_search, table[i].DNI)==0){
	fprintf(stdout, "Patient data:\n");
	display_patient(table[i]);
	return 0;
     }
    }
     fprintf(stdout, "Unknown patient\n");
   }
  return 0;
  }

int p_discharge(struct aPatient *table, int *number) {
  char DNI_discharge[10];
  int i=0;
  int j=0;
  
  fprintf(stdout,"Discharge\n");
  fprintf (stdout, "\n");
  
  if (*number==0) {
    fprintf(stdout, "No patients yet\n");
  }
    
  else {
    get_string("DNI (9-9 char): ", DNI_discharge, 9, 9);
    for(i=0;i<*number;i++) {
      if (strcmp(DNI_discharge, table[i].DNI)==0){
        for (j=i;j<((*number)-1);j++) {
	table[j]=table[j+1];
        }
         (*number)--;
        fprintf (stdout, "Discharged patient\n");
        return 0;
      }
    }
  fprintf(stdout, "Unknown patient\n");
  }
  return 0;
}

int p_list(struct aPatient *table, int *number) {
  int date=0;
  int i;
  fprintf(stdout, "List\n");
  fprintf (stdout, "\n");
  if (*number==0) {
    fprintf (stdout, "No patients yet\n");
  }
  if (*number!=0) {
    date=get_integer(1900, 2020, "Date [1900-2020]: ");
    fprintf (stdout, "Patients born before %d:\n", date);
    for(i=0;i<*number;i++){
      if (date>=table[i].date){
        display_patient(table[i]);
      }
    }
  }

  return 0;
}

int p_mark(struct aPatient *table, int *number){
  int i;
  fprintf (stdout, "Positives\n");
  fprintf (stdout, "\n");
  if (*number!=0) {
    fprintf (stdout, "Positive patients:\n");
    for(i=0;i<*number;i++){
      if ((table[i].fever==1)&&(table[i].cough==1)&&(table[i].symptoms!='N')){
      display_patient(table[i]);
      }
    }
  }
  else{
    fprintf(stdout, "No patients yet\n");
  }
  return 0;
}



int p_exit(struct aPatient *table, int *number) {
  int i;
  FILE *patients;
  int return_yes_or_no;
  
  fprintf (stdout, "Exit\n");
  fprintf (stdout, "\n");
  
  return_yes_or_no=yes_or_no("Are you sure you want to exit the program? (y/n): ");


  if(return_yes_or_no==0) {
    return 0;
     
  }
  patients=fopen("patients.txt", "w");
  
  if (*number==0) {
    fclose(patients);
    return 1;
  }
  for(i=0;i<*number;i++){
  fprintf(patients, "%s %s %d %d %d %c\n", table[i].N, table[i].DNI, table[i].date, table[i].fever, table[i].cough, table[i].symptoms);
  }
  fclose(patients);
  return 1;
}
