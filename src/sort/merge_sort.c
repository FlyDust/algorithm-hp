#include <stdlib.h>
#include "sort.h"

//归并排序（分治法）
//O(nlgn)
void merge(int *a, int low, int middle, int high)
{
	int *b;
	b = (int*)malloc((high-low+1)*sizeof(int));
	int i;
	int l,h;
	for(i=0,l=low,h=middle+1;i<high-low+1;i++){
		if(l<=middle && h<=high){
			if(a[l]>a[h]){
				b[i] = a[h];
				h++;
			}else{
				b[i] = a[l];
				l++;
			}
		}
		else if(l<=middle){
			b[i] = a[l];
			l++;
		}
		else if(h<=high){
			b[i] = a[h];
			h++;
		}
	}
	for(i=0;i<high-low+1;i++){
		a[i+low] = b[i];
	}
	free(b);
	return;

}

void merge_sort(int *a, int low, int high)
{
	int middle =low + (high-low)/2;
	if(high-low > 0){
		merge_sort(a,low,middle);
		merge_sort(a,middle+1,high);
		merge(a,low,middle,high);
	}
	return;
}
