#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include "edit.h"
#include"chooser.h"
#include"fill.h"
int** create(int m, int n){
	int ** mtx = calloc(m, sizeof(int*));
	for (int i=0; i<m; ++i){
		mtx[i]=calloc(n,sizeof(int));
	}
	return mtx;
}

int **cpy(int **dest, int **src, int *size){
        printf("%d %d \n", size[0], size[1]);
        dest = create(size[0], size[1]);
        for (int i=0; i<size[0]; i++){
                for (int j=0; j<size[1]; j++){
                        dest[i][j] = src[i][j];
                }
        }
        return dest;
}



int **enter(int **getData, int *mtxsize, int **editData, int *editmtxsize){
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
				{if (editData && editData!=NULL) fullfree(editData, editmtxsize[0]);
				if (getData && getData!=NULL) fullfree(getData, mtxsize[0]);
				printf("%s\n",size_m);
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
				{if (editData && editData!=NULL) fullfree(editData, editmtxsize[0]);
                                if (getData && getData!=NULL) fullfree(getData, mtxsize[0]);
				char *filename = readline("Enter file name: ");
				int **mtxfilled = fillfile(filename, mtxsize);
				return mtxfilled;
				}
				break;
			case 3:{if (editData) fullfree(editData, editmtxsize[0]);
                                if (getData) fullfree(getData, mtxsize[0]);
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
				flag=1;
				break;
			default:
				printf("Something went wrong, try again\n");
				break;
			}
		}
	//free();
	return NULL;
}
