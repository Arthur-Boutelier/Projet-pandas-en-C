/*
 * CDATAFRAME by Paul Lesage, Victor Proffit et Arthur Boutelier
 * Ce fichier comporte toutes les fonctions permettant de gérer les colonnes
 */
#include "colonne.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define taille_realloc 256


COLONNE* creer_colonne(TYPE type,char * title) // création de la classe colonne
{
    COLONNE * ptr=malloc(sizeof (COLONNE));

    strcpy(ptr->titre,title);//titre de la colonne
    ptr->donnees=NULL;//données de la colonne
    ptr->type=type;// type des données
    ptr->index=NULL; // indice des valeurs de la colonne
    ptr->tmax=0;
    ptr->tlog=0; //nombre de colonne
    ptr->valid_index=0;
    ptr->tri_dir = 0;

    return ptr;
}


void allocation_initial(COLONNE* col){
    switch(col->type){ //switch case pour résoudre le problème avec chaque type
        case INT: //type INT
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(int*));//allocation de la mémoire pour la colonne
            break;
        case CHAR:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(char*));
            break;
        case UINT:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(unsigned int*));
            break;
        case FLOAT:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(float *));
            break;
        case DOUBLE:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(double *));
            break;
        case STRING:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(char***));
            break;
        case STRUCTURE:
            col->donnees = (COLUMN_TYPE **) malloc(taille_realloc*sizeof(void**));
            break;
        case NULLVAL:
            col->donnees = (COLUMN_TYPE**) malloc(taille_realloc*sizeof (NULLVAL));
    }
    col->index=(int*)malloc(sizeof(int)*taille_realloc);
    for (int i=0;i<taille_realloc; i++) {
        col->index[i] = i;
    }
    col->tmax = 256;
}

void reallocation(COLONNE* col){
    COLUMN_TYPE ** ptr;
    ptr = realloc(col->donnees, col->tmax+taille_realloc); //réallocation de mémoire
    col->donnees = ptr;
    int* temp = realloc(col->index,(col->tmax + sizeof(int))*taille_realloc);
    if (temp != NULL)
        col->index = temp;
}
int inserer_valeur(COLONNE* col, void* val)
{
    int etat = 1;
    if (col->tmax == col->tlog){ //si il n'y a pas assez de place dans la mémoire pour insérer une nouvelle valeure
        etat = 0;
        if (col->tmax)
            reallocation(col);
        else
            allocation_initial(col);
    }
    if (val!=NULL){
        switch (col->type){ //switch case pour résoudre le problème avec chaque type
            case INT:
                col->donnees[col->tlog] = (COLUMN_TYPE*) malloc (sizeof(int)); // allocation de la mémoire pour le dernier élément
                *((int*)col->donnees[col->tlog])= *((int*)val); //insertion de la valeur en bout de colonne
                break;
            case CHAR:
                col->donnees[col->tlog] = (COLUMN_TYPE *) malloc (sizeof(char));
                *((char *)col->donnees[col->tlog])= *((char *)val);
                break;
            case UINT:
                col->donnees[col->tlog] = (COLUMN_TYPE *) malloc (sizeof(unsigned int));
                *((unsigned int*)col->donnees[col->tlog])= *((unsigned int*)val);
                break;
            case FLOAT:
                col->donnees[col->tlog] = (COLUMN_TYPE *) malloc (sizeof(float));
                *((float*)col->donnees[col->tlog])= *((float *)val);
                break;
            case DOUBLE:
                col->donnees[col->tlog] = (COLUMN_TYPE *) malloc (sizeof(double));
                *((double *)col->donnees[col->tlog])= *((double *)val);
                break;
            case STRING:
                col->donnees[col->tlog] = (COLUMN_TYPE *) malloc (sizeof(char)*strlen(val));
                strcpy((char *)col->donnees[col->tlog], (char *)val);
                break;
            case STRUCTURE:
                break;
            case NULLVAL:
                col->donnees[col->tlog] = NULL;
                break;
        }
        col->tlog +=1;
    }
    else{
        *(col->donnees+col->tlog)=NULL;
        col->tlog+=1;
    }
    if (col->index)
        col->valid_index = -1;
    actualiser_index(col);
    return etat;
}

