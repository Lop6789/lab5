#include <stdio.h>
#include <stdlib.h>
#include "chooser.h"
#include <readline/readline.h>

void printmtx(int **Data, int *mtxsize){
	for (int i = 0; i<mtxsize[0]; ++i){
		printf("| ");
		for (int j=0; j<mtxsize[1]; ++j){
			printf("%d ", Data[i][j]);
		}
		printf("|\n");
	}
}

void writemtx(int **Data, int *mtxsize, char *name){
	FILE *fd;
	fd = fopen(name, "wb");
	fwrite(mtxsize, sizeof(int), 2, fd);
	for (int i=0; i<mtxsize[0]; ++i){
		fwrite(Data[i], sizeof(int), mtxsize[1], fd);
	}
	fclose(fd);
}

void write(int **getData, int *mtxsize, int **editData, int *editmtxsize){
	int flag=0;
	const char choose[] = "------------------------------------------\n1. Output original matrix\n2. Output edited matrix\n3. Write original matrix to file\n4. Write edited matrix to file\n5. Back\n------------------------------------------\n";
	while(!flag){
		printf("%s\n", choose);
		int res = chooser(5);
		switch(res){
			case 1:
				printmtx(getData, mtxsize);
				break;
			case 2:
				printmtx(editData, editmtxsize);
				break;
			case 3:
				{char *filename = readline("Enter file name: ");
				writemtx(getData, mtxsize, filename);
				}break;
			case 4:
				{char *editfilename = readline("Enter file name :");
				writemtx(editData, editmtxsize, editfilename);
				}
				break;
			case 5:
				flag=1;
				break;
			default:
				printf("Something went wrong, try again\n");
				break;
			}
	}
}
