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




COLONNE* create_column(TYPE type, char * nom);

int inserer_valeur(COLONNE* col, void*  valeur);

void delete_column(COLONNE * col);

void print_col(COLONNE * col);

void convert_value(COLONNE * col , unsigned long long int indice, char* str, int taille);

long long int occurence(COLONNE * col, void* valeur);

char* valeur_pos(COLONNE* col, long long int indice);

long long int nb_valeur_inf_col(COLONNE* col, void* valeur);

long long int nb_valeur_sup_col(COLONNE* col, void* valeur);

long long int nb_valeur_egal_col(COLONNE* col, void* valeur);

void print_colonne_par_index(COLONNE* col);

void supprimer_index(COLONNE* col);

int verifier_index(COLONNE* col);

void actualiser_index(COLONNE* col);

int chercher_val_col_trier(COLONNE* col, void* valeur);

void allocation_initial(COLONNE* col);

void reallocation(COLONNE* col);


#endif
