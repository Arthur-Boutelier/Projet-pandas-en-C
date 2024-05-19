#include "cdataframe.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

CDATAFRAME* creer_cd(TYPE* type, long long int size){
    CDATAFRAME * cd = lst_create_list(); // on crée un cd vide
    char str[10];// nom de la colonne
    for (long long int i = 0; i<size; i++){
        long long int cmpt = i; // on récupère le i pour le mettre en nom de la colonne
        do {
            snprintf(str, 10, "%lld", cmpt++); // transforme cmpt en str et l'incremente
        } while (col_existe_cd(cd, str)); // vérifie si le nom est déja pris
        COLONNE * col = creer_colonne(type[i], str);
        lnode * p_nouv = lst_create_lnode(col);
        lst_insert_tail(cd, p_nouv);
    }
    return cd;
}

void remplir_cd(CDATAFRAME* cd) {
    long long int size;
    do {
        printf("Combien de ligne voulez vous rajoutez : ");
        scanf("%lld", &size);
    } while (size <= 0);
    lnode *temp = cd->head;
    while (temp != NULL) { // on parcourt toute les colonnes
        switch (temp->data->type) {// on vérifie le type
            case INT:
                printf("Veuillez remplir cette colonne d'entier\n");
                int *val_int = (int *) malloc(sizeof(int)); //cree l'emplacement de la valeur et on place un pointeur dessus
                for (int i = 0; i < size; i++) { // nombre de valeur
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n"); // on vérifie la présence d'une valeur
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) { // il y aune valeur  donc on l'entre
                        printf("Veuillez entrer la valeur : ");
                        scanf(" %d", val_int);
                        inserer_valeur(temp->data, (void *) val_int);// on rajoute la valeur dans la colonne
                    } else
                        inserer_valeur(temp->data, NULL);// on insere la valeur null
                }
                break;
            case CHAR:
                printf("Veuillez remplir cette colonne de caractere\n");
                char *val_char = (char *) malloc(sizeof(char));
                for (int i = 0; i < size; i++) {
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n");
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) {
                        printf("Veuillez entrer la valeur : ");
                        scanf(" %c", val_char);
                        inserer_valeur(temp->data, (void *) val_char);
                    } else
                        inserer_valeur(temp->data, NULL);
                }
                break;
            case UINT:
                printf("Veuillez remplir cette colonne d'entier non signé\n");
                unsigned int *val_uint = (unsigned int*) malloc(sizeof(unsigned int));
                for (int i = 0; i < size; i++) {
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n");
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) {
                        printf("Veuillez entrer la valeur : ");
                        scanf(" %u", val_uint);
                        inserer_valeur(temp->data, (void *) val_uint);
                    } else
                        inserer_valeur(temp->data, NULL);
                }
                break;
            case FLOAT:
                printf("Veuillez remplir cette colonne de nombres décimaux\n");
                float *val_float = (float*) malloc(sizeof(float));
                for (int i = 0; i < size; i++) {
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n");
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) {
                        printf("Veuillez entrer la valeur : ");
                        scanf(" %f", val_float);
                        inserer_valeur(temp->data, (void *) val_float);
                    } else
                        inserer_valeur(temp->data, NULL);
                }
                break;
            case DOUBLE:
                printf("Veuillez remplir cette colonne de double\n");
                double *val_double = (double *) malloc(sizeof(double));
                for (int i = 0; i < size; i++) {
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n");
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) {
                        printf("Veuillez entrer la valeur : ");
                        scanf(" %lf", val_double);
                        inserer_valeur(temp->data, (void *) val_double);
                    } else
                        inserer_valeur(temp->data, NULL);
                }
                break;
            case NULLVAL:
                inserer_valeur(temp->data, NULL);
                break;
            case STRUCTURE:
                break;
            case STRING:
                printf("Veuillez remplir cette colonne de chaine de caractere\n");
                char str[100];
                for (int i = 0; i < size; i++) {
                    int reponse;
                    printf("Ligne %d :\n", i);
                    do {
                        printf("Avez vous une valeur 0/1 (non/oui)\n");
                        scanf(" %d", &reponse);
                    } while (reponse != 1 && reponse != 0);
                    if (reponse) {
                        printf("Veuillez entrer la valeur :");
                        fflush(stdin);
                        fgets(str, 100, stdin);
                        inserer_valeur(temp->data, (void*) str);
                    } else
                        inserer_valeur(temp->data, NULL);
                }
                break;
        }
        temp = temp->next;
        }
}

