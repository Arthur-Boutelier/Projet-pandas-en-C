/*
 * CDATAFRAME by Paul Lesage, Victor Proffit et Arthur Boutelier
 * Ce fichier est celui a lancer pour faire fonctionner le programme. C'est le coeur de ce dernier dans lequel vous pouvez
 * utiliser toutes les fonctions
 */
#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
#include "sort.h"
int main()
{
    TYPE type [] = {STRING,STRING,INT,CHAR, FLOAT };  //types de nos colonnes
    char nom_fichier[] ="//Users//macos//CLionProjects//Projet-C//étudiants.csv"; //import du fichier .csv
    COLONNE* col= creer_colonne(NULLVAL,"Numéro"); //création d'une colonne vide
    int modif=19;
    float moyenne_etudiants;
    CDATAFRAME * cd = csv_vers_cd(nom_fichier, type, 5); //copie du fichier .csv dans un cdataframe

    renommer_col(cd,"0","Nom");    //modification du nom des colonnes
    renommer_col(cd,"1","Prénom");
    renommer_col(cd,"2","Age");
    renommer_col(cd,"3","Classe");
    renommer_col(cd,"4","Moyenne");
    afficher_cd(cd);

    tri(cd->tail->data,DESC); //tri en fonction de la moyenne dans l'ordre croissant
    afficher_cd_par_index(cd,cd->tail->data);

    moyenne_etudiants=(*(float*) somme_col(cd->tail->data))/ nb_ligne_cd(cd); //calcul de la moyenne des étudiants
    printf("Moyenne des étudiants: %.2f \nNombre d'étudiants au dessus de la moyenne: %lld \n\n",moyenne_etudiants,nb_valeur_sup_col(cd->tail->data,&moyenne_etudiants));

    tri(cd->head->data,ASC); //tri en fonction du nom dans l'ordre alphabétique
    afficher_cd_par_index(cd,cd->head->data);

    suppr_colonne(cd,"Moyenne"); //supression de la colonne moyenne
    ajouter_colonne(cd,col);  //ajout d'une colonne vide au cdataframe
    modif_valeur(cd,"Age",0,&modif,INT); //changement d'une valeur
    suppr_ligne(cd,9); //suppression de la ligne 9
    afficher_cd(cd);

    cd_vers_csv(cd, "//Users//macos//CLionProjects//Projet-C//étudiants_copie.csv"); //copie du cdataframe dans un fichier .csv
    /*tri(cd->tail->prev->data,DESC); //tri en fonction de la classe dans l'ordre décroissant
    afficher_cd_par_index(cd,cd->tail->prev->data);*/
    return 0;
}
