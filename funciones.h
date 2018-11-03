#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Funcion encargada de calcular el factorial de un numero dado*/
unsigned long long int factorial (int n);

/*Funcion encargada de insertar un caracter en un determinado string segun la posicion requerida*/
void insert(char *M,int pos,char in);

/**/
int getpos(int pos, unsigned long long int permsubi,int k, unsigned long long int alv);

/**/
char *F (char *C,int k);






#endif // FUNCTIONS_H