void suppr_cd(CDATAFRAME** cd){
    lst_erase(*cd);// on efface la liste doublement chainé
    free(*cd);
    *cd = NULL;// On remet le pointeur vers NULL designant un cd inexistant
}

void ajouter_colonne(CDATAFRAME* cd, COLONNE* col){
    long long int taille = nb_ligne_cd(cd);
    lnode * temp = cd->head;
    if (taille < col->tlog){ // cas ou le cd à moins de ligne que la colonne
        while (temp != NULL){ // on partcourt le cd
            for (long long int i = 0; i<col->tlog-taille; i++)
                inserer_valeur(temp->data, NULL);// on rajoute des valeurs NULL jusqu'a avoir autant de ligne dans le dataframe et la colonne
            temp = temp->next;
        }
    }
    else if(taille>(col->tlog)){ // cas ou plus de ligne dans le cd que dans la colonne
        for (long long int i = 0; i<taille-col->tlog; i++)
            inserer_valeur(col, NULL); // on rajoute des valeurs dans la colonne
    }
    lnode* p_nouv = lst_create_lnode(col);
    lst_insert_tail(cd, p_nouv); // on rajoute la colonne dans la liste doublement chainé

}

void ajouter_ligne(CDATAFRAME* cd, CDATAFRAME* cd_2){
    lnode* temp_1 = cd->head; //head du 1er cd
    lnode* temp_2 = cd_2->head;// head du 2nd cd
    long long int taille_1 = nb_colonne_cd(cd), taille_2 = nb_colonne_cd(cd_2), compteur = 0;
    if (taille_1 < taille_2){ // cas ou plus de colonne dans le 2nd cd que dans le 1er -> on rajoute des colonnes dans le 1er dataframe
        long long int ecart_taille = taille_2 - taille_1;
        for (long long int i = 0; i<ecart_taille; i++){
            COLONNE * nouv_col = creer_colonne(NULLVAL, "");
            for (long long int j = 0; j<temp_1->data->tlog; j++)
                inserer_valeur(nouv_col, NULL);
            ajouter_colonne(cd, nouv_col);
        }
    }
    else if(taille_1 > taille_2){ // cas ou plus de colonne dans le 1er dataframe que le 2nd -> On rajoute des colonnes dans le 2nd
        long long int ecart_taille = taille_1 - taille_2;
        for (long long int i = 0; i<ecart_taille; i++){
            COLONNE * nouv_col = creer_colonne(NULLVAL, "");
            for (long long int j = 0; j<temp_2->data->tlog; j++)
                inserer_valeur(nouv_col, NULL);
            ajouter_colonne(cd_2, nouv_col);
        }
    }
    while (temp_1!=NULL) {// on parcouts la liste doublement chainé
        if (compteur++ >= taille_1) // cas ou la colonne a été rajouté dans le 1er cd
            temp_1->data->type = temp_2->data->type;
        if (temp_1->data->type == temp_2->data->type) {
            for (long long int i = 0; i < temp_2->data->tlog; i++) // on insere les valeurs présente dans la colonne du 2nd cd dans la colonne du 1er
                inserer_valeur(temp_1->data, temp_2->data->donnees[i]);
        }
        else{
            for (long long int i = 0; i < temp_2->data->tlog; i++)
                inserer_valeur(temp_1->data, NULL);
        }
        temp_1 = temp_1->next;
        temp_2 = temp_2->next;
    }
}

long long int nb_colonne_cd(CDATAFRAME* cd){
    lnode * temp = cd->head; // tete du cd
    long long int taille = 0;
    while (temp != NULL){ // on parcourt le cd
        taille++;
        temp = temp->next;
    }
    return taille;
}

long long int nb_ligne_cd(CDATAFRAME* cd){
    if(cd->head == NULL){// cd vide
        return 0;
    }
    return cd->head->data->tlog; //sinon on revoie la tl de la 1ere colonne car toute les colonnes on la même taille
}

void afficher_cd(CDATAFRAME* cd){
    if (cd != NULL) { //cas ou le cd est non vide
        lnode *temp;
        char str[100];
        afficher_nom_col(cd); // on affiche les noms des colonnes
        for (long long i = 0; i < nb_ligne_cd(cd); i++) { // on parcourt les lignes
            temp = cd->head;
            printf("[%7lld]  ", i);
            while (temp != NULL) { // Pour chaque ligne on parcourt les colonnes
                if (temp->data->donnees[i] != NULL) {
                    convert_val(temp->data, i, str, 100);// on récupere un str contenant la valeur
                    printf("%15s  ", str);
                } else
                    printf("%15s  ", "NULL");
                temp = temp->next;
            }
            printf("\n");
        }
    }
    else
        printf("Ce Dataframe n'existe pas\n");
}

