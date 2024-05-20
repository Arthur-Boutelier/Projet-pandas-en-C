#ifndef PROJET_C_SORT_H
#define PROJET_C_SORT_H
#define ASC  0
#define DESC 1
#include "colonne.h"
/*
 * Fonction qui choisi quel tri effectuer sur une colonne
 * Entrées: col: COLONNE*: pointeur sur une colonne
 *          dir: int : direction du tri, croissant ou décroissant
 * Sortie: void
 */
void tri(COLONNE* col, int dir);
/*
 * Fonction qui effectue un tri insertion sur l'index d'une colonne, soit croissant soit décroissant
 * Entrée: col: COLONNE*: pointeur sur une colonne
 * Sortie: void
 */
void tri_insertion(COLONNE* col);
/*
 * Fonction qui effectue un tri quicksort sur l'index d'une colonne, soit croissant soit décroissant
 * Entrée: col: COLONNE*: pointeur sur une colonne
 * Sortie: void
 */
void tri_quicksort(COLONNE* col);
/*
 * Fonction récursive qui permet de trier l'index d'une colonne dans l'ordre croissant
 * Entrées: col: COLONNE*: pointeur sur une colonne
 *         l: int: représente la valeur basse
 *         h: int: représente la valeur haute
 * Sortie: void
 */
void quickSort(COLONNE* col, int l, int h);
/*
 * Fonction récursive qui permet de trier l'index d'une colonne dans l'ordre décroissant
 * Entrées: col: COLONNE*: pointeur sur une colonne
 *         l: int: représente la valeur basse
 *         h: int: représente la valeur haute
 * Sortie: void
 */
void quickSort2(COLONNE* col,int l,int h);
/*
 * Fonction qui échange deux valeurs dans un tableau (ici le tableau d'index)
 * Entrées: a: int*: première valeur à échanger
 *          b: int*: deuxième valeur à échanger
 * Sortie: void
 */
void swap(int *a, int *b);
/*
 * Fonction qui partitionne les éléments du tableau dans l'ordre croissant
 * Entrées: col: COLONNE*: pointeur sur une colonne
 *         l: int: représente la valeure basse
 *         h: int: représente la valeure haute
 * Sortie: int : retourne la valeur du pivot
 */
int partition(COLONNE* col, int l, int h);
/*
 * Fonction qui partitionne les éléments du tableau dans l'ordre décroissant
 * Entrées: col: COLONNE*: pointeur sur une colonne
 *         l: int: représente la valeure basse
 *         h: int: représente la valeure haute
 * Sortie: int : retourne la valeur du pivot
 */
int partition2(COLONNE* col, int l, int h);
#endif //PROJET_C_SORT_H
