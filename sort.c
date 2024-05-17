#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sort(COLONNE* col, int dir){

    if (dir != col->sort_dir){
        col->sort_dir=dir;
        col->valid_index = 0;
    }
    switch (col->valid_index) { //effectue le tri en fonction de valid index
        case 1:
            break;
        case 0:
            tri_quicksort(col);//effectue un quicksort
            col->valid_index=1;
            break;
        case -1:
            tri_insertion(col);//effectuer un tri insertion
            col->valid_index=1;
            break;
    }
}
void tri_insertion(COLONNE* col){
    int i,j,n=col->tlog;
    void* k;                    //k est un pointeur sur void car on ne connait pas à l'avance son type
    switch(col->sort_dir){
        case 0:
            switch(col->type){
                case NULLVAL:
                    break;
                case INT:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(int*)col->donnees[col->index[j]]>*(int*)col->donnees[*(int*)k])))){ //longues conditions pour mettre l'index des valeurs NULL à la fin
                            col->index[j+1]=col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }free(k);
                    break;
                case DOUBLE:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(double*)col->donnees[col->index[j]]>*(double*)col->donnees[*(int*)k])))){  //longues conditions pour mettre l'index des valeurs NULL à la fin
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }free(k);
                    break;
                case FLOAT:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(float*)col->donnees[col->index[j]]>*(float*)col->donnees[*(int*)k])))){  //longues conditions pour mettre l'index des valeurs NULL à la fin
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }free(k);
                    break;
                case UINT:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(unsigned int*)col->donnees[col->index[j]]>*(unsigned int*)col->donnees[*(int*)k])))){  //longues conditions pour mettre l'index des valeurs NULL à la fin
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }free(k);
                    break;
                case CHAR:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(char*)col->donnees[col->index[j]]>*(char*)col->donnees[*(int*)k])))){  //longues conditions pour mettre l'index des valeurs NULL à la fin
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }free(k);
                    break;
                case STRING:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(strcmp((char*)col->donnees[col->index[j]],(char*)col->donnees[*(int*)k])>0)))){   //longues conditions pour mettre l'index des valeurs NULL à la fin
                                col->index[j+1]= col->index[j];
                                j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }free(k);
                    break;
                case STRUCTURE:
                    break;
            }
            break;
        case 1:
            switch(col->type){
                case NULLVAL:
                    break;
                case INT:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(int*)col->donnees[col->index[j]]<*(int*)col->donnees[*(int*)k])))){  //longues conditions pour mettre l'index des valeurs NULL à la fin
                            col->index[j+1]=col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    free(k);
                    break;
                case DOUBLE:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(double*)col->donnees[col->index[j]]<*(double*)col->donnees[*(int*)k])))){ //longues conditions pour mettre l'index des valeurs NULL à la fin
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    free(k);
                    break;
                case FLOAT:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(float*)col->donnees[col->index[j]]<*(float*)col->donnees[*(int*)k])))){  //longues conditions pour mettre l'index des valeurs NULL à la fin
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    free(k);
                    break;
                case UINT:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(unsigned int*)col->donnees[col->index[j]]<*(unsigned int*)col->donnees[*(int*)k])))){  //longues conditions pour mettre l'index des valeurs NULL à la fin
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }free(k);
                    break;
                case CHAR:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(int*)col->donnees[col->index[j]]<*(int*)col->donnees[*(int*)k])))){  //longues conditions pour mettre l'index des valeurs NULL à la fin
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }free(k);
                    break;
                case STRING:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(strcmp((char*)col->donnees[col->index[j]],(char*)col->donnees[*(int*)k])<0)))){  //longues conditions pour mettre l'index des valeurs NULL à la fin
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }free(k);
                    break;
                case STRUCTURE:
                    break;
            }
            break;
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void tri_quicksort(COLONNE* col) {
    int l = 0;
    int h = col->tlog - 1;
    if (col->sort_dir==0){
        quickSort(col, l, h);  //appel la fonction quicksort croissant
    }
    else{
        quickSort2(col,l,h);   //appel la fonction quicksort décroissant
    }
}
void quickSort(COLONNE* col, int l, int h) {
    if (l < h) {
        int pi = partition(col, l, h);
        quickSort(col, l, pi - 1);
        quickSort(col, pi + 1, h);
    }
}
int partition(COLONNE* col, int l, int h) {
    void *pivot = col->donnees[col->index[h]];
    int i = (l - 1);
    switch(col->type){
        case INT:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && (*(int*)col->donnees[col->index[j]]< *(int*)col->donnees[col->index[h]]))) {  //longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case DOUBLE:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && (*(double*)col->donnees[col->index[j]]< *(double*)col->donnees[col->index[h]]))) {  //longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case FLOAT:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && (*(float*)col->donnees[col->index[j]]< *(float*)col->donnees[col->index[h]]))) {  //longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case UINT:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && (*(unsigned int*)col->donnees[col->index[j]]< *(unsigned int*)col->donnees[col->index[h]]))) {  //longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case CHAR:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && (*(char*)col->donnees[col->index[j]]< *(char*)col->donnees[col->index[h]]))) {   //longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case NULLVAL:
            break;
        case STRING:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && strcmp((char*)col->donnees[col->index[j]], (char*)pivot) <= 0)) {   //longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case STRUCTURE:
            break;
    }
    return (i + 1);
}
void quickSort2(COLONNE* col,int l,int h){
    if (l < h) {
        int pi = partition2(col, l, h);
        quickSort2(col, l, pi - 1);
        quickSort2(col, pi + 1, h);
    }
}
int partition2(COLONNE* col, int l, int h) {
    void *pivot = col->donnees[col->index[h]];
    int i = (l - 1);
    switch(col->type){
        case INT:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && (*(int*)col->donnees[col->index[j]]> *(int*)col->donnees[col->index[h]]))) { //longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case DOUBLE:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && (*(double*)col->donnees[col->index[j]]> *(double*)col->donnees[col->index[h]]))) {//longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case FLOAT:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && (*(float*)col->donnees[col->index[j]]> *(float*)col->donnees[col->index[h]]))) {//longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case UINT:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && (*(unsigned int*)col->donnees[col->index[j]]> *(unsigned int*)col->donnees[col->index[h]]))) {//longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case CHAR:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && (*(char*)col->donnees[col->index[j]]> *(char*)col->donnees[col->index[h]]))) {//longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case NULLVAL:
            break;
        case STRING:
            for (int j = l; j <= h - 1; j++) {
                if ((col->donnees[col->index[j]] != NULL && pivot == NULL) ||
                    (col->donnees[col->index[j]] != NULL && pivot != NULL && strcmp((char*)col->donnees[col->index[j]], (char*)pivot) >= 0)) {//longues conditions pour mettre l'index des valeurs NULL à la fin
                    i++;
                    swap(&col->index[i], &col->index[j]);
                }
            }
            swap(&col->index[i + 1], &col->index[h]);
            break;
        case STRUCTURE:
            break;
    }
    return (i + 1);
}