#include <stdlib.h>
#include <string.h>

#include "sort.h"

//稍加修改的用于基数排序的计数排序
static void radix_counting_sort(int *tmp, int n, int k, int *a)
{
	int *b = NULL, *c = NULL;
	int i;

	if((b = (int*)malloc(n*sizeof(int))) == NULL){
		exit(1);
	}
	if((c = (int*)malloc((k+1)*sizeof(int))) == NULL){
		exit(1);
	}
	memset(c,0,(k+1)*sizeof(int));
	
	for(i = 0; i < n; i++){
		c[tmp[i]]++;
	}
	for(i = 1; i < k+1; i++){
		c[i] += c[i-1];
	}
	for(i = n -1; i >= 0; i--){
		b[c[tmp[i]]-1] = a[i];
		c[tmp[i]]--;
	}
	memcpy(a,b,n*sizeof(int));
	free(b);
	free(c);
	return;
}

//基数排序
//时间复杂度O(d(n+k))
//@n: 输入数组大小
//@d: 数组元素的最高位数
void radix_sort(int *a, int n, int d)
{
	int *tmp;
	int i, j, flag = 1;

	if((tmp = (int*)malloc(n*sizeof(int))) == NULL){
		exit(1);
	}

	for(i = 0; i < d; i++){
		flag *= 10;
		for(j = 0; j < n; j++){
			tmp[j] = (a[j]%flag)/(flag/10);
		}
		radix_counting_sort(tmp,n,9,a);
	}
	free(tmp);
	return;
}
