#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main(int argc, char const *argv[]){ 

    int T,k;
    T=argv[0]; // cantidad de consultas
    char *C = (char *)malloc(32*sizeof(char));
    char *M; // String a entregar al usuario

    for(int i = 1; i < T ; i++){
        C = argv[i];//String a desencriptar
        i++;
        k = argv[i];    //LLave, que contiene la permutacion que se busca

        if(strlen(C)>20){
            printf("Error: String ingresado no debe tener mas de 20 caracteres\n");
            continue;
        }

        M = F(C,k);
        printf("%s\n",M );  //Se imprime string desencriptado
        fflush(stdin);
        free ((void *)M);
    }


    free ((void *)C);
    return 0;
}