void supprimer_colonne(COLONNE *col)
{
    int i;
    for (i = col->tlog;i>0;i--){ //on parcours chaque ligne de la colonne
        free(col->donnees[i-1]);//on supprime chaque données
    }
    free(col->index);
    free(col->donnees);
    free(col); //on supprime la colonne
}

void print_col(COLONNE *col)
{
    int n=col->tlog;
    char str[100];
    for (int i=0;i<n;i++)
    {
        if( (col->donnees[i])==NULL    )
        {
            printf("[%d]    NULL\n",i); //on affiche NULL si la colonne est null
        }
        else
        {
            if (col->type==STRING){ // on étudie le cas pour le type STRING
                printf("[%d]    %s\n",i,(char*)col->donnees[i]); //On affiche la valeur
            }
            else{
                convert_val(col,i,str,100); //on convertie la valeur en str
                printf("[%d]    %s\n",i,str); // on l'affiche
            }
        }
    }
    printf("\n");
}
void convert_val(COLONNE * col , unsigned long long int indice, char* str, int taille)
{
    switch(col->type){ //switch case pour résoudre le problème avec chaque type
        case INT:
            snprintf(str, taille, "%d", *((int*)col->donnees[indice])); //on convertie le type en format str
            break;
        case CHAR:
            snprintf(str, taille, "%c", *((char*)col->donnees[indice]));
            break;
        case UINT:
            snprintf(str, taille, "%ud", *((unsigned int*)col->donnees[indice]));
            break;
        case FLOAT:
            snprintf(str, taille, "%f", *((float*)col->donnees[indice]));
            break;
        case DOUBLE:
            snprintf(str, taille, "%lf", *((double*)col->donnees[indice]));
            break;
        case STRING:
            strcpy(str, (char*)col->donnees[indice]);
            break;
        case STRUCTURE:
            break;
        case NULLVAL:
            strcpy(str, "NULL");
    }
}

long long int occurence(COLONNE * col, void* valeur){
    long long int nb_occurrence = 0;
    if (valeur != NULL) {
        switch (col->type) { //switch case pour résoudre le problème avec chaque type
            case (NULLVAL):
                break;
            case INT: // cas pour int
                for (long long int i = 0; i < col->tlog; i++) { //on parcours la colonne
                    if (col->donnees[i] != NULL) {
                        if (*((int *) (col->donnees[i])) == *((int *) valeur)) //si la valeur est la même que celle recherché
                            nb_occurrence++; //on incrémente 1 car c'est la valeur recherché
                    }
                }
                break;
            case CHAR:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (col->donnees[i] != NULL) {
                        if (*((char *) (col->donnees[i])) == *((char *) valeur))
                            nb_occurrence++;
                    }
                }
                break;
            case UINT:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (col->donnees[i] != NULL) {
                        if (*((unsigned int *) (col->donnees[i])) == *((unsigned int *) valeur))
                            nb_occurrence++;
                    }
                }
                break;
            case FLOAT:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (col->donnees[i] != NULL) {
                        if (*((float *) (col->donnees[i])) == *((float *) valeur))
                            nb_occurrence++;
                    }
                }
                break;
            case DOUBLE:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (col->donnees[i] != NULL) {
                        if (*((double *) (col->donnees[i])) == *((double *) valeur))
                            nb_occurrence++;
                    }
                }
                break;
            case STRING:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (col->donnees[i] != NULL) {
                        if (!strcmp(*((char **) (col->donnees[i])), *((char **) valeur)))
                            nb_occurrence++;
                    }
                }
                break;
            case STRUCTURE:
                break;
        }
    }
    else{
        for (long long int i = 0; i < col->tlog; i++) { //on parcours la colonne
            if (col->donnees[i] == NULL) //si la valeur de la colonne est NULL
                    nb_occurrence++; // alors on incrémente 1
        }
    }
    return nb_occurrence;
}

