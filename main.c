#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
int main()
{
    int a=1,b=2, c=3, d=4;
    void* u = NULL;
    COLONNE * A= create_column(INT,"caca");
    printf("%s\n",A->titre);
    inserer_valeur(A,&b);
    inserer_valeur(A,&a);
    inserer_valeur(A,&c);
    inserer_valeur(A,&d);
    inserer_valeur(A,&d);
    inserer_valeur(A,&d);
    inserer_valeur(A,&d);
    print_col(A);
    printf("%lld\n", occurence(A,u));

    TYPE types[]={INT, INT, INT};
    CDATAFRAME* cd = creer_cd(types, 3);
    remplir_cd(cd);
    afficher_cd(cd);
    afficher_colonne_entre(cd, "0","1");
    return 0;
}
