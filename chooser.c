#include <stdio.h>
#include "check.h"
int chooser(int qty){
	int res = 0, iferr = 0;
	iferr = scanf("%d", &res);
	if(iferr!=1 || qty<1 || res>qty){
		res = check(qty);
	}
	return res;
}

int Silentchooser(){
	int res=0, iferr=0;
	iferr = scanf("%d", &res);
	if(iferr!=1){
		res = Silentcheck();
	}
	return res;
}

