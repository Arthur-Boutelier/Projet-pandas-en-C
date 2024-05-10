
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
    char titre[15];
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
/*
 * Cette fonction permet d'inserer une valeur dans une colonne
 * Entrée : col : COLONNE* ,Un pointeur visant une colonne
 *          valeur : void* ,Pointeur visant une valeur
 * Sortie : Renvoie un booléen celon l'accomplissement de l'insertion
 */
int inserer_valeur(COLONNE* col, void*  valeur);

/*
 * Cette fonction permet de supprimer une colonne
 * Entrée : col : COLONNE**, une double pointeur permettant de viser la colonne à supprimer
 * Sortie : void
 */
void supprimer_colonne(COLONNE * col);

/*
 * Cette fonction permet d'afficher une colonne
 * Entrée : col : COLONNE*, colonne à afficher
 * Sortie : void
 */
void print_col(COLONNE * col);

/*
 * Cette fonction permet de convertir la valeur d'une case en str
 * Entrée : col : COLONNE*, pointeur visant la colonne
 *          indice : long entier non signé
 *          str : char*
 *          taille : int
 * Sortie : void
 */
void convert_value(COLONNE * col , unsigned long long int indice, char* str, int taille);

/*
 * Cette fonction permet de calculer le nombre d'occurence d'une valeur dans une colonne
 * Entrée : col : COLONNE*
 *          valeur : void*, pointeur visant une valeur
 * Sortie : long long int
 */
long long int occurence(COLONNE * col, void* valeur);

/*
 * Cette fonction permet de donner la valeur a une indice précis dans une colonne
 * Entrée : col : COLONNE*, pointeur visant la colonne
 * Sortie : char*
 */
void* valeur_pos(COLONNE* col, long long int indice);

/*
 * Cette fonction permet de donner le nombre de valeur étant inferieur à la valeur entrée
 * Entrée : col : COLONNE*, pointeur visant la colonne
 *          valeur : void*, pointeur visant sur une valeur
 * Sortie : long long int, correspondant au nombre de valeur inferieur à la valeur entrée
 */
long long int nb_valeur_inf_col(COLONNE* col, void* valeur);

/*
 * Cette fonction permet de donner le nombre de valeur étant inferieur à la valeur entrée
 * Entrée : col : COLONNE*, pointeur visant la colonne
 *          valeur : void*, pointeur visant sur la valeur
 * Sortie : long long int, correspondant au nombre de valeur supperieur à la valeur entée
 */
long long int nb_valeur_sup_col(COLONNE* col, void* valeur);


/*
 * Cette fonction permet d'afficher une colonne trié
 * Entrée : col : COLONNE*, pointeur visant la colonne
 * Sortie : void
 */
void print_colonne_par_index(COLONNE* col);

/*
 * Cette fonction permet de supprimer les index
 * Entrée : col : COLONNE*, pointeur visant la colonne
 * Sortie : void
 */
void supprimer_index(COLONNE* col);

/*
 * Cette fonction permet de vérifier si une colonne a été trié
 * Entrée : col : COLONNE*, pointeur visant la colonne
 * Sortie : int : 1 si trié 0 sinon
 */
int verifier_index(COLONNE* col);

/*
 * Cette fonction permet de re-trier une colonne ayant déjà été trié par le passé
 * Entrée : col : COLONNE*, pointeur visant la colonne
 * Sortie : void
 */
void actualiser_index(COLONNE* col);

/*
 * Cette fonction permet de rehercher une valeur dans une colonne ayant été trié
 * Entrée : col : COLONNE*, pointeur visant la colonne
 * Sortie : int
 */
int chercher_val_col_trier(COLONNE* col, void* valeur);
void allocation_initial(COLONNE* col);
void reallocation(COLONNE* col);
void colonne_supprimer_indice(COLONNE* col, long long int indice);
void colonne_modif_valeur(COLONNE* col, long long int indice, void* nouv_val, TYPE type);
int existe_col(COLONNE* col, void* val);
#endif
