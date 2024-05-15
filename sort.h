#ifndef PROJET_C_SORT_H
#define PROJET_C_SORT_H
#define ASC  0
#define DESC 1
#include "colonne.h"
void sort(COLONNE* col, int dir);
void tri_insertion(COLONNE* col);
void tri_quicksort(COLONNE* col);
void quickSort(COLONNE* col, int l, int h);
void quickSort2(COLONNE* col,int l,int h);
void swap(int *a, int *b);
int partition(COLONNE* col, int l, int h);
int partition2(COLONNE* col, int l, int h);
#endif //PROJET_C_SORT_H