void suppr_ligne(CDATAFRAME* cd, long long int indice){
    lnode* temp = cd->head;
    while(temp!= NULL){// on parcourt le cd
        colonne_supprimer_indice(temp->data, indice); // Pour chaque colonne on supprime l'element d'indice indice
        temp = temp->next;
    }
}
long long int nb_valeur_egal_cd(CDATAFRAME* cd, void* valeur, TYPE type_val){
    long long int occ = 0; // compteur
    lnode * temp = cd->head;
    while(temp != NULL){ // On parcourt le dataframe
        if(type_val == temp->data->type || valeur == NULL) // On vérifie si la colonne à le même type que la valeur
            occ += occurence(temp->data, valeur); // si c'est le cas on compte le nombre d'occurence de valeur dans la colonne
        temp = temp->next;
    }
    return occ;
}

long long int nb_valeur_sup_cd(CDATAFRAME* cd, void* valeur, TYPE type_val){
    long long int compteur = 0;
    lnode * temp = cd->head;
    while(temp != NULL){ // on parcourt le dataframe
        if(type_val == temp->data->type || valeur == NULL) // On vérifie la concordance entre les types
            compteur += nb_valeur_sup_col(temp->data, valeur);
        temp = temp->next;
    }
    return compteur;
}

long long int nb_valeur_inf_cd(CDATAFRAME* cd, void* valeur, TYPE type_val){
    long long int compteur = 0;
    lnode * temp = cd->head;
    while(temp != NULL){
        if(type_val == temp->data->type || valeur == NULL) // on parcourt le dataframe
            compteur += nb_valeur_inf_col(temp->data, valeur); // On vérifie la concordance entre les types
        temp = temp->next;
    }
    return compteur;
}

void afficher_nom_col(CDATAFRAME* cd){
    lnode* temp = cd->head;
    printf("           ");
    while (temp != NULL){ // on parcourt le cd
        printf("%15s  ", temp->data->titre); // on affiche le nom des colonnes
        temp = temp->next;
    }
    printf("\n");
}

int col_existe_cd(CDATAFRAME* cd, char* nom){
    lnode * temp = cd->head;
    while (temp != NULL){ // On parcourt le dataframe
        if (!strcmp(nom, temp->data->titre)) // on verifie si la colonne à le bon nom
            return 1;
        temp = temp->next;
    }
    return 0;
}

void modif_valeur(CDATAFRAME* cd, char* nom_col, long long int indice_ligne, void* nouv_val, TYPE type_n_v){
    lnode * temp = cd->head;
    if (col_existe_cd(cd,nom_col) && indice_ligne < nb_ligne_cd(cd)){ // On verifie si la valeur existe
        while (strcmp(temp->data->titre, nom_col) != 0) // on recupere la colonne
            temp = temp->next;
        if (temp->data->type == type_n_v)
            colonne_modif_valeur(temp->data, indice_ligne, nouv_val, type_n_v); // même signe entre les valeurs on les interchanges
        else
            printf("La modification n'a pas pu être effectuer");

    }
    else
        printf("La modification n'a pas pu etre effectuer\n");
}

void* obtenir_valeur(CDATAFRAME* cd, char* nom_col, long long int indice_ligne){
    lnode * temp = cd->head;
    if (col_existe_cd(cd,nom_col) && indice_ligne < nb_ligne_cd(cd)){ // on verifie si les indices existes
        while (strcmp(temp->data->titre, nom_col) != 0) // On recupere la colonne
            temp = temp->next;
        return valeur_pos(temp->data, indice_ligne); // on renvoie la valeur à l'indice indice_ligne dans la colonne
    }
    else
        printf("Veuillez vérifiez vos indices ils n'existent pas dans ce dataframe\n");
    return NULL;
}

