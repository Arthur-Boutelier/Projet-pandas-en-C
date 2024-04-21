#ifndef PROJET_C_CDATAFRAME_H
#define PROJET_C_CDATAFRAME_H
#include "colonne.h"
#include "list.h"

typedef list CDATAFRAME;

CDATAFRAME* creer_cd(TYPE*, int);
void remplir_cd(CDATAFRAME*);
void suppr_cd(CDATAFRAME**);
void suppr_colonne(CDATAFRAME*, char*);
int nb_colonne_cd(CDATAFRAME*);
void afficher_cd(CDATAFRAME*);
void afficher_ligne_entre(CDATAFRAME*, long long int, long long int);
void afficher_colonne_entre(CDATAFRAME*, char*, char*);
void ajouter_ligne(CDATAFRAME*, list);
void ajouter_colonne(CDATAFRAME*, COLONNE);
void suppr_ligne(CDATAFRAME*, long long int);
void renommer_col(CDATAFRAME*, char*, char*);
int existe_cd(CDATAFRAME*, void*);
void* obtenir_valeur(CDATAFRAME*, char*, long long int);
void modif_valeur(CDATAFRAME*, char*, long long int, void*);
void afficher_nom_col(CDATAFRAME*);
int nb_ligne_cd(CDATAFRAME*);
long long int nb_valeur_inf_cd(CDATAFRAME*, void*);
long long int nb_valeur_sup_cd(CDATAFRAME*, void*);
long long int nb_valeur_egal_cd(CDATAFRAME*, void*);


#endif //PROJET_C_CDATAFRAME_H
