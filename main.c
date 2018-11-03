#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main(int argc, char const *argv[]){ 

    int T,k;
    scanf("%d", &T);
    char *C = (char *)malloc(33*sizeof(char));
    char *M;

    for(int i = 0; i < T ; i++){
        scanf("%s", C);
        scanf("%d",&k);

        if(strlen(C)>32){
            printf("Error: String ingresado no debe tener mas de 32 caracteres\n");
            continue;
        }

        M = F(C,k);
        printf("%s\n",M );
        fflush(stdin);
        free ((void *)M);
    }


    free ((void *)C);
    return 0;
}