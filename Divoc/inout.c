#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "database.h"
#include "inout.h"

void stripe(char p, int line_size) {
  int i;
  for(i=0;i<50;i++){
    fprintf(stdout,"%c",p);
  }
  fprintf(stdout,"\n");
}

void headline(char word[],char p, int line_size) {
  int i,j,length;
  length=strlen(word);
  j=(48-length)/2;
  fprintf(stdout,"%c",p);
  for(i=0;i<j;i++){
    fprintf(stdout," ");
  }
  fprintf(stdout,"%s",word);
  for(i=0;i<j;i++){
    fprintf(stdout," ");
  }
  fprintf(stdout,"%c\n",p);
}

int yes_or_no(char *prompt) {
  char car;
  char string[256];
  char added[256];
  int x=0;
  do{
  fprintf (stdout, "%s", prompt);
  fgets(string, sizeof(string), stdin);
  fprintf(stdout,"\n");
  x=sscanf(string, "%c %s", &car, added);
  if(x==1) {
    car = toupper (car);
  }
  switch(car){
  case 'Y':
    return 1;
    break;
  case 'N':
    return 0;
    break;
  }}while((car!=0)||(car!=1));
  return 0;
}

int get_character(char checkword[], char *prompt) {
  char character;
  char string[256];
  char added[256];
  int x=0;
  do{
  fprintf(stdout, "%s (%s): ", prompt, checkword);
  fgets(string, sizeof(string), stdin);
  fprintf(stdout,"\n");
  x=sscanf(string, "%c%s", &character, added);
  if(x==1){
  character=toupper(character);
  }
  }while ((strchr(checkword, character)==NULL)||(x!=1));
  return character;
}

void get_string(char *prompt, char *my_string, int minlength, int maxlength) {
  char word[256];
  char added[256];
  char complete_word[256];
  int x=0;
  int length;
  
  do{
   fprintf(stdout,"%s", prompt);
   fgets (complete_word, sizeof(complete_word), stdin);
   fprintf(stdout,"\n");
   x=sscanf(complete_word, "%s%s", word, added);
    if(x==1){
   length=strlen(word);
  }
    else length=-1;
  }while ((length<minlength)||(length>maxlength));
  strcpy(my_string, word);
}


int get_integer(int mindate, int maxdate, char *prompt) {
  int number=0;
  char string[256];
  char added[256];
  int x=0;
  do{
    fprintf(stdout,"%s ",prompt);
    fgets(string, sizeof(string), stdin);
    fprintf(stdout,"\n");
    x=sscanf(string, "%d%s", &number, added);
  }while ((number<mindate)||(number>maxdate)||(x!=1));

  return number;
}


void display_patient(struct aPatient table){

  fprintf(stdout, ">%24s;%s;%d;%d;%d;%c;\n", table.N, table.DNI, table.date, table.fever, table.cough, table.symptoms);

}



int verify_DNI(char *DNI_con_letra){
  int DNI_sin_letra_int;
  char DNI_sin_letra_char[9];
  char DNI_letter;
  int index;
  int i;
  char cadena[23]="TRWAGMYFPDXBNJZSQVHLCKE";
  sscanf(DNI_con_letra, "%8s%c", DNI_sin_letra_char, &DNI_letter);
  for(i=0;i<8;i++){
    if(isdigit(DNI_sin_letra_char[i])==0){
      fprintf (stdout, "Invalid DNI\n");
      
      return 0;}}
  
  DNI_sin_letra_int=atoi(DNI_sin_letra_char); 
  index=DNI_sin_letra_int%23; 
  
  if (DNI_letter==cadena[index]){
    return 1;
  }
  else { fprintf (stdout, "Invalid DNI\n"); return 0;}
}
