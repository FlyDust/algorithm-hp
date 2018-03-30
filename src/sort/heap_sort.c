#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define LEFT(i)	(i<<1)+1
#define RIGHT(i)	(i<<1)+2

static void exchange(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

//O(lgn)
static void max_heapify(int *a, int index, int size)
{
	int left = LEFT(index);
	int right = RIGHT(index);
	int largest = index;
	if(left<size && a[left]>a[index]) {
		largest = left;
	}
	if(right<size && a[right]>a[largest]) {
		largest = right;
	}
	if(largest != index){
		exchange(&a[index], &a[largest]);
		max_heapify(a, largest, size);
	}
	return;
}

//O(n)
static void build_max_heap(int *a, int len)
{
	int i;
	for(i = len/2-1; i>=0; i--){
		max_heapify(a,i,len);
	}
	return;
}

/** 堆排序
  * O(nlgn)
  */
void heap_sort(int *a, int len)
{
	int i;
	build_max_heap(a,len);
	for(i=0; i<len; i++)
		printf("%d ",a[i]);
	printf("\n");
	int size = len;
	for(i=0; i<len-1; i++){
		exchange(&a[0],&a[size-1]);
		size--;
		max_heapify(a,0,size);
	}
	return;
}


