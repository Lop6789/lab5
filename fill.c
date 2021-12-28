#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "enter.h"
#include "chooser.h"
int **fillkey(int **mtx, int m, int n){
		for (int i = 0; i<m; ++i){
			for (int j=0; j<n; ++j){
				printf("Enter a[%d][%d]element\n", i,j);
				mtx[i][j]=Silentchooser();
			}
		}
	return mtx;
}

int **fillrand(int **mtx, int m, int n){
	for(int i = 0; i<m; ++i){
		for(int j=0; j<n; ++j){
			mtx[i][j] = rand()%1000000;
		}

	}

	return mtx;
}

int **fillfile(char *name, int *mtxsize){
	FILE *fd;
	fd = fopen(name, "rb");
	fread(mtxsize, sizeof(int), 2, fd);

	int **mtx = create(mtxsize[0], mtxsize[1]);

	for(int i = 0; i<mtxsize[0]; ++i){
		fread(mtx[i], sizeof(int), mtxsize[1], fd);
	}

	fclose(fd);
	return mtx;
}
