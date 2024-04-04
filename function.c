#include "function.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
COLONNE* create_column(char * title)
{
    COLONNE col; COLONNE * ptr=NULL;
    col.titre=title; col.donnees=NULL; col.tlog=0; col.tmax=256; ptr=&col;
    return ptr;
}
int inserer_valeur(COLONNE* col, void* val)
{
    if (col->tmax == col->tlog)
        return 0;
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
            *((char*)col->donnees[col->tlog])= *((char*)val);
            break;
        case STRUCTURE:
            return 1;
    }
    col->tlog +=1;
    return 1;
}

void delete_column(COLONNE **ptr)
{
    free((*ptr)->donnees);
    free(ptr);
}
void print_col(COLONNE *col)
{
    int n=col->tlog;
    for (int i=0;i<n;i++)
    {
        printf("[%d]   %d\n",i,(col->donnees)[i]);
    }
}
