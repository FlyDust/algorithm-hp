#ifndef SORT_H
#define SORT_H

//插入排序O(n^2)
void insertion_sort(int *a, int n);

//归并排序O(nlgn)(非原址排序)
void merge_sort(int *a, int low, int high);

//堆排序O(nlgn)
void heap_sort(int *a, int n);

//快速排序O(n^2)~O(nlgn)
void quick_sort(int *a, int low, int high);
void randomized_quick_sort(int *a, int low, int high);	//随机化
void tail_recursive_quick_sort(int *a, int low, int high);	//尾递归

//计数排序O(n+k)
void counting_sort(int *a, int n, int k);

//基数排序O(d(n+k))
void radix_sort(int *a, int n, int d);

//选择问题O(n),返回a中第i小的元素
int randomized_select(int *a, int low, int high, int i);

#endif
