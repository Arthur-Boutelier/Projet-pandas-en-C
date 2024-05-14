#include "colonne.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define taille_realloc 256
COLONNE* create_column(TYPE type,char * title)
{
    COLONNE * ptr=malloc(sizeof (COLONNE));

    strcpy(ptr->titre,title);
    ptr->donnees=NULL;
    ptr->type=type;
    ptr->index=NULL;
    ptr->tmax=0;
    ptr->tlog=0;
    ptr->valid_index=0;

    return ptr;
}


void allocation_initial(COLONNE* col){
    switch(col->type){
        case INT:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(int*));
            break;
        case CHAR:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(char*));
            break;
        case UINT:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(unsigned int*));
            break;
        case FLOAT:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(float *));
            break;
        case DOUBLE:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(double *));
            break;
        case STRING:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(char***));
            break;
        case STRUCTURE:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(void**));
            break;
        case NULLVAL:
            col->donnees = (COLUMN_TYPE**) malloc(taille_realloc*sizeof (NULLVAL));
    }
    col->tmax = 256;
}

void reallocation(COLONNE* col){
    COLUMN_TYPE ** ptr;
    ptr = realloc(col->donnees, col->tmax+taille_realloc);
    col->donnees = ptr;
}
int inserer_valeur(COLONNE* col, void* val)
{
    int etat = 1;
    if (col->tmax == col->tlog){
        etat = 0;
        if (col->tmax)
            reallocation(col);
        else
            allocation_initial(col);
    }
    if (val!=NULL){
        switch (col->type){
            case INT:
                col->donnees[col->tlog] = (COLUMN_TYPE*) malloc (sizeof(int));
                *((int*)col->donnees[col->tlog])= *((int*)val);
                break;
            case CHAR:
                col->donnees[col->tlog] = (COLUMN_TYPE *) malloc (sizeof(char));
                *((char *)col->donnees[col->tlog])= *((char *)val);
                break;
            case UINT:
                col->donnees[col->tlog] = (COLUMN_TYPE *) malloc (sizeof(unsigned int));
                *((unsigned int*)col->donnees[col->tlog])= *((unsigned int*)val);
                break;
            case FLOAT:
                col->donnees[col->tlog] = (COLUMN_TYPE *) malloc (sizeof(float));
                *((float*)col->donnees[col->tlog])= *((float *)val);
                break;
            case DOUBLE:
                col->donnees[col->tlog] = (COLUMN_TYPE *) malloc (sizeof(double));
                *((double *)col->donnees[col->tlog])= *((double *)val);
                break;
            case STRING:
                col->donnees[col->tlog] = (COLUMN_TYPE *) malloc (sizeof(char)*strlen(val));
                strcpy((char *)col->donnees[col->tlog], (char *)val);
                break;
            case STRUCTURE:
                break;
            case NULLVAL:
                col->donnees[col->tlog] = NULL;
                break;
        }
        col->tlog +=1;
        create_index(col);
    }
    else{
        *(col->donnees+col->tlog)=NULL;
        col->tlog+=1;
        create_index(col);
    }
    return etat;
}

void supprimer_colonne(COLONNE *col)
{
    int i;
    for (i = col->tlog;i>0;i--){
        free(col->donnees[i-1]);
    }
    free(col->donnees);
    free(col);
}

void print_col(COLONNE *col)
{
    int n=col->tlog;
    char str[100];
    for (int i=0;i<n;i++)
    {
        if( (col->donnees[i])==NULL    )
        {
            printf("[%d]    NULL\n",i);
        }
        else
        {
            if (col->type==STRING){
                printf("[%d]    %s\n",i,(char*)col->donnees[i]);
            }
            else{
                convert_value(col,i,str,100);
                printf("[%d]    %s\n",i,str);
            }}
    }
}
void convert_value(COLONNE * col , unsigned long long int indice, char* str, int taille)
{
    switch(col->type){
        case INT:
            snprintf(str, taille, "%d", *((int*)col->donnees[indice]));
            break;
        case CHAR:
            snprintf(str, taille, "%c", *((char*)col->donnees[indice]));
            break;
        case UINT:
            snprintf(str, taille, "%ud", *((unsigned int*)col->donnees[indice]));
            break;
        case FLOAT:
            snprintf(str, taille, "%f", *((float*)col->donnees[indice]));
            break;
        case DOUBLE:
            snprintf(str, taille, "%lf", *((double*)col->donnees[indice]));
            break;
        case STRING:
            strcpy(str, (char*)col->donnees[indice]);
            break;
        case STRUCTURE:
            break;
        case NULLVAL:
            strcpy(str, "NULL");
    }
}

