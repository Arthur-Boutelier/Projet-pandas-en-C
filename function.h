#ifndef PROJET_C_FUNCTION_H
#define PROJET_C_FUNCTION_H

typedef enum
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
}TYPE;

typedef union {
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
}COLUMN_TYPE;

typedef struct{
    char * titre;
    int tmax;
    int tlog;
    COLUMN_TYPE ** donnees;
    TYPE type;
    int* index;


}COLONNE;
typedef struct{
    COLONNE * Tab;
    int nbCol;
}CDataframe;




COLONNE* create_column(char *);
int insert_value(COLONNE* , int);
void delete_column(COLONNE **);
void print_col(COLONNE *);
#endif
