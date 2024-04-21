#ifndef PROJET_C_CDATAFRAME_H
#define PROJET_C_CDATAFRAME_H
#include "colonne.h"
#include "list.h"

typedef list CDATAFRAME;

CDATAFRAME* creer_cd(TYPE*, int);
void suppr_cd(CDATAFRAME**);
void suppr_colonne(CDATAFRAME*, char*);
int nb_colonne_cd(CDATAFRAME*);
void afficher_cd(CDATAFRAME*);
void afficher_ligne_entre(CDATAFRAME*, long long int, long long int);
void afficher_colonne_entre(CDATAFRAME*, char*, char*);
void ajouter_ligne(CDATAFRAME*, list);
void ajouter_colonne(CDATAFRAME*, COLONNE);
void suppr_ligne(CDATAFRAME*, long long int);
void



#endif //PROJET_C_CDATAFRAME_H
