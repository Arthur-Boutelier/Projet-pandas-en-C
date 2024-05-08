#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
int main()
{
    int a=9,b=10;
    void* u = NULL;
    COLONNE * A= create_column(INT,"caca");
    printf("%s\n",A->titre);
    inserer_valeur(A,&a);
    inserer_valeur(A,&a);
    inserer_valeur(A,NULL);
    inserer_valeur(A,&b);
    print_col(A);
    printf("%lld\n", occurence(A,u));
    //MODIFF DANS INSERER VALEUR !!!


    TYPE types[]={STRING, INT};
    CDATAFRAME* cd = creer_cd(types, 1);
    remplir_cd(cd);
    print_col(cd->head->data);
    /*
    suppr_cd(&etudiants);*/
    return 0;
}
