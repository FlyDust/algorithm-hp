#ifndef DIVIDE_AND_CONQUER_H
#define DIVIDE_AND_CONQUER_H

typedef struct max_subarray_struct {
	int low;
	int high;
	int value;
} max_subarray;
max_subarray* find_maximum_subarray(int *a, int low, int high);


#endif