long long int occurence(COLONNE * col, void* valeur){
    long long int nb_occurrence = 0;
    if (valeur != NULL) {
        switch (col->type) {
            case (NULLVAL):
                break;
            case INT:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (col->donnees[i] != NULL) {
                        if (*((int *) (col->donnees[i])) == *((int *) valeur))
                            nb_occurrence++;
                    }
                }
                break;
            case CHAR:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (col->donnees[i] != NULL) {
                        if (*((char *) (col->donnees[i])) == *((char *) valeur))
                            nb_occurrence++;
                    }
                }
                break;
            case UINT:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (col->donnees[i] != NULL) {
                        if (*((unsigned int *) (col->donnees[i])) == *((unsigned int *) valeur))
                            nb_occurrence++;
                    }
                }
                break;
            case FLOAT:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (col->donnees[i] != NULL) {
                        if (*((float *) (col->donnees[i])) == *((float *) valeur))
                            nb_occurrence++;
                    }
                }
                break;
            case DOUBLE:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (col->donnees[i] != NULL) {
                        if (*((double *) (col->donnees[i])) == *((double *) valeur))
                            nb_occurrence++;
                    }
                }
                break;
            case STRING:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (col->donnees[i] != NULL) {
                        if (!strcmp(*((char **) (col->donnees[i])), *((char **) valeur)))
                            nb_occurrence++;
                    }
                }
                break;
            case STRUCTURE:
                break;
        }
    }
    else{
        for (long long int i = 0; i < col->tlog; i++) {
            if (col->donnees[i] == NULL)
                    nb_occurrence++;
        }
    }
    return nb_occurrence;
}

void* valeur_pos(COLONNE* col, long long int indice){
    if (indice<col->tlog)
        return (col->donnees[indice]);
    return NULL;
}

long long int nb_valeur_inf_col(COLONNE* col, void* valeur){
    long long int cmpt = 0;
    switch (col->type) {
        case(NULLVAL):
            break;
        case INT:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((int*)(col->donnees[i])) < *((int*)valeur))
                        cmpt++;
                }}
            break;
        case CHAR:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((char*)(col->donnees[i])) < *((char*)valeur))
                        cmpt++;
                }}
            break;
        case UINT:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((unsigned int*)(col->donnees[i])) < *((unsigned int*)valeur))
                        cmpt++;
                }}
            break;
        case FLOAT:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((float*)(col->donnees[i])) < *((float*)valeur))
                        cmpt++;
                }}
            break;
        case DOUBLE:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((double *)(col->donnees[i])) < *((double*)valeur))
                        cmpt++;
                }}
            break;
        case STRING:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (strcmp(*((char **)(col->donnees[i])), *((char**)valeur))<0)
                        cmpt++;
                }}
            break;
        case STRUCTURE:
            break;
    }
    return cmpt;
}


long long int nb_valeur_sup_col(COLONNE* col, void* valeur){
    long long int cmpt = 0;
    switch (col->type) {
        case(NULLVAL):
            break;
        case INT:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((int*)(col->donnees[i])) > *((int*)valeur))
                        cmpt++;
                }}
            break;
        case CHAR:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((char*)(col->donnees[i])) > *((char*)valeur))
                        cmpt++;
                }}
            break;
        case UINT:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((unsigned int*)(col->donnees[i])) > *((unsigned int*)valeur))
                        cmpt++;
                }}
            break;
        case FLOAT:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((float*)(col->donnees[i])) > *((float*)valeur))
                        cmpt++;
                }}
            break;
        case DOUBLE:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((double *)(col->donnees[i])) > *((double*)valeur))
                        cmpt++;
                }}
            break;
        case STRING:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (strcmp(*((char **)(col->donnees[i])), *((char**)valeur))>0)
                        cmpt++;
                }}
            break;
        case STRUCTURE:
            break;
    }
    return cmpt;
}

void colonne_supprimer_indice(COLONNE* col, long long int indice){
    if (indice<col->tlog){
        for (long long int i = indice; i<col->tlog-1;i++)
            col->donnees[i]=col->donnees[i+1];
        free(col->donnees[col->tlog]);
        col->tlog--;
    }
}

void colonne_modif_valeur(COLONNE* col, long long int indice, void* nouv_val, TYPE type_n_v){
    if (col->type == type_n_v){
        switch (col->type){
            case NULLVAL:
                break;
            case INT:
                *((int*)col->donnees[indice]) = *((int*)nouv_val);
                break;
            case CHAR:
                *((char*)col->donnees[indice]) = *((char*)nouv_val);
                break;
            case FLOAT:
                *((float*)col->donnees[indice]) = *((float*)nouv_val);
                break;
            case DOUBLE:
                *((double*)col->donnees[indice]) = *((double*)nouv_val);
                break;
            case STRING:
                strcpy((char*)col->donnees[indice], (char*)nouv_val);
                break;
            case STRUCTURE:
                break;
            case UINT:
                *((unsigned int*)col->donnees[indice]) = *((unsigned int*)nouv_val);
                break;
        }
    }
    else
        printf("Probleme survenue lors de la modification\n");
}

