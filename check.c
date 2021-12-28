#include <stdio.h>

int check(int qty){
	int n=0, iferr = 0;
	const char error[] = "Error, check your input and try again!";
	do{
		iferr = 0;
		printf("%s\n", error);
		while(getchar()!='\n'){}
		iferr = scanf("%d", &n);
		//printf("%d\n",iferr);
		//printf("%d\n", qty);
	}while(iferr!=1 || (n>qty || n<1));
	return n;
}


int Silentcheck(){
        int n=0, iferr = 0;
        const char error[] = "Error, check your input and try again!";
        do{
                iferr = 0;
                printf("%s\n", error);
                while(getchar()!='\n'){}
                iferr = scanf("%d", &n);
                //printf("%d\n",iferr);
                //printf("%d\n", qty);
        }while(iferr!=1);
        return n;
}