int existe_cd(CDATAFRAME* cd, void* valeur, TYPE type_n_v){
    lnode * temp = cd->head;
    while (temp != NULL){ // on parcourt le dataframe
        if(temp->data->type == type_n_v || valeur == NULL){ // si la colonne est du bon type
            if(existe_col(temp->data, valeur)) // On vérifie si la valeur est dans la colonne
                return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void renommer_col(CDATAFRAME* cd, char* ancien_nom, char* nouveau_nom){
    lnode * temp = cd->head;
    if(col_existe_cd(cd, ancien_nom) && !col_existe_cd(cd, nouveau_nom)){ // On vérifie si la colonne existe et si la modification ne crée pas de doublon
        while(strcmp(temp->data->titre, ancien_nom) != 0) // on recupere la colonne
            temp = temp->next;
        strcpy(temp->data->titre, nouveau_nom); // on modifie le nom
    }
    else
        printf("Erreur pendant la modification du nom de la colonne veuillez verifier les informations transmises\n");
}

void suppr_colonne(CDATAFRAME* cd, char* nom){
    if(col_existe_cd(cd,nom)){ // on verifie si la colonne existe
        lnode * temp = cd->head;
        while(strcmp(temp->data->titre, nom) != 0) // On recupere la colonne
            temp = temp->next;
        lst_delete_lnode(cd, temp); // on supprime le maillon de la liste doublement chainé
    }
    else
        printf("Cette Colonne n'existe pas\n");
}

void afficher_ligne_entre(CDATAFRAME* cd, long long int debut, long long int fin){
    if (cd != NULL) { // On vérifie si le cd existe
        afficher_nom_col(cd);
        lnode *temp;
        char str[100];
        if (debut>fin){ // on vérifie le bon ordre des indice
            long long int val_temp = debut;
            debut = fin;
            fin = val_temp;
        }
        fin ++;
        if(debut >= 0 && fin >= 0 && debut < nb_ligne_cd(cd) && fin < nb_ligne_cd(cd)) { // on verifie si les indices sont valide
            for (long long i = debut; i < fin; i++) { // on parcourt les ligne
                temp = cd->head;
                printf("[%7lld]  ", i);
                while (temp != NULL) { // on parcourt les colonne
                    if (temp->data->donnees[i] != NULL) {
                        convert_val(temp->data, i, str, 100); // on recupere un string de la valeur
                        printf("%15s  ", str);
                    } else
                        printf("%15s  ", "NULL");
                    temp = temp->next;
                }
                printf("\n");
            }
        }
        else
            printf("Erreur les indices fournies ne sont pas bon\n");
    }
    else
        printf("Ce Dataframe n'existe pas\n");
}

void afficher_colonne_entre(CDATAFRAME* cd, char* nom_debut, char* nom_fin){
    if (cd != NULL) { // cas ou le cd existe
        lnode *temp = cd->head;
        char str[100];
        lnode * col_debut;
        lnode* col_fin;
        if(col_existe_cd(cd,nom_debut) && col_existe_cd(cd,nom_fin)){ // on verifie la presence des colonnes dans le cd
            while(strcmp(temp->data->titre, nom_debut) != 0 && strcmp(temp->data->titre, nom_fin) != 0) // on récupre le 1er cd à apparaitre
                temp = temp->next;
            if (strcmp(temp->data->titre, nom_debut) == 0) {
                col_debut = temp;
                while (strcmp(temp->data->titre, nom_fin) != 0)
                    temp = temp->next;
                col_fin = temp; // on récupere le 2eme cd à apparaitre
            }
            else {
                col_debut = temp;
                while (strcmp(temp->data->titre, nom_debut) != 0)
                    temp = temp->next;
                col_fin = temp;
            }
            printf("           ");
            temp = col_debut;
            while (temp != col_fin->next) { // on affiche les titres
                printf("%15s  ", temp->data->titre);
                temp = temp->next;
            }
            printf("\n");
            for (long long i = 0; i < nb_ligne_cd(cd); i++) { // On affiche le contenue des colonnes
                temp = col_debut;
                printf("[%7lld]  ", i);
                while (temp != col_fin->next) {
                    if (temp->data->donnees[i] != NULL) {
                        convert_val(temp->data, i, str, 100);
                        printf("%15s  ", str);
                    } else
                        printf("%15s  ", "NULL");
                    temp = temp->next;
                }
                printf("\n");
            }
        }
        else
            printf("Erreur les indices fournies ne sont pas bon\n");
    }
    else
        printf("Ce Dataframe n'existe pas\n");
}

CDATAFRAME* csv_vers_cd(char *nom_fichier, TYPE* dftype, int taille){
    void* val = malloc(sizeof(TYPE*)); // on cree un espace mémoire val
    FILE* fichier; // On cree un fichier
    fichier = fopen(nom_fichier, "rt"); // on ouvre le fichier
    CDATAFRAME * cd = creer_cd(dftype, taille); // on cree un cd principale
    CDATAFRAME* cd_intermediaire ;
    COLONNE * col;
    char ligne[100]; // contenue de la ligne
    char nom[10]; // nom des colonnes
    char* mot; // va contenir les mot
    const char * separateur = " ,-!"; // tableau des separateur possible dans un csv
    if (fichier == NULL){ // cas ou y a pas le fichier
        printf("Le fichier n'existe pas");
        return NULL;
    }
    while (fgets(ligne, 100, fichier) != NULL){
        cd_intermediaire = creer_cd(dftype, 0); // on cree le cd intermediaire
        mot = strtok(ligne, separateur); // on prend le 1er mot de la ligne (caractere jusqu'au premier delimiteur)
        for(long long int i = 0;i<taille; i++){ // on cree des taille colonne
            snprintf(nom,10, "%lld", i);
            col = creer_colonne(dftype[i], nom);
            switch (dftype[i]) { // En fonction du type on insere la valeur de mot dedans
                case NULLVAL:
                    inserer_valeur(col, NULL);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case INT:
                    *((int *) val) = atoi(mot); // convertisseur str to int
                    inserer_valeur(col, val);
                    ajouter_colonne(cd_intermediaire, col); // on rajoute la colonne dans le cd intermediaire
                    break;
                case FLOAT:
                    *(float *) val = strtof(mot, NULL);
                    inserer_valeur(col, val);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case CHAR:
                    *(char *) val = mot[0];
                    inserer_valeur(col, val);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case DOUBLE:
                    *(double *) val = strtol(mot, NULL, 10);
                    inserer_valeur(col, val);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case STRING:
                    inserer_valeur(col, mot);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case UINT:
                    *(unsigned int *) val = strtoul(mot, NULL, 10);
                    inserer_valeur(col, val);
                    ajouter_colonne(cd_intermediaire, col);
                    break;
                case STRUCTURE:
                    inserer_valeur(col, NULL);
                    ajouter_colonne(cd_intermediaire, col);
                    break;

            }
            mot = strtok(NULL, separateur); // on passe au mot suivant
        }
        ajouter_ligne(cd, cd_intermediaire); // on a un cd intermediaire d'une ligne que l'on rajoute dans le principale
        suppr_cd(&cd_intermediaire); // on supprime le cd intermediaire
    }
    fclose(fichier); // on ferme le fichier
    free(val);
    return cd;
}

void cd_vers_csv(CDATAFRAME* cd, char* nom_fichier){
    FILE* fichier;
    fichier = fopen(nom_fichier, "w");
    if (cd != NULL){ // on verifie si le cd est non nul
        lnode *temp;
        char str[100];
        for (long long i = 0; i < nb_ligne_cd(cd); i++) { // on parcourt les lignes du cd
            temp = cd->head;
            while (temp != NULL) { // on parcourt les colonnes
                if (temp->data->donnees[i] != NULL) {
                    convert_val(temp->data, i, str, 100); // on convertit la valeur du croissement ligne/colonne en str
                    fputs(str, fichier); // on l'ecrit dans le cd
                }
                else
                    fputs("NULL", fichier);
                temp = temp->next;
                if(temp == NULL)
                    fputs("\n", fichier); // ligne finit on saute une ligne
                else
                    fputs(", ", fichier); // ligne pas finit on met une virgule
            }
        }
    }
    else
        printf("Ce Dataframe n'existe pas\n");
    fclose(fichier); // on ferme le fichier
}

void afficher_cd_par_index(CDATAFRAME* cd, COLONNE* col){
    if (cd != NULL) {
        lnode *temp;
        char str[100];
        afficher_nom_col(cd); // on affiche le nom des colonnes
        for (long long i = 0; i < nb_ligne_cd(cd); i++) { // on parcourt les lignes
            temp = cd->head;
            printf("[%7lld]  ", i);
            while (temp != NULL) { // on parcourt les colonnes
                if (temp->data->donnees[col->index[i]] != NULL) { // parcourt en fonction de l'index
                    convert_val(temp->data, col->index[i], str, 100);
                    printf("%15s  ", str);
                } else
                    printf("%15s  ", "NULL");
                temp = temp->next;
            }
            printf("\n");
        }
    }
    else
        printf("Ce Dataframe n'existe pas\n");
}
