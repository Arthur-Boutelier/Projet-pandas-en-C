#ifndef PROJET_C_FUNCTION_H
#define PROJET_C_FUNCTION_H
typedef struct{
    char * titre;
    int tmax;
    int tlog;
    int * donnees;
}COLONNE;
typedef struct{
    COLONNE * Tab;
    int nbCol;
}CDataframe;

COLONNE* create_column(char *);
int insert_value(COLONNE* , int);
void delete_column(COLONNE **);
void print_col(COLONNE *);
#endif
