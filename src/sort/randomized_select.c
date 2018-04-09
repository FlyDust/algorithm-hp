#include <stdlib.h>
#include <sys/time.h>
#include "sort.h"

static int partition(int *a, int low, int high)
{
	int i, l = low-1;
	int tmp;
	for(i = low; i < high; i++){
		if(a[i] <= a[high]){
			l++;
			tmp = a[l];
			a[l] = a[i];
			a[i] = tmp;
		}
	}
	l++;
	tmp = a[l];
	a[l] = a[high];
	a[high] = tmp;
	return l;
}

static int randomized_partition(int *a, int low, int high)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	srand((unsigned int)tv.tv_usec);
	int m = low + rand()%(high-low+1);
	int tmp;
	tmp = a[m];
	a[m] = a[high];
	a[high] = tmp;
	return partition(a,low,high);
}

//选择问题，时间复杂度O(n)
//返回数组a中第i小的元素
int randomized_select(int *a, int low, int high, int i)
{
	if(low == high)
		return a[low];
	int middle, k;
	middle = randomized_partition(a, low, high);
	k = middle - low + 1;
	if(i == k)
		return a[middle];
	else if(i < k)
		return randomized_select(a, low, middle-1, i);
	else
		return randomized_select(a, middle+1, high, i-k);
}
