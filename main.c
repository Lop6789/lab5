#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "enter.h"
#include "write.h"
#include "edit.h"
#include "chooser.h"

void fullfree(int **data, int *mtxsize){
	for (int i = 0; i<mtxsize[0]; i++){
		free(data[i]);
	}
	free(data);
}

int main(){
	srand(time(NULL));
	const char choose[] = "---------------------\n1. Enter data\n2. Write data\n3. Process data\n4. Quit\n---------------------\n";
	int flag = 0;
	int **getData = NULL;
	int **editData = NULL;
	int mtxsize[2] = {0,0};
	int editmtxsize[2] = {0,0};

	while (!flag){
		printf("%s\n",choose);
		int res = chooser(4);
		//int mtxsize[2];
		//int editmtxsize[2];
		//mtxsize[0]=0;
		//mtxsize[1]=0;
		//editmtxsize[0]=0;
		//editmtxsize[1]=0;

		switch(res){
			case 1:
				getData = enter(mtxsize);
				break;
			case 2:
				{//printf("MATRIX HAS YOU\n");
				write(getData, mtxsize, editData, editmtxsize);
				}
				break;
			case 3:
				edit(getData, mtxsize, editData, editmtxsize);
				break;
			case 4:
				flag=1;
				break;
			default:
				printf("Something went wrong, try again\n");
				break;

		}

	}
	fullfree(getData, mtxsize);
	fullfree(editData, editmtxsize);
	return 0;
}
