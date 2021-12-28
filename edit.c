#include "chooser.h"
#include "enter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int **AddLine(int **getData,int *mtxsize,int **editData,int *editmtxsize){
	editmtxsize [0] = mtxsize[0]+1;
	//mtxsize[0]+=2;
	//editmtxsize[1] = mtxsize[1];
	editData = create(editmtxsize[0], editmtxsize[1]);
	printf("---------->>>>>%d\n", mtxsize[0]);
	printf("%d\n%d\n",editmtxsize[0], editmtxsize[1]);
	printf("Enter index to add line: ");
	int index = chooser(editmtxsize[0]);

	for (int i=0; i<index; ++i){
		memcpy(editData[i], getData[i], editmtxsize[1]);
	}
	printf("\n");

	for (int j=0; j<editmtxsize[1]; ++j){
		printf("Enter [%d][%d] element\n",index,j);
		editData[index][j] = Silentchooser();
	}

	for (int k=index; k<mtxsize[0];++k){
		memcpy(editData[k], getData[k+1], editmtxsize[1]);
	}

	return editData;
}

int **AddColumn(int **getData, int *mtxsize, int **editData, int *editmtxsize);
int **DeleteLine(int **getData, int *mtxsize, int **editData, int *editmtxsize);
int **DeleteColumn(int **getData, int *mtxsize, int **editData, int *editmtxsize);

int min(const int *arr){
	int size = sizeof(arr)/sizeof(arr[0]);
	int mnm = arr[0];
	for(int i = 0; i<size; i++){
		if (arr[i]<mnm) mnm=arr[i];
	}
	return mnm;
}


int comp(const void *p1, const void *p2){
	int **ptr1 = (int **)p1;
	int **ptr2 = (int **)p2;
	return min(*ptr1)-min(*ptr2);
}


void sort (int **getData, int *mtxsize){
	qsort(getData, mtxsize[0], sizeof(int), comp);
}





int **edit(int **getData, int *mtxsize, int **editData, int *editmtxsize){
	int flag = 0;
	const char choose[] = "------------------------------------------\n1. Add line by index\n2. Add column by index\n3. Delete line by index\n4. Delete column by index\n5. Sort by minimal element\n6. Back\n------------------------------------------\n";
	while(!flag){
		printf("%s\n", choose);
		int res = chooser(6);
		switch(res){
			case 1:
				{
				editData = AddLine(getData, mtxsize, editData, editmtxsize);
				return editData;
				}
				break;
			case 2:
				//AddColumn(getData, mtxsize, editData, editmtxsize);
				break;
			case 3:
				//DeleteLine(getData, mtxsize, editData, editmtxsize);
				break;
			case 4:
				//DeleteColumn(getData, mtxsize, editData, editmtxsize);
				break;
			case 5:
				sort(getData, mtxsize);
				break;
			case 6:
				flag=1;
				break;
			default:
				printf("Something went wrong, try again\n");
				break;
		}

	}
	return NULL;
}


