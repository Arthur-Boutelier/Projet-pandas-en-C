#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*void sort(COLONNE* col, int dir){
    col->sort_dir=dir;
    switch (col->valid_index) {
        case 1:
            break;
        case 0:
            quicksort(col);
            break;
        case -1:
            tri_insertion(col);
            break;
    }
}*/
void tri_insertion(COLONNE* col){
    int i,j,n=col->tlog;
    void* k;
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
                        while ((j>=0)&&(*(int*)col->donnees[col->index[j]]>*(int*)col->donnees[*(int*)k])){
                            col->index[j+1]=col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    break;
                case DOUBLE:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&(*(double*)col->donnees[col->index[j]]>*(double*)col->donnees[*(int*)k])){
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    break;
                case FLOAT:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&(*(float*)col->donnees[col->index[j]]>*(float*)col->donnees[*(int*)k])){
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    break;
                case UINT:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&(*(unsigned int*)col->donnees[col->index[j]]>*(unsigned int*)col->donnees[*(int*)k])){
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    break;
                case CHAR:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&(*(char*)col->donnees[col->index[j]]>*(char*)col->donnees[*(int*)k])){
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    break;
                case STRING:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while((j>=0)&&(strcmp((char*)col->donnees[col->index[j]],(char*)col->donnees[*(int*)k])>0)){
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
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
                        while ((j>=0)&&(*(int*)col->donnees[col->index[j]]<*(int*)col->donnees[*(int*)k])){
                            col->index[j+1]=col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    break;
                case DOUBLE:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&(*(double*)col->donnees[col->index[j]]<*(double*)col->donnees[*(int*)k])){
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    break;
                case FLOAT:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&(*(float*)col->donnees[col->index[j]]<*(float*)col->donnees[*(int*)k])){
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    break;
                case UINT:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&(*(unsigned int*)col->donnees[col->index[j]]<*(unsigned int*)col->donnees[*(int*)k])){
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    break;
                case CHAR:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while ((j>=0)&&(*(char*)col->donnees[col->index[j]]<*(char*)col->donnees[*(int*)k])){
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    break;
                case STRING:
                    k=(int*)malloc(sizeof(int));
                    for(i=1;i<n;i++){
                        *(int*)k=col->index[i];
                        j=i-1;
                        while((j>=0)&&(strcmp((char*)col->donnees[col->index[j]],(char*)col->donnees[*(int*)k])<0)){
                            col->index[j+1]= col->index[j];
                            j--;
                        }
                        col->index[j+1]=*(int*)k;
                    }
                    break;
                case STRUCTURE:
                    break;}
            break;
    }
}
void swap_indice(COLONNE*col,int a, int b){
    void*tmp;
    switch (col->type){
        case NULLVAL:
            break;
        case INT:
            tmp=(int*)malloc(sizeof(int));
            *(int*)tmp=*(int*)col->donnees[a];
            *(int*)col->donnees[a]=*(int*)col->donnees[b];
            *(int*)col->donnees[b]=*(int*)tmp;
            break;
        case DOUBLE:
            tmp=(double*)malloc(sizeof(double));
            *(double*)tmp=*(double*)col->donnees[a];
            *(double*)col->donnees[a]=*(double*)col->donnees[b];
            *(double*)col->donnees[b]=*(double*)tmp;
            break;
        case FLOAT:
            tmp=(float*)malloc(sizeof(float));
            *(float*)tmp=*(float*)col->donnees[a];
            *(float*)col->donnees[a]=*(float*)col->donnees[b];
            *(float*)col->donnees[b]=*(float*)tmp;
            break;
        case UINT:
            tmp=(unsigned int*)malloc(sizeof(unsigned int));
            *(unsigned int*)tmp=*(unsigned int*)col->donnees[a];
            *(unsigned int*)col->donnees[a]=*(unsigned int*)col->donnees[b];
            *(unsigned int*)col->donnees[b]=*(unsigned int*)tmp;
            break;
        case CHAR:
            tmp=(char*)malloc(sizeof(char));
            *(char*)tmp=*(char*)col->donnees[a];
            *(char*)col->donnees[a]=*(char*)col->donnees[b];
            *(char*)col->donnees[b]=*(char*)tmp;
            break;
        case STRING:
            tmp=(char**)malloc(sizeof(char*));
            *(char**)tmp=*(char**)col->donnees[a];
            *(char**)col->donnees[a]=*(char**)col->donnees[b];
            *(char**)col->donnees[b]=*(char**)tmp;
            break;
        case STRUCTURE:
            break;
    }
}
int partition(COLONNE* col,int l,int h){
    void* pivot;
    int i=l-1;
    switch (col->type){
        case NULLVAL:
            break;
        case INT:
            pivot=(int*)malloc(sizeof(int));
            *(int*)pivot=*(int*)col->donnees[h];
            for (int j=l;j<h;j++){
                if (*(int*)col->donnees[j]<*(int*)pivot){
                    i++;
                    swap_indice(col,i,j);
                }
            }
            swap_indice(col,i+1,h);
            return (i+1);
        case DOUBLE:
            pivot=(double*)malloc(sizeof(double));
            *(double*)pivot=*(double*)col->donnees[h];
            for (int j=l;j<h;j++){
                if (*(double*)col->donnees[j]<*(double*)pivot){
                    i++;
                    swap_indice(col,i,j);
                }
            }
            swap_indice(col,i+1,h);
            return (i+1);
        case FLOAT:
            pivot=(float*)malloc(sizeof(float));
            *(float*)pivot=*(float*)col->donnees[h];
            for (int j=l;j<h;j++){
                if (*(float*)col->donnees[j]<*(float*)pivot){
                    i++;
                    swap_indice(col,i,j);
                }
            }
            swap_indice(col,i+1,h);
            return (i+1);
        case UINT:
            pivot=(unsigned int*)malloc(sizeof(unsigned int));
            *(unsigned int*)pivot=*(unsigned int*)col->donnees[h];
            for (int j=l;j<h;j++){
                if (*(unsigned int*)col->donnees[j]<*(unsigned int*)pivot){
                    i++;
                    swap_indice(col,i,j);
                }
            }
            swap_indice(col,i+1,h);
            return (i+1);
        case CHAR:
            pivot=(char*)malloc(sizeof(char));
            *(char*)pivot=*(char*)col->donnees[h];
            for (int j=l;j<h;j++){
                if (*(char*)col->donnees[j]<*(char*)pivot){
                    i++;
                    swap_indice(col,i,j);
                }
            }
            swap_indice(col,i+1,h);
            return (i+1);
        case STRING:
            pivot=(char**)malloc(sizeof(char*));
            *(char**)pivot=*(char**)col->donnees[h];
            for (int j=l;j<h;j++){
                if (*(char**)col->donnees[j]<*(char**)pivot){
                    i++;
                    swap_indice(col,i,j);
                }
            }
            swap_indice(col,i+1,h);
            return (i+1);
        case STRUCTURE:
            break;
    }
}
void quicksort(COLONNE* col,int l,int h){
    if (l<h) {
        int pi = partition(col, l, h);
        quicksort(col, l, pi - 1);
        quicksort(col,pi+1,h);
    }
}