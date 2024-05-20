
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
    int valid_index;        /* peut prendre 3 valeurs 0 1 ou -1 */
    int tri_dir;           /* peut prendre 2 valeurs 0 ou 1*/


}COLONNE;
typedef struct{
    COLONNE * Tab;
    int nbCol;
}CDataframe;

#include "sort.h"

/*
 * Cette fonction permet de créer une colonne d'un type donné et de la nommer
 * Entrées: type: TYPE: type de la colonne que l'on veut créer
 *          nom: char*: nom de la colonne
 * Sortie: COLONNE*: pointeur sur cette colonne
 */
COLONNE* creer_colonne(TYPE type, char * nom);
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
void convert_val(COLONNE * col , unsigned long long int indice, char* str, int taille);

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
 * Cette fonction permet de re-trier une colonne ayant déjà été trié par le passé
 * Entrée : col : COLONNE*, pointeur visant la colonne
 * Sortie : void
 */
void actualiser_index(COLONNE* col);
/*
 * Fonction qui alloue dynamiquement le tableau de données de la colonne et qui crée son index
 * Entrée: col: COLONNE*: pointeur sur la colonne
 * Sortie: void
 */
void allocation_initial(COLONNE* col);
/*
 *Fonction qui quand une colonne est pleine rajoute 256 vide dans cette derniere
 * Entrée: col: COLONNE*: pointeur sur la colonne a agrandir
 * Sortie: void
 */
void reallocation(COLONNE* col);
/*
 * Fonction qui supprime une ligne d'une colonne
 * Entrées: col: COLONNE*: pointeur sur une colonne
 *          indice: ll int: numéro de la ligne à supprimer
 */
void colonne_supprimer_indice(COLONNE* col, long long int indice);
/*
 * Fonction qui modifie la valeur d'une colonne
 * Entrées: col: COLONNE*: pointeur sur une colonne
 *          indice: ll int: numéro de la ligne de la valeur à modifier
 *          nouv_val: void*: pointeur sur la nouvelle valeur
 *          type: TYPE: type de cette nouvelle valeur
 * Sortie: void
 */
void colonne_modif_valeur(COLONNE* col, long long int indice, void* nouv_val, TYPE type);
/*
 * Fonction qui permet de savoir si une valeur se trouve dans une colonne
 * Entrées: col: COLONNE*: pointeur sur une colonne
 *          val: void*: pointeur sur une valeur
 * Sortie: int: 1 ou 0 en fonction de si la valeur donnée se trouve dans la colonne
*/
int existe_col(COLONNE* col, void* val);
/*
 * Fonction qui affiche les valeurs d'une colonne en fonction de son index
 * Entrée: col: COLONNE*: pointeur sur une colonne
 * Sortie: void
 */
void print_col_index(COLONNE* col);
/*
 * Fonction qui supprime totalement l'index d'une colonne
 * Entrée: col: COLONNE*: pointeur sur une colonne
 * Sortie: void
 */
void effacer_index(COLONNE* col);
/*
 * Fonction rajoutée pour afficher l'indice d'une colonne
 * Entrée: col: COLONNE* : pointeur sur une colonne
 * Sortie: void
 */
void print_index(COLONNE * col);

/*
 * Fonction qui regarde si l'index est correct
 * Entrée: col: COLONNE* : pointeur sur une colonne
 * Sortie: int: 0 si l'index n'existe pas
 *             -1 si l'index n'est pas trié ou à jour
 *              1 si l'index est correct
 */
int verif_index(COLONNE *col);
/*
 * Fonction qui permet de savoir si une valeur se trouve dans une colonne par dichotomie
 * Entrées: col: COLONNE*: pointeur sur une colonne
 *          val: void*: pointeur sur la valeur à chercher
 * Sortie: int : -1 si la colonne n'est pas triée
 *                0 si la valeur n'est pas dans la colonne
 *                1 si la valeur est dans la colonne
 */
int chercher_val_col_dicho(COLONNE *col, void *val);
#endif
