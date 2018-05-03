#include <stdio.h>
#include <stdlib.h>
#include "dp.h"
#define MAX(x,y) x > y ? x : y

//O(2^n)
double cut_rod(double p[], int n)
{
	if(n == 0){
		return 0;
	}
	int q = -1;
	int i;
	for(i = 0; i < (n>10?10:n) ; i++){
		q = MAX(q, p[i] + cut_rod(p, n-i-1));
	}
	return q;
}

//O(n^2)
double bottom_up_cut_rod(double p[], int n)
{
	double *r;
	r = (double*)malloc(n * sizeof(double));
	r[0] = p[0];
	int i, j;
	int q;
	for(i = 1; i < n; i++){
		q = i>10?-1:p[i];
		for(j = 0; j < (i>10?10:i); j++){
			q = MAX(q, r[j] + r[i-j-1]);
		}
		r[i] = q;
	}
	free(r);
	return q;
}