void* valeur_pos(COLONNE* col, long long int indice){
    if (indice<col->tlog)
        return (col->donnees[indice]); // on retourne la valeur à la position indice si l'indice est plus petit que le nombre de colonne
    return NULL;
}

long long int nb_valeur_inf_col(COLONNE* col, void* valeur){
    long long int cmpt = 0; //on initialise un compteur
    switch (col->type) { //switch case pour résoudre le problème avec chaque type
        case(NULLVAL):
            break;
        case INT: // cas pour le type INT
            for (long long int i = 0; i<col->tlog; i++){ //on parcours la colonne
                if (col->donnees[i]!=NULL) { //si la valeur à l'indice i n'est pas NULL
                    if (*((int*)(col->donnees[i])) < *((int*)valeur))//alors on regarde si la valeur est plus grande que la valeur dans la colonne
                        cmpt++; // on incrémente
                }}
            break;
        case CHAR:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((char*)(col->donnees[i])) < *((char*)valeur))
                        cmpt++;
                }}
            break;
        case UINT:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((unsigned int*)(col->donnees[i])) < *((unsigned int*)valeur))
                        cmpt++;
                }}
            break;
        case FLOAT:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((float*)(col->donnees[i])) < *((float*)valeur))
                        cmpt++;
                }}
            break;
        case DOUBLE:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((double *)(col->donnees[i])) < *((double*)valeur))
                        cmpt++;
                }}
            break;
        case STRING:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (strcmp(*((char **)(col->donnees[i])), *((char**)valeur))<0)
                        cmpt++;
                }}
            break;
        case STRUCTURE:
            break;
    }
    return cmpt;
}


long long int nb_valeur_sup_col(COLONNE* col, void* valeur){
    long long int cmpt = 0;
    switch (col->type) { //switch case pour résoudre le problème avec chaque type
        case(NULLVAL):
            break;
        case INT:
            for (long long int i = 0; i<col->tlog; i++){ //on parcours la colonne
                if (col->donnees[i]!=NULL) { //si la valeur n'est pas NULL
                    if (*((int*)(col->donnees[i])) > *((int*)valeur)) // on regarde si la valeur est inférieur à la valeur de la colonne
                        cmpt++;//on incrémente
                }}
            break;
        case CHAR:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((char*)(col->donnees[i])) > *((char*)valeur))
                        cmpt++;
                }}
            break;
        case UINT:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((unsigned int*)(col->donnees[i])) > *((unsigned int*)valeur))
                        cmpt++;
                }}
            break;
        case FLOAT:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((float*)(col->donnees[i])) > *((float*)valeur))
                        cmpt++;
                }}
            break;
        case DOUBLE:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (*((double *)(col->donnees[i])) > *((double*)valeur))
                        cmpt++;
                }}
            break;
        case STRING:
            for (long long int i = 0; i<col->tlog; i++){
                if (col->donnees[i]!=NULL) {
                    if (strcmp(*((char **)(col->donnees[i])), *((char**)valeur))>0)
                        cmpt++;
                }}
            break;
        case STRUCTURE:
            break;
    }
    return cmpt;
}

void colonne_supprimer_indice(COLONNE* col, long long int indice){
    if (indice<col->tlog){
        for (long long int i = indice; i<col->tlog-1;i++) //on parcours la colonne à partir de l'indice
            col->donnees[i]=col->donnees[i+1]; //on décale chaque valeur
        free(col->donnees[col->tlog]); //on supprime la mémoire allouer pour la dernière valeur
        col->tlog--; // on décrémente la taille logique
    }
}

