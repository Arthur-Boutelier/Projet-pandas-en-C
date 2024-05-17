#ifndef PROJET_C_SORT_H
#define PROJET_C_SORT_H
#define ASC  0
#define DESC 1
#include "colonne.h"
/*
 * Fonction qui choisi quel tri effectuer sur une colonne
 * Sortie: void
 * Entrées: col: COLONNE*: pointeur sur une colonne
 *          dir: int : direction du tri, croissant ou décroissant
 */
void sort(COLONNE* col, int dir);
/*
 * Fonction qui effectue un tri insertion sur l'index d'une colonne, soit croissant soit décroissant
 * Sortie: void
 * Entrée: col: COLONNE*: pointeur sur une colonne
 */
void tri_insertion(COLONNE* col);
/*
 * Fonction qui effectue un tri quicksort sur l'index d'une colonne, soit croissant soit décroissant
 * Sortie: void
 * Entrée: col: COLONNE*: pointeur sur une colonne
 */
void tri_quicksort(COLONNE* col);
/*
 * Fonction récursive qui permet de trier l'index d'une colonne dans l'ordre croissant
 * Sortie: void
 * Entrée: col: COLONNE*: pointeur sur une colonne
 *         l: int: représente la valeur basse
 *         h: int: représente la valeur haute
 */
void quickSort(COLONNE* col, int l, int h);
/*
 * Fonction récursive qui permet de trier l'index d'une colonne dans l'ordre décroissant
 * Sortie: void
 * Entrée: col: COLONNE*: pointeur sur une colonne
 *         l: int: représente la valeur basse
 *         h: int: représente la valeur haute
 */
void quickSort2(COLONNE* col,int l,int h);
/*
 * Fonction qui échange deux valeurs dans un tableau (ici le tableau d'index)
 * Sortie: void
 * Entrée: a: int*: première valeur à échanger
 *         b: int*: deuxième valeur à échanger
 */
void swap(int *a, int *b);
/*
 * PAS FINI PAS FINI PAS FINI PAS FINI PAS FINI
 * Fonction qui partitionne les éléments du tableau dans l'ordre croissant
 * Sortie: int : retourne la valeure
 * Entrée: col: COLONNE*: pointeur sur une colonne
 *         l: int: représente la valeure basse
 *         h: int: représente la valeure haute
 */
int partition(COLONNE* col, int l, int h);
int partition2(COLONNE* col, int l, int h);
#endif //PROJET_C_SORT_H
