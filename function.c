#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
COLONNE* create_column(char * title)
{
    COLONNE col; COLONNE * ptr=NULL;
    col.titre=title; col.donnees=NULL; col.tlog=0; col.tmax=256; ptr=&col;
    return ptr;
}
int insert_value(COLONNE* col, int val)
{
    if (col->tmax >col->tlog)
    {
        (col->donnees)[col->tlog]=val;(col->tlog)++; return 1;
    }
    else {return 0;}
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
