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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(int*)col->donnees[col->index[j]]>*(int*)col->donnees[*(int*)k])))){
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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(double*)col->donnees[col->index[j]]>*(double*)col->donnees[*(int*)k])))){
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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(float*)col->donnees[col->index[j]]>*(float*)col->donnees[*(int*)k])))){
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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(unsigned int*)col->donnees[col->index[j]]>*(unsigned int*)col->donnees[*(int*)k])))){
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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(char*)col->donnees[col->index[j]]>*(char*)col->donnees[*(int*)k])))){
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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(strcmp((char*)col->donnees[col->index[j]],(char*)col->donnees[*(int*)k])>0)))){
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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(int*)col->donnees[col->index[j]]<*(int*)col->donnees[*(int*)k])))){
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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(double*)col->donnees[col->index[j]]<*(double*)col->donnees[*(int*)k])))){
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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(float*)col->donnees[col->index[j]]<*(float*)col->donnees[*(int*)k])))){
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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(unsigned int*)col->donnees[col->index[j]]<*(unsigned int*)col->donnees[*(int*)k])))){
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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(*(int*)col->donnees[col->index[j]]<*(int*)col->donnees[*(int*)k])))){
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
                        while ((j>=0)&&((col->donnees[col->index[j]]==NULL&&col->donnees[*(int*)k]!=NULL)||(col->donnees[col->index[j]]!=NULL&&col->donnees[*(int*)k]!=NULL&&(strcmp((char*)col->donnees[col->index[j]],(char*)col->donnees[*(int*)k])<0)))){
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
    }
    col->valid_index=1;
}