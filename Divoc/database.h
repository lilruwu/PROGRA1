#ifndef DATABASE_H
#define DATABASE_H

struct aPatient{
  char N[256];
  char DNI[10];
  int date;
  int fever;
  int cough;
  char symptoms;
};

void p_register(struct aPatient *table, int *number);

int p_search(struct aPatient *table, int *number);

int p_discharge(struct aPatient *table, int *number);

int p_list(struct aPatient *table, int *number);

int p_mark(struct aPatient *table, int *number);

int read_file(struct aPatient *table, int *number);

int p_exit(struct aPatient *table, int *number);

#endif
