#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
{
    int *ptr= malloc(sizeof(int)*3);
    COLONNE B={"bonjour",256,3,ptr};
    COLONNE* A=&B;
    insert_value(A,5);
    print_col(A);
    return 0;
}