int existe_col(COLONNE* col, void* val){
    if(val != NULL) {
        switch (col->type) {
            case INT:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (*((int *) col->donnees[i]) == *((int *) val))
                        return 1;
                }
                break;
            case CHAR:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (*((char *) col->donnees[i]) == *((char *) val))
                        return 1;
                }
                break;
            case FLOAT:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (*((float *) col->donnees[i]) == *((float *) val))
                        return 1;
                }
                break;
            case DOUBLE:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (*((double *) col->donnees[i]) == *((double *) val))
                        return 1;
                }
                break;
            case UINT:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (*((unsigned int *) col->donnees[i]) == *((unsigned int *) val))
                        return 1;
                }
                break;
            case STRING:
                for(long long int i = 0; i<col->tlog; i++){
                    if(!strcmp((char*)val, (char*)col->donnees[i]))
                        return 1;
                }
                break;
            case NULLVAL:
                if(col->tlog != 0)
                    return 1;
            case STRUCTURE:
                break;
        }
    }
    else{
        for(long long int i = 0; i<col->tlog; i++){
            if(col->donnees[i] == NULL)
                return 1;
            }
    }
    return 0;
}
void print_col_index(COLONNE* col){
    char str[100];
    for (int i=0;i<col->tlog;i++){
        if( (col->donnees[col->index[i]])==NULL)
        {
            printf("[%d]    NULL\n",i);
        }
        else
        {
            if (col->type==STRING){
                printf("[%d]    %s\n",i,(char*)col->donnees[col->index[i]]);
            }
            else{
                convert_value(col,col->index[i],str,100);
                printf("[%d]    %s\n",i,str);
            }}
    }
}
void erase_index(COLONNE* col){
    free(col->index);
    col->index=NULL;
    col->valid_index=0;
}
void create_index(COLONNE* col){
    switch (col->valid_index) {
        case 0:
            col->index=(int*)malloc(sizeof(int)*col->tlog);
            for (int i=0;i<col->tlog;i++) {
                col->index[i] = i;
            }
            break;
        case 1:
            col->index= realloc(col->index,(sizeof(int))*col->tlog);
            col->index[col->tlog-1]=col->tlog-1;
            col->valid_index=-1;
            break;
        case -1:
            col->index= realloc(col->index,(sizeof(int))*col->tlog);
            col->index[col->tlog-1]=col->tlog-1;
            break;
    }


}
void print_index(COLONNE * col){
    for (int i=0;i<col->tlog;i++){
        printf("%d ",col->index[i]);
    }
    printf("\n");
}

int search_value_in_column(COLONNE *col, void *val){
    if(val != NULL){
        if (col->valid_index != 1){
            return -1;
        }

        else{
            int a = 0;
            int b = col->tlog - 1;
            int m = (a + b) / 2;
            switch (col->type) {
                case INT:
                    while (a < b){
                        if (*(int *) col->donnees[col->index[m]] == *((int *) val)){
                            return 1;
                        }
                        else{
                            if (*(int *) col->donnees[col->index[m]] > *((int *) val)){
                                b = m-1;
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;

                case CHAR:
                    while (a < b){
                        if (*(char *) col->donnees[col->index[m]] == *((char *) val)){
                            return 1;
                        }
                        else{
                            if (*(char *) col->donnees[col->index[m]] > *((char *) val)){
                                b = m-1;
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;
                case FLOAT:
                    while (a < b){
                        if (*(float *) col->donnees[col->index[m]] == *((float *) val)){
                            return 1;
                        }
                        else{
                            if (*(float *) col->donnees[col->index[m]] > *((float *) val)){
                                b = m-1;
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;
                case DOUBLE:
                    while (a < b){
                        if (*(double *) col->donnees[col->index[m]] == *((double *) val)){
                            return 1;
                        }
                        else{
                            if (*(double *) col->donnees[col->index[m]] > *((double *) val)){
                                b = m-1;
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;
                case UINT:
                    while (a < b){
                        if (*(unsigned int *) col->donnees[col->index[m]] == *((unsigned int *) val)){
                            return 1;
                        }
                        else{
                            if (*(unsigned int *) col->donnees[col->index[m]] > *((unsigned int *) val)){
                                b = m-1;
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;
                case STRING:
                    while (a < b){
                        if(!strcmp((char*)val, (char*)col->donnees[m])){
                            return 1;
                        }
                        else{
                            if(strcmp((char*)val, (char*)col->donnees[m]) == -1){
                                b = m-1;
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;
                case NULLVAL:
                    return 0;
                    break;
                case STRUCTURE:
                    break;
            }
            return 0;
        }
    }
    else{
        return col->donnees[col->index[col->tlog]]==NULL;
    }
}

