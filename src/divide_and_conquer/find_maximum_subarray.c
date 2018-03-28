#include <stdio.h>
#include <stdlib.h>
#include "divide_and_conquer.h"

//寻找跨越中点的最大子串
static max_subarray* find_max_crossing_subarray(int *a,int low,int middle,int high)
{
	max_subarray *subarray;
	if((subarray = (max_subarray*) malloc(sizeof(max_subarray))) == NULL){
		return NULL;
	}
	int i;
	int left_sum = 0, right_sum = 0;
	int left_max = 0, right_max = 0;
	for(i=middle; i>=low; i--){
		left_sum += a[i];
		if(left_sum > left_max || i == middle){
			left_max = left_sum;
			subarray->low = i;
		}
	}
	for(i=middle+1; i<=high; i++){
		right_sum += a[i];
		if(right_sum > right_max || i == middle+1){
			right_max = right_sum;
			subarray->high = i;
		}
	}

	subarray->value = left_max + right_max;
	return subarray;
}

/** 分治法求最大连续子数组
  * O(nlgn)
  */

max_subarray* find_maximum_subarray(int *a,int low,int high)
{
	if(low == high){
		max_subarray *subarray = (max_subarray*)malloc(sizeof(max_subarray));
		subarray->low = low;
		subarray->high = low;
		subarray->value = a[low];
		return subarray;
	}
	max_subarray *left_subarray,*right_subarray,*cross_subarray;
	int middle = (low + high) / 2;
	left_subarray = find_maximum_subarray(a,low,middle);
	right_subarray = find_maximum_subarray(a,middle+1,high);
	cross_subarray = find_max_crossing_subarray(a,low,middle,high);
	if(left_subarray->value>=right_subarray->value && left_subarray->value>=cross_subarray->value)
		return left_subarray;
	else if(cross_subarray->value>=left_subarray->value && cross_subarray->value>=right_subarray->value)
		return cross_subarray;
	else
		return right_subarray;
}
