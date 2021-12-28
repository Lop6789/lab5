#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include"chooser.h"
#include"fill.h"
int** create(int m, int n){
	int ** mtx = calloc(m, sizeof(int*));
	for (int i=0; i<m; ++i){
		mtx[i]=calloc(n,sizeof(int));
	}
	return mtx;
}


int **enter(int *mtxsize){
	const char enter[] = "Enter a number to select an action: ";
	const char choose[]="------------------------------------------\n1. Read from keyboard\n2. Read from file\n3. Generate random data\n4. Back\n------------------------------------------\n";
	const char size_m[]="Enter quantity of lines of matrix (m):";
	const char size_n[]="Enter quantity of columns of matrix (n):";
	int flag = 0;

	while (!flag){
		printf("%s\n",enter);
		printf("%s\n",choose);
		int res = chooser(4);

		switch(res){
			case 1:
				{printf("%s\n",size_m);
				int m=0, n=0;
				m = Silentchooser();

				printf("%s\n",size_n);

                                n = Silentchooser();

				int **mtxi = create(m,n);
				mtxsize[0]=m;
				mtxsize[1]=n;
				int **mtxfilled = fillkey(mtxi, m, n);
				printf("%d\n", mtxfilled[0][0]);
				return mtxfilled;
				}
				break;

			case 2:
				{
				char *filename = readline("Enter file name: ");
				int **mtxfilled = fillfile(filename, mtxsize);
				return mtxfilled;
				}
				break;
			case 3:{
				printf("%s\n",size_m);
                                int m=0, n=0;
				m = Silentchooser();

                                printf("%s\n",size_n);
				n = Silentchooser();

				int **mtxi = create(m,n);
				mtxsize[0]=m;
				mtxsize[1]=n;
				int **mtxfilled = fillrand(mtxi, m,n);

				return mtxfilled;
				}
				break;
			case 4:
				flag = 1;
				break;
			default:
				printf("Something went wrong, try again\n");
				break;
			}
		}
	//free();
	return NULL;
}
