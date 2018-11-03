#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"






unsigned long long int factorial (int n){
    if(n==1){
        return (1);
    }

    else if (n==0){
        return (1);
    }

    return (n * factorial(n-1));
};

/*******************************
Nombre funcion: insert
********************************
Descripcion:Inserta caracter in, entre caracteres de un string,
*si se necesita insertar al principio del string, la posicion
*que debe recibir es 1
********************************
entrada:
*  M: puntero a string
*  pos: posicion con el espacio entre caracteres a insertar
*  in: caracter a insertar
******
salida: vacio
*******************************/


void insert(char *M,int pos,char in){
    char aux[33]="";
    char aux2[2]="a";

    for(int i=0;i<=strlen(M);i++){
        if(i+1 == pos){
            aux2[0]=in;
            strcat(aux,aux2);

        }
        aux2[0]=M[i];
        strcat(aux,aux2);
    }

    strcpy(M,aux);

    if(strlen(M)==0){
        aux2[0]=in;
        strcat(M,aux2);
    }        
};

/*******************************
Nombre funcion getpos
********************************
Descripcion:Ocupando backtracking, avanza por ramas, para comprobar
*si la permutacion que se busca pertenece a esta, sino se llama recursivamente
*a la funcion para continuar buscando en la siguiente rama
********************************
entrada:
*  pos: posicion donde se insertara, si se acepta esta rama
*  permsubi: cantidad de permutaciones que no se han descartado
*  k: permutacion que se busca
*  alv: permutacion base
******
salida: pos, si esque esta es la subrama a la que pertenece la llave, se llama
*a la funcion de nuevo si es que no era esta.
*******************************/



int getpos(int pos, unsigned long long int permsubi,int k, unsigned long long int alv){
    if(k < alv)
        return(pos);

    else
        return(getpos(pos +1,permsubi,k,alv+permsubi));
};


/*******************************
Nombre funcion F
********************************
Descripcion:Busca la palabra desencriptada ocupando backtracking
********************************
entrada:
*  C: palabra a desencriptar
*  k: permutacion que se busca
******
salida: string nuevo (M), desencripatacion de C
*******************************/


char *F (char *C,int k){

    char *M = (char *)malloc(32*sizeof(char));
    int n = (strlen(C)), pos;
    unsigned long long int perm = factorial(n), permsubi, i, alv= 1;

    if(k>perm){
        strcpy(M,"Error: ingrese un valor de k valido");
        return (M);
    }

    for (i=1;i<=n;i++){
        
        permsubi = perm / i;
       
        pos = getpos(1,permsubi,k,alv+permsubi);
        insert(M,pos,C[i-1]);


        alv = alv  + (pos-1) * permsubi;

        
        perm /= i;

    }

    return M;
};