void colonne_modif_valeur(COLONNE* col, long long int indice, void* nouv_val, TYPE type_n_v){
    if (col->donnees[indice] == NULL && nouv_val != NULL)
        col->donnees[indice] = malloc(sizeof(COLUMN_TYPE));
    if (nouv_val == NULL) {
        free(col->donnees[indice]);
        col->donnees[indice] = NULL;
    }
    else {
        if (col->type == type_n_v) {
            switch (col->type) { //switch case pour résoudre le problème avec chaque type
                case NULLVAL:
                    break;
                case INT:
                    *((int *) col->donnees[indice]) = *((int *) nouv_val);//on modifie la valeur à l'indice souhaité
                    break;
                case CHAR:
                    *((char *) col->donnees[indice]) = *((char *) nouv_val);
                    break;
                case FLOAT:
                    *((float *) col->donnees[indice]) = *((float *) nouv_val);
                    break;
                case DOUBLE:
                    *((double *) col->donnees[indice]) = *((double *) nouv_val);
                    break;
                case STRING:
                    strcpy((char *) col->donnees[indice], (char *) nouv_val);
                    break;
                case STRUCTURE:
                    break;
                case UINT:
                    *((unsigned int *) col->donnees[indice]) = *((unsigned int *) nouv_val);
                    break;
            }
        }
    }
}

int existe_col(COLONNE* col, void* val){
    if(val != NULL) {
        switch (col->type) { //switch case pour résoudre le problème avec chaque type
            case INT: //cas pour le type INT
                for (long long int i = 0; i < col->tlog; i++) { //on parcours la colonne
                    if (*((int *) col->donnees[i]) == *((int *) val)) // si la valeur est égale à la valeur à l'indice i
                        return 1;
                }
                break;
            case CHAR:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (*((char *) col->donnees[i]) == *((char *) val))
                        return 1;
                }
                break;
            case FLOAT:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (*((float *) col->donnees[i]) == *((float *) val))
                        return 1;
                }
                break;
            case DOUBLE:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (*((double *) col->donnees[i]) == *((double *) val))
                        return 1;
                }
                break;
            case UINT:
                for (long long int i = 0; i < col->tlog; i++) {
                    if (*((unsigned int *) col->donnees[i]) == *((unsigned int *) val))
                        return 1;
                }
                break;
            case STRING:
                for(long long int i = 0; i<col->tlog; i++){
                    if(!strcmp((char*)val, (char*)col->donnees[i]))
                        return 1;
                }
                break;
            case NULLVAL:
                if(col->tlog != 0)
                    return 1;
            case STRUCTURE:
                break;
        }
    }
    else{
        for(long long int i = 0; i<col->tlog; i++){
            if(col->donnees[i] == NULL) //si la valeur à l'indice i est égale à NULL
                return 1;
            }
    }
    return 0;
}
void print_col_index(COLONNE* col){
    char str[100];
    for (int i=0;i<col->tlog;i++){ // on parcours la colonne
        if( (col->donnees[col->index[i]])==NULL) // si la valeur de la données est NULL
        {
            printf("[%d]    NULL\n",i);
        }
        else
        {
            if (col->type==STRING){ //si le type de la colonne est string
                printf("[%d]    %s\n",i,(char*)col->donnees[col->index[i]]); //on affiche les indice
            }
            else{
                convert_val(col,col->index[i],str,100); //on convertie en str
                printf("[%d]    %s\n",i,str);
            }}
    }
    printf("\n");
}

void effacer_index(COLONNE* col){
    col->valid_index=0;
}

void print_index(COLONNE * col){
    for (int i=0;i<col->tlog;i++){ // on parcours la colonne
        printf("%d ",col->index[i]); // on affiche l'indice
    }
    printf("\n");
}

int verif_index(COLONNE *col){
    if (col->index==NULL){
        return 0;
    }
    if (col->valid_index==1){ //si la liste est trié
        return 1;
    }
    return -1;
}


int chercher_val_col_dicho(COLONNE *col, void *val){
    if(val != NULL){
        if (col->valid_index != 1){ //vérification si la liste est trié
            return -1;
        }

        else{
            int a = 0; //initialisation des variables de la dichotomie
            int b = col->tlog - 1;
            int m = (a + b) / 2; // m étant le milieu des indices de la colonne
            switch (col->type) { //switch case pour résoudre le problème avec chaque type
                case INT: //cas pour le type int
                    while (a < b){ //tant que le debut n'aura pas rejoint la fin
                        if (*(int *) col->donnees[col->index[m]] == *((int *) val)){ //on regarde si le milieu n'est pas la valeur recherché
                            return 1;
                        }
                        else{
                            if (*(int *) col->donnees[col->index[m]] > *((int *) val)){ //sinon on regarde la valeur à l'indice m est plus grand que la valeur
                                b = m-1; // on ramène la fin au milieu
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;

                case CHAR://cas pour le type char
                    while (a < b){//cas pour le type int
                        if (*(char *) col->donnees[col->index[m]] == *((char *) val)){//on regarde si le milieu n'est pas la valeur recherché
                            return 1;
                        }
                        else{
                            if (*(char *) col->donnees[col->index[m]] > *((char *) val)){//sinon on regarde la valeur à l'indice m est plus grand que la valeur
                                b = m-1;
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;
                case FLOAT://cas pour le type float
                    while (a < b){//cas pour le type int
                        if (*(float *) col->donnees[col->index[m]] == *((float *) val)){//on regarde si le milieu n'est pas la valeur recherché
                            return 1;
                        }
                        else{
                            if (*(float *) col->donnees[col->index[m]] > *((float *) val)){//sinon on regarde la valeur à l'indice m est plus grand que la valeur
                                b = m-1;
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;
                case DOUBLE://cas pour le type double
                    while (a < b){//cas pour le type int
                        if (*(double *) col->donnees[col->index[m]] == *((double *) val)){//on regarde si le milieu n'est pas la valeur recherché
                            return 1;
                        }
                        else{
                            if (*(double *) col->donnees[col->index[m]] > *((double *) val)){//sinon on regarde la valeur à l'indice m est plus grand que la valeur
                                b = m-1;
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;
                case UINT://cas pour le type unit
                    while (a < b){//cas pour le type int
                        if (*(unsigned int *) col->donnees[col->index[m]] == *((unsigned int *) val)){//on regarde si le milieu n'est pas la valeur recherché
                            return 1;
                        }
                        else{
                            if (*(unsigned int *) col->donnees[col->index[m]] > *((unsigned int *) val)){//sinon on regarde la valeur à l'indice m est plus grand que la valeur
                                b = m-1;
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;
                case STRING://cas pour le type string
                    while (a < b){//cas pour le type int
                        if(!strcmp((char*)val, (char*)col->donnees[m])){//on regarde si le milieu n'est pas la valeur recherché
                            return 1; //la fonction strcmp sert à comparé dans l'ordre lexicographique les deux valeurs
                        }
                        else{
                            if(strcmp((char*)val, (char*)col->donnees[m]) == -1){//sinon on regarde la valeur à l'indice m est plus grand que la valeur avec la fonction strcmp
                                b = m-1;
                            }
                            else{
                                a = m+1;
                            }
                        }
                    }
                    break;
                case NULLVAL: //cas pour le type nullval
                    return 0;
                    break;
                case STRUCTURE: //cas pour le type structure
                    break;
            }
            return 0;
        }
    }
    else{
        return col->donnees[col->index[col->tlog]]==NULL;
    }
}

void actualiser_index(COLONNE* col) {
    tri(col, col->tri_dir);
}
void* somme_col(COLONNE* col){
    void* somme= malloc(64);
    switch (col->type) {
        case INT:
            for (int i=0;i<col->tlog;i++){
                *(int*)somme+=*(int*)col->donnees[i];
            }
            break;
        case FLOAT:
            for (int i=0;i<col->tlog;i++){
                *(float*)(somme)+=*(float*)col->donnees[i];
            }
            break;
        case DOUBLE:
            for (int i=0;i<col->tlog;i++){
                *(double*)somme+=*(double*)col->donnees[i];
            }
            break;
        case UINT:
            for (int i=0;i<col->tlog;i++){
                *(unsigned int*)somme+=*(unsigned int*)col->donnees[i];
            }
            break;
        case STRING:
            free(somme);
            somme=NULL;
            break;
        case CHAR:
            free(somme);
            somme=NULL;
            break;
        case STRUCTURE:
            free(somme);
            somme=NULL;
            break;
        case NULLVAL:
            free(somme);
            somme=NULL;
            break;

    }
    return somme;
}
