#ifndef INOUT_H
#define INOUT_H

void stripe(char p, int line_size);

void headline(char word[],char p, int line_size);

int yes_or_no(char *prompt);
  
void get_string(char *prompt, char *my_string, int minlength, int maxlength);
 
int get_integer(int mindate, int maxdate, char *prompt);

int get_character(char checkword[], char *prompt);

void display_patient(struct aPatient table);

int verify_DNI(char *DNI_con_letra);

#endif
