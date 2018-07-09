#include <iostream>
#include <vector>
using namespace std;
struct MaxHeap {
	vector<int> a;
	int length;
	int heap_size;
	MaxHeap(const vector<int>& the_a):a(the_a), length(the_a.size()),
		heap_size(the_a.size()) {}
};

inline int left_child(int parent) {
	return 2 * parent + 1;
}
inline int right_child(int parent) {
	return 2 * parent + 2;
}
inline void swap(int& v1, int& v2) {
	int tmp = v1;
	v1 = v2;
	v2 = tmp;
}

void max_heap(MaxHeap& heap, int parent) {
	int largest = parent;
	int l = left_child(parent);
	int r = right_child(parent);
	if(l < heap.heap_size && heap.a[l] > heap.a[largest]) {
		largest = l;
	}
	if(r < heap.heap_size && heap.a[r] > heap.a[largest]) {
		largest = r;
	}
	swap(heap.a[parent], heap.a[largest]);
	if(largest != parent) {
		max_heap(heap, largest);
	}
}

void build_max_heap(MaxHeap& heap) {
	heap.heap_size = heap.length;
	for(int i = heap.length/2-1; i >= 0; i--) {
		max_heap(heap, i);
	}
}

void heap_sort(MaxHeap& heap) {
	build_max_heap(heap);
	for(int i = heap.length-1; i > 0; i--) {
		swap(heap.a[0], heap.a[i]);
		heap.heap_size--;
		max_heap(heap, 0);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	MaxHeap heap(a);
	heap_sort(heap);
	for(int i = 0; i < heap.length; i++) {
		cout << heap.a[i] << " ";
	}
	cout << endl;
	return 0;
}
