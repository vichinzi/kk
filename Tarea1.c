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

void insert(char *M,int pos,char *in){

};

char *F (char *C,int k){
	char *M = (char *)malloc(32*sizeof(char));
	int n = (strlen(C)), alv,alvaux = 1;
	unsigned int perm = factorial(n), permsubi;
	for (int i=1;i<=n;i++){
		alv = alvaux;
		permsubi = perm / i;

		int j;
		for( j=1;j<=i;j++){
			alv += permsubi;
			if(k<alv)
				insert(M,j,&C[i-1]);
		};

		alvaux = alvaux  + (j-1) * permsubi;
		perm /= i;

	}


	return M;
};





int main(int argc, char const *argv[]){	

	int T,k;
	scanf("%d", &T);
	char *C = (char *)malloc(32*sizeof(char));
	char *M;

	for(int i = 0; i < T ; i++){
		scanf("%s", C);
		scanf("%d",&k);

		M = F(C,k);
		//printf(M);
		fflush(stdin);
		free ((void *)M);

	}


		free ((void *)C);
	return 0;
}