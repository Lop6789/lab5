#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap (void *p1, void *p2, size_t size){
	void *temp = malloc(size);
	memcpy (temp, p1, size);
	memcpy (p1, p2, size);
	memcpy (p2, temp, size);
	free(temp);
}


void QuickSort(void *origArr, size_t datasize, size_t size, size_t arrsize,
				int (*compar)(const void *, const void*, int size)){
	if (datasize-1<=0) return;

	int l = 0, r = datasize-1, x = (l+r)/2;
	void *piv = origArr+x*size;

	do{
		while (compar(origArr+l*size, piv, arrsize)<0){
			l++;
		}

		while(compar(origArr+r*size, piv, arrsize)>0){
			r--;
		}

		if (l<=r){
			swap(origArr+l*size, origArr+r*size, size);
			l++;
			r--;
		}
	}while (l<=r);
	if (r>0) QuickSort (origArr, r+1, size, arrsize, compar);
	if (l<datasize) QuickSort (origArr+l*size, datasize-l, size, arrsize, compar);
}
