#include <stdlib.h>
#include <string.h>

#include "sort.h"

//计数排序
//假设所有输入元素都是0～k范围内的整数
//时间复杂度O(n+k)
//需要(n+k+1)*sizeof(int)的额外空间
void counting_sort(int *a, int n, int k)
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

	for(i=0; i<n; i++){
		c[a[i]]++;
	}
	
	for(i=1; i<k+1; i++){
		c[i] += c[i-1];
	}
	
	//	为了保持稳定性：具有相同值的元素在输出数组中的相对次序与它们在输入数组中
	//的相对次序相同。应当从后往前遍历。
	for(i=n-1; i>=0; i--){
		b[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}
	memcpy(a,b,n*sizeof(int));
	free(b);
	free(c);
	return;
}
