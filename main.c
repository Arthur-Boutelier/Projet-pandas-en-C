#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
int main()
{
    int a=9,b=10;
    COLONNE * A= create_column(INT,"caca");
    printf("%s\n",A->titre);
    inserer_valeur(A,&a);
    inserer_valeur(A,&a);
    inserer_valeur(A,NULL);
    inserer_valeur(A,&b);
    print_col(A);
    printf("%lld\n", occurence(A,&a));
    //MODIFF DANS INSERER VALEUR !!!




    /*TYPE types[]={STRING,STRING, INT,FLOAT};

    suppr_cd(&etudiants);*/
    return 0;
}
