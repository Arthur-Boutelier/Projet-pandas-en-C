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
CDATAFRAME* creer_cd(TYPE* type, int size);

/*
*fonction qui a pour but de remplir un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME* : pointeur vers le dataframe que l'on veut remplir
 */
void remplir_cd(CDATAFRAME* cd);

/*
*fonction qui supprime un dataframe
 *Sortie : void
 *Entrée: cd : CDATAFRAME ** : Pointeur vers le pointeur du Dataframe à supprimer
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
int nb_colonne_cd(CDATAFRAME* cd);

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
void ajouter_ligne(CDATAFRAME* cd, list liste);
void ajouter_colonne(CDATAFRAME* cd, COLONNE* col);
void suppr_ligne(CDATAFRAME* cd, long long int indice);
void renommer_col(CDATAFRAME* cd, char* ancien_nom, char* nouveau_nom);
int existe_cd(CDATAFRAME* cd, void* valeur);
void* obtenir_valeur(CDATAFRAME* cd, char* nom_col, long long int indice_ligne);
void modif_valeur(CDATAFRAME* cd, char* nom_col, long long int indice_ligne, void* nouv_val);
void afficher_nom_col(CDATAFRAME* cd);
int nb_ligne_cd(CDATAFRAME* cd);
long long int nb_valeur_inf_cd(CDATAFRAME* cd, void* valeur);
long long int nb_valeur_sup_cd(CDATAFRAME* cd, void* valeur);
long long int nb_valeur_egal_cd(CDATAFRAME* cd, void* valeur);


#endif //PROJET_C_CDATAFRAME_H
