#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

//以下STL容器list中sort的实现方法，为归并思想

template <typename T>
void stl_list_sort(list<T> &l) {

	//注意此处必须添加typename关键字！！
	typename list<T>::iterator first = l.begin();
	if(first == l.end() || (++first) == l.end()) return;

	list<T> carry;
	list<T> counter[64];
	int fill = 0;
	while(!l.empty()) {
		carry.splice(carry.begin(), l, l.begin());
		int i = 0;
		while(i < fill && !counter[i].empty()) {
			counter[i].merge(carry);
			carry.swap(counter[i++]);
		}
		carry.swap(counter[i]);
		if(i == fill) ++fill;
	}

	for(int i = 1; i < fill; ++i) {
		counter[i].merge(counter[i-1]);
	}
	l.swap(counter[fill-1]);
}

int main() {
	list<int> l {3,6,8,1,3,0,9,98,76};
	auto print = [](int value) {cout << value << " ";};
	for_each(l.begin(), l.end(), print);
	cout << endl;
	stl_list_sort(l);
	for_each(l.begin(), l.end(), print);
	cout << endl;
	return 0;
}
