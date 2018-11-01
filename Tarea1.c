#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned int factorial (int n){
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



    for(int i=0;i<strlen(M);i++){
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
        
}

/*
int getpos(int pos, unsigned int permsubi,int k,int alv){
	if(k < alv)
		return(pos);
	else
		getpos(pos +1,permsubi,k,alv+permsubi);
};


*/


char *F (char *C,int k){
	char *M = (char *)malloc(32*sizeof(char));
	int n = (strlen(C)), alv,alvaux = 1;
	unsigned int perm = factorial(n), permsubi;
	for (int i=1;i<=n;i++){
		alv = alvaux; //se va
		permsubi = perm / i;



		//En vez de esta mierda lo de abajoooo

		int j;
		for( j=1;j<=i;j++){
			alv += permsubi;
			if(k<alv){
				insert(M,j,C[i-1]);
				break;
				printf("i:%d, j:%d\n",i,j);
				
			}	
		};

		
		//pos = getpos(1,permsubi,k,alv+permsubi);




		alvaux = alvaux  + (j-1) * permsubi;

		//Cambiar j por pos 
		//alvaux por alv

		perm /= i;

	}

	return M;
};





int main(int argc, char const *argv[]){	

	int T,k;
	scanf("%d", &T);
	char *C = (char *)malloc(33*sizeof(char));
	char *M;

	for(int i = 0; i < T ; i++){
		scanf("%s", C);
		scanf("%d",&k);

		M = F(C,k);
		printf("%s\n",M );
		fflush(stdin);
		free ((void *)M);

	}


		free ((void *)C);
	return 0;
}