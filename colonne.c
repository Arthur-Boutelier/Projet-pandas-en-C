#include "colonne.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define taille_realloc 256
COLONNE* create_column(TYPE type,char * title)
{
    COLONNE * ptr=malloc(sizeof (COLONNE));
    if (title==NULL){return NULL;}
    ptr->titre=title;ptr->donnees=NULL; ptr->type=type;ptr->index=NULL;ptr->tmax=0;ptr->tlog=0;
    return ptr;
}


void allocation_initial(COLONNE* col){
    switch(col->type){
        case INT:
            col->donnees = (int**) malloc(taille_realloc*sizeof(int*));
            break;
        case CHAR:
            col->donnees = (char**) malloc(taille_realloc*sizeof(char*));
            break;
        case UINT:
            col->donnees = (unsigned int**) malloc(taille_realloc*sizeof(unsigned int*));
            break;
        case FLOAT:
            col->donnees = (float **) malloc(taille_realloc*sizeof(float *));
            break;
        case DOUBLE:
            col->donnees = (double **) malloc(taille_realloc*sizeof(double *));
            break;
        case STRING:
            col->donnees = (char***) malloc(taille_realloc*sizeof(char***));
            break;
        case STRUCTURE:
            col->donnees = (void**) malloc(taille_realloc*sizeof(void**));
            break;
    }
    col->tmax = 256;
}

void reallocation(COLONNE* col){
    void ** ptr;
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
    switch (col->type){
        case INT:
            col->donnees[col->tlog] = (int*) malloc (sizeof(int));
            *((int*)col->donnees[col->tlog])= *((int*)val);
            break;
        case CHAR:
            col->donnees[col->tlog] = (char *) malloc (sizeof(char));
            *((char *)col->donnees[col->tlog])= *((char *)val);
            break;
        case UINT:
            col->donnees[col->tlog] = (unsigned int*) malloc (sizeof(unsigned int));
            *((unsigned int*)col->donnees[col->tlog])= *((unsigned int*)val);
            break;
        case FLOAT:
            col->donnees[col->tlog] = (float*) malloc (sizeof(float));
            *((float*)col->donnees[col->tlog])= *((float *)val);
            break;
        case DOUBLE:
            col->donnees[col->tlog] = (double *) malloc (sizeof(double));
            *((double *)col->donnees[col->tlog])= *((double *)val);
            break;
        case STRING:
            col->donnees[col->tlog] = (char*) malloc (sizeof(char)*strlen(val));
            *((char*)(col->donnees[col->tlog]))= *((char*)val);
            break;
        case STRUCTURE:
            break;
    }
    col->tlog +=1;
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
    for (int i=0;i<n;i++)
    {
        printf("[%d]   %d\n",i,(col->donnees)[i]);
    }
}

long long int occurence(COLONNE * col, void* valeur){
    long long int nb_occurrence = 0;
    switch (col->type) {
        case(NULLVAL):
            break;
        case INT:
            for (long long int i = 0; i<col->tlog; i++){
                if (*((int*)(col->donnees[i])) == *((int*)valeur))
                    nb_occurrence++;
            }
            break;
        case CHAR:
            for (long long int i = 0; i<col->tlog; i++){
                if (*((char*)(col->donnees[i])) == *((char*)valeur))
                    nb_occurrence++;
            }
            break;
        case UINT:
            for (long long int i = 0; i<col->tlog; i++){
                if (*((unsigned int*)(col->donnees[i])) == *((unsigned int*)valeur))
                    nb_occurrence++;
            }
            break;
        case FLOAT:
            for (long long int i = 0; i<col->tlog; i++){
                if (*((float*)(col->donnees[i])) == *((float*)valeur))
                    nb_occurrence++;
            }
            break;
        case DOUBLE:
            for (long long int i = 0; i<col->tlog; i++){
                if (*((double *)(col->donnees[i])) == *((double*)valeur))
                    nb_occurrence++;
            }
            break;
        case STRING:
            for (long long int i = 0; i<col->tlog; i++){
                if (!strcmp(*((char **)(col->donnees[i])), *((char**)valeur)))
                    nb_occurrence++;
            }
            break;
        case STRUCTURE:
            break;
    }
    return nb_occurrence;
}


