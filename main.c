#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
int main()
{
    COLONNE * A= create_column(INT,"caca");
    printf("%s",A->titre);





    /*TYPE types[]={STRING,STRING, INT,FLOAT};
    int nbcol=4,nblig,note=15;
    CDATAFRAME* etudiants= creer_cd(types,nbcol);
    remplir_cd(etudiants);
    suppr_colonne(etudiants,"Prénoms");
    nbcol = nb_colonne_cd(etudiants);
    afficher_cd(etudiants);
    afficher_colonne_entre(etudiants,"Noms","Notes");
    afficher_ligne_entre(etudiants,24,31);
    suppr_ligne(etudiants,40);
    renommer_col(etudiants,"Notes","Moyennes");
    ajouter_colonne(etudiants, create_column(INT,"age"));
    ajouter_ligne(etudiants,*lst_create_list()); 
    if (existe_cd(etudiants,"Lesage")){
        printf("Cette valeur existe.");
    }
    else{
        printf("Cette valeur n'existe pas.");
    }
    afficher_nom_col(etudiants);
    nblig= nb_ligne_cd(etudiants);
    modif_valeur(etudiants,"Moyennes",21,&note);
    printf("La valeur colonne 'Noms' lignes 17 est: %p", obtenir_valeur(etudiants,"Noms",17));
    printf("%lld étudiants ont eu 15", nb_valeur_egal_cd(etudiants,&note));
    printf("%lld étudiants ont eu plus de 15", nb_valeur_sup_cd(etudiants,&note));
    printf("%lld étudiants ont eu moins de 15", nb_valeur_inf_cd(etudiants,&note));

    suppr_cd(&etudiants);*/
    return 0;
}
