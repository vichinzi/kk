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


int getpos(int pos, unsigned long long int permsubi,int k, unsigned long long int alv){
    if(k < alv)
        return(pos);

    else
        return(getpos(pos +1,permsubi,k,alv+permsubi));
};





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

        //Cambiar j por pos 
        //alvaux por alv

        perm /= i;

    }

    return M;
};
