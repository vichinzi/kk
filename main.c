#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main(int argc, char const *argv[]){ 

    int T,k;
    scanf("%d", &T); // cantidad de consultas
    char *C = (char *)malloc(33*sizeof(char));
    char *M;

    for(int i = 0; i < T ; i++){
        scanf("%s", C);    //String a desencriptar
        scanf("%d",&k);    //LLave, que contiene la permutacion que se busca

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
