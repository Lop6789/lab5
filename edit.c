#include "chooser.h"
#include "enter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QuickSort.h"
void fullfree(int **data, int m){
	if(!data || data == NULL) return;
        for (int i = 0; i<m; i++){
                free(data[i]);
        }
        free(data);
}

int  **AddLine(int **getData, int *mtxsize){
	mtxsize[0]+=1;
	int **editData = create(mtxsize[0], mtxsize[1]);

	printf("Enter index to add line: ");
	int index = chooser(mtxsize[0]);

	for (int i=0; i<index; ++i){
		for (int m=0; m<mtxsize[1]; ++m){
			editData[i][m] = getData[i][m];
			}
	}

	for (int j=0; j<mtxsize[1]; ++j){
		printf("Enter [%d][%d] element\n",index,j);
		editData[index][j] = Silentchooser();
		printf("OK %d\n", editData[index][j]);
	}

	for (int k=index; k<mtxsize[0]-1; ++k){
		for (int p=0; p<mtxsize[1]; ++p){
                        editData[k+1][p] = getData[k][p];
                        }
	}
	fullfree(getData, mtxsize[0]-1);
	return editData;
}

int **AddColumn(int **getData, int *mtxsize){
        mtxsize[1]+=1;
        int **editData = create(mtxsize[0], mtxsize[1]);

        printf("Enter index to add column: ");
        int index = chooser(mtxsize[0]);

        for (int i=0; i<index; ++i){
                for (int m=0; m<mtxsize[0]; ++m){
                        editData[m][i] = getData[m][i];
                        }
        }

        for (int j=0; j<mtxsize[0]; ++j){
                printf("Enter [%d][%d] element\n",j, index);
                editData[j][index] = Silentchooser();
                printf("OK %d\n", editData[j][index]);
        }

        for (int k=index; k<mtxsize[1]-1; ++k){
                for (int p=0; p<mtxsize[0]; ++p){
                        editData[p][k+1] = getData[p][k];
                        }
        }
	fullfree(getData, mtxsize[0]);
        return editData;
}

int **DeleteLine(int **getData, int *mtxsize){
        printf("Enter index to delete line: ");
        int index = chooser(mtxsize[0]);
	mtxsize[0]-=1;
	int **editData = create(mtxsize[0], mtxsize[1]);

	for (int i=0; i<index; ++i){
                for (int j=0; j<mtxsize[1]; ++j){
                        editData[i][j] = getData[i][j];
                        }
	}

	for (int k=index+1; k<mtxsize[0]+1; ++k){
		for(int m=0; m<mtxsize[1]; ++m){
			editData[k-1][m] = getData[k][m];
		}
        }
	fullfree(getData, mtxsize[0]+1);
        return editData;

}

int **DeleteColumn(int **getData, int *mtxsize){
        mtxsize[1]-=1;

	int **editData = create(mtxsize[0], mtxsize[1]);

        printf("Enter index to delete line: ");
        int index = chooser(mtxsize[0]);

	for (int i = 0; i<index; i++){
                for (int j=0; j<mtxsize[0]; ++j){
			editData[j][i] = getData[j][i];
		}
        }

        for (int k=index+1; k<mtxsize[1]+1; ++k){
                for (int m=0; m<mtxsize[0]; ++m){
                        editData[m][k-1] = getData[m][k];
                        }
        }
        fullfree(getData, mtxsize[0]);
        return editData;
}
/*
int qty(int *arr){
	int qty=0;
	while(arr) qty++;
	return qty;
}*/

int min(const int *arr, int size){
	printf("ARRSIZE: %d\n", size);
	int mnm = arr[0];
	for(int i = 0; i<size; i++){
		if (arr[i]<mnm) mnm=arr[i];
	}
	return mnm;
}


int comp(const void *p1, const void *p2, int size){
	int **ptr1 = (int **)p1;
	int **ptr2 = (int **)p2;
	return min(*ptr1, size)-min(*ptr2, size);
}

/*
void sort (int **getData, int *mtxsize){
	qsort(getData, mtxsize[0], sizeof(int *), comp);
}
*/
int **edit(int **editData, int *editmtxsize){
	int flag = 0;
	const char choose[] = "------------------------------------------\n1. Add line by index\n2. Add column by index\n3. Delete line by index\n4. Delete column by index\n5. Sort by minimal element\n6. Back\n------------------------------------------\n";
	while(!flag){
		printf("%s\n", choose);
		int res = chooser(6);
		switch(res){
			case 1:
				{
				editData = AddLine(editData, editmtxsize);
				printf("DONE\n");
				return editData;
				}
				break;
			case 2:	{
				editData = AddColumn(editData, editmtxsize);
				return editData;}
				break;
			case 3:{
				editData = DeleteLine(editData, editmtxsize);
				return editData;
				}
				break;
			case 4:{
				editData = DeleteColumn(editData, editmtxsize);
				return editData;
				}
				break;
			case 5: {
				QuickSort(editData, editmtxsize[0], sizeof(int *), editmtxsize[1], comp);
				//printf("CI: %d\n", min(a));
				return editData;
				}
				break;
			case 6:	{
				//flag=1;
				return editData;
				}
				break;
			default:
				printf("Something went wrong, try again\n");
				break;
		}

	}
	return NULL;
}


