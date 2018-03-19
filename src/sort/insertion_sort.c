#include "sort.h"

//插入排序，从小到大排序
void insertion_sort(int *a, int length)
{
	int i,j,tmp;
	for(i = 1; i < length; i++){
		tmp = a[i];
		j = i - 1;
		while(a[j] > tmp && j >= 0){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
	return;
}
