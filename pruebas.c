
#include <stdio.h>

#include <string.h>

void insert(char *M,int pos,char in){
    char aux[33]="";
    char aux2[2]="a";
    for(int i=0;i<=strlen(M);i++){
        printf("%d %d\n",i+1,pos );
        if(i+1 == pos){
            aux2[0]=in;
            strcat(aux,aux2);
            

        }
        aux2[0]=M[i];
        strcat(aux,aux2);
    }


    strcpy(M,aux);
        
}


int main() {
    char M[33]= "holaa";
    insert(M,6,'a');
    printf("%s\n",M );
    return (0);
}