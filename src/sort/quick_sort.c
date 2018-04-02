#include <sys/time.h>
#include <stdlib.h>

#include "sort.h"

static void exchange(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}


static int partition(int *a, int low, int high);
static int randomized_partion(int *a, int low, int high);

//快速排序
//选定A[high]为主元
//最坏时间复杂度O(n^2)
//期望时间复杂度O(nlgn)
void quick_sort(int *a, int low, int high)
{
	int middle;
	if(low < high){
		middle = partition(a,low,high);
		quick_sort(a,low,middle-1);
		quick_sort(a,middle+1,high);
	}
	return;
}

//随机化版本的快速排序
//随机选择元素作为主元
void randomized_quick_sort(int *a, int low, int high)
{
	int middle;
	if(low < high){
		middle = randomized_partion(a,low,high);
		randomized_quick_sort(a,low,middle-1);
		randomized_quick_sort(a,middle+1,high);
	}
	return;
}

//基于尾递归的快速排序
void tail_recursive_quick_sort(int *a, int low, int high)
{
	int middle;
	while(low < high){
		middle = partition(a,low,high);
		tail_recursive_quick_sort(a,low,middle-1);
		low = middle + 1;
	}
	return;
}

static int partition(int *a, int low, int high)
{
	int x = a[high];
	int i;
	int j = low - 1;
	for(i=low; i<high; i++){
		if(a[i] <= x){
			j++;
			exchange(&a[i],&a[j]);
		}
	}
	exchange(&a[j+1],&a[high]);
	return j+1;
}

static int randomized_partion(int *a, int low, int high)
{
	struct timeval tp;
	gettimeofday(&tp,NULL);
	srand((unsigned int)tp.tv_usec);
	int m = rand()%(high-low+1) + low;
	exchange(&a[m],&a[high]);
	return partition(a,low,high);
}
