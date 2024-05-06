#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
int main()
{
    int a=12,b=-4;
    COLONNE * A= create_column(INT,"caca");
    printf("%s\n",A->titre);
    /*inserer_valeur(A,&a);
    inserer_valeur(A,NULL);
    inserer_valeur(A,&b);*/
    for (int i=0;i<5;i++){
        inserer_valeur(A,&i);
    }
    printf("%lld\n", nb_valeur_inf_col(A, (void*)(&b)));

    print_col(A);
    //MODIFF DANS INSERER VALEUR !!!




    /*TYPE types[]={STRING,STRING, INT,FLOAT};

    suppr_cd(&etudiants);*/
    return 0;
}
