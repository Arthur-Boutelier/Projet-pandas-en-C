#ifndef PROJET_C_SORT_H
#define PROJET_C_SORT_H
#define ASC  0
#define DESC 1
#include "colonne.h"
void sort(COLONNE* col, int dir);
void tri_insertion(COLONNE* col);
void quicksort(COLONNE* col,int l,int h);
void swap_indice(COLONNE* col,int a, int b);
int partition(COLONNE* col,int l,int h);
#endif //PROJET_C_SORT_H
