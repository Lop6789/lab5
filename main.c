#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "enter.h"
#include "write.h"
#include "edit.h"
#include "chooser.h"

/*void fullfree(int **data, int *mtxsize){
	for (int i = 0; i<mtxsize[0]; i++){
		free(data[i]);
	}
	free(data);
}
*/
int main(){
	srand(time(NULL));
	const char choose[] = "---------------------\n1. Enter data\n2. Output data\n3. Edit data\n4. Quit\n---------------------\n";
	int flag = 0;
	int **getData = NULL;
	int **editData = NULL;
	int mtxsize[2] = {0,0};
	int editmtxsize[2] = {0,0};

	while (!flag){
		printf("%s\n",choose);
		int res = chooser(4);

		switch(res){
			case 1: {//if (getData) fullfree(getData, mtxsize[0]);
				//if (editData) fullfree(editData, editmtxsize[0]);
				getData = enter(getData, mtxsize, editData, editmtxsize);
				editData = cpy(editData, getData, mtxsize);
				editmtxsize[0] = mtxsize[0];
				editmtxsize[1] = mtxsize[1];
				}
				break;
			case 2:
				write(getData, mtxsize, editData, editmtxsize);
				break;
			case 3:
				editData = edit(editData, editmtxsize);
				break;
			case 4:
				flag=1;
				break;
			default:
				printf("Something went wrong, try again\n");
				break;

		}

	}
	if (getData && getData!=NULL) fullfree(getData, mtxsize[0]);
	if (getData && getData!=NULL) fullfree(editData, editmtxsize[0]);
	return 0;
}
