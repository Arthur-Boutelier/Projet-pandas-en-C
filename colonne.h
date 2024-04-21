#ifndef PROJET_C_COLONNE_H
#define PROJET_C_COLONNE_H

typedef enum
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
}TYPE;

typedef union {
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
}COLUMN_TYPE;

typedef struct{
    char * titre;
    int tmax;
    int tlog;
    COLUMN_TYPE ** donnees;
    TYPE type;
    int* index;


}COLONNE;
typedef struct{
    COLONNE * Tab;
    int nbCol;
}CDataframe;




COLONNE* create_column(TYPE, char *);
int insert_value(COLONNE* , void*);
void delete_column(COLONNE **);
void print_col(COLONNE *);
void convert_value(COLONNE *, unsigned long long int, char*, int);
long long int occurence(COLONNE *, void*);
char* valeur_pos(COLONNE*, long long int);
long long int nb_valeur_plus_petite(COLONNE*, void*);
long long int nb_valeur_plus_grande(COLONNE*, void*);
long long int nb_valeur_egale(COLONNE*, void*);
void print_colonne_par_index(COLONNE*);
void supprimer_index(COLONNE*);
int verifier_index(COLONNE*);
void actualiser_index(COLONNE*);
int chercher_val_col_trier(COLONNE*, void*);



#endif
