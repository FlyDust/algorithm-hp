#ifndef SORT_H
#define SORT_H

//插入排序O(n^2)
void insertion_sort(int *a, int length);

//归并排序O(nlgn)(非原址排序)
void merge_sort(int *a, int low, int high);

//堆排序O(nlgn)
void heap_sort(int *a, int length);

//快速排序O(n^2)~O(nlgn)
void quick_sort(int *a, int low, int high);
void randomized_quick_sort(int *a, int low, int high);	//随机化
void tail_recursive_quick_sort(int *a, int low, int high);	//尾递归

#endif
