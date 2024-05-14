#ifndef PROJET_C_CDATAFRAME_H
#define PROJET_C_CDATAFRAME_H
#include "colonne.h"
#include "list.h"

typedef list CDATAFRAME;
/*
*fonction qui crée un dataframe
 *Sortie : structure de type cdataframe
 *Entrée: type : Type* : pointeur vers les type présent dans le dataframe
 *       size : int : taille du dataframe
 */
CDATAFRAME* creer_cd(TYPE* type, long long int size);

/*
*fonction qui a pour but de remplir un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME* : pointeur vers le dataframe que l'on veut remplir
 */
void remplir_cd(CDATAFRAME* cd);

/*
*fonction qui supprime un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME ** : Pointeur vers le Dataframe à supprimer
 */
void suppr_cd(CDATAFRAME** cd);

/*
*fonction qui supprime une colonne dans un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME* : pointeur vers le dataframe dans lequelle on veut supprimer la colonne
 *       nom : char* : Nom de la colonne à supprimer
 */
void suppr_colonne(CDATAFRAME* cd, char* nom);

/*
*fonction qui renvoie le nombre de colonne dans un dataframe
 *Sortie : int : nombre de colonne dans le dataframe
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 */
long long int nb_colonne_cd(CDATAFRAME* cd);

/*
*fonction qui affiche un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 */
void afficher_cd(CDATAFRAME* cd);

/*
*fonction qui renvoie le nombre de colonne dans un dataframe
 *Sortie : int : nombre de colonne dans le dataframe
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 */
void afficher_ligne_entre(CDATAFRAME* cd, long long int debut, long long int fin);

/*
*fonction qui affiche les colonnes présente entre 2 autres
 *Sortie : void
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 *        nom_debut, nom_fin : char* : nom des colonnes entres lesquelles on affiche
 */
void afficher_colonne_entre(CDATAFRAME* cd, char* nom_debut, char* nom_fin);

/*
*fonction qui ajoute une ligne dans un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 *        liste : list* : pointeur vers une liste doublement chainé contenant la nouvelle ligne
 */
void ajouter_ligne(CDATAFRAME* cd, CDATAFRAME * cd_ajouter);

/*
*fonction qui permet de rajouter une colonne dans un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 *        col : COLONNE* : pointeur vers la colonne à rajouter
 */
void ajouter_colonne(CDATAFRAME* cd, COLONNE* col);

/*
*fonction qui supprime une ligne dans un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 *        indice : long long int : indice de la ligne à supprimer
 */
void suppr_ligne(CDATAFRAME* cd, long long int indice);

/*
*fonction qui renvoie le nombre de colonne dans un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 *        ancien_nom, nouveau_nom : char* : ancien et nouveau nom de la colonne
 */
void renommer_col(CDATAFRAME* cd, char* ancien_nom, char* nouveau_nom);

/*
*fonction qui renvoie le nombre de colonne dans un dataframe
 *Sortie : int : renvoie 0 si la valeur n'est pas présente et 1 sinon
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 *        valeur : void* : pointeur vers valeur rechercher
 */
int existe_cd(CDATAFRAME* cd, void* valeur, TYPE type_n_v);

/*
*fonction qui permet de renvoyer la valeur présente au croisement entre la ligne et la colonne choisie dans un dataframe
 *Sortie : void* : valeur présente à la position rechercher
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 *        nom_col : char* : nom de la colonne
 *        indice_ligne : long long int : indice de la ligne
 */
void* obtenir_valeur(CDATAFRAME* cd, char* nom_col, long long int indice_ligne);

/*
*fonction qui modifie la valeur présente au croisement de la ligne et de la colonne en argument dans un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 *        nom_col : char* : nom de la colonne
 *        indice_ligne : long long int : indice de la ligne
 *        nouv_val : void* : nouvelle valeur
 */
void modif_valeur(CDATAFRAME* cd, char* nom_col, long long int indice_ligne, void* nouv_val, TYPE type_n_v);

/*
*fonction qui affiche le nom de toute les colonnes présente dans un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 */
void afficher_nom_col(CDATAFRAME* cd);

/*
*fonction qui renvoie le nombre de ligne présente dans un dataframe
 *Sortie : int : nombre de ligne dans le dataframe
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 */
long long int nb_ligne_cd(CDATAFRAME* cd);

/*
*fonction qui renvoie le nombre de valeur inférieur a une valeur prise en argument dans un dataframe
 *Sortie : long long int : nombre de valeur inférieur
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 *        valeur : void* : pointeur vers la valeur témoin
 */
long long int nb_valeur_inf_cd(CDATAFRAME* cd, void* valeur, TYPE type_val);

/*
*fonction qui renvoie le nombre de valeur supérieur a une valeur prise en argument dans un dataframe
 *Sortie : long long int : nombre de valeur supérieur
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 *        valeur : void* : pointeur vers la valeur témoin
 */
long long int nb_valeur_sup_cd(CDATAFRAME* cd, void* valeur, TYPE type_val);

/*
*fonction qui renvoie le nombre de valeur égal a une valeur prise en argument dans un dataframe
 *Sortie : long long int : nombre de valeur égal
 *Entrée: cd : CDATAFRAME * : pointeur vers le dataframe
 *        valeur : void* : pointeur vers la valeur témoin
 */
long long int nb_valeur_egal_cd(CDATAFRAME* cd, void* valeur, TYPE type);

int col_existe_cd(CDATAFRAME* cd, char* nom);
#endif //PROJET_C_CDATAFRAME_H
