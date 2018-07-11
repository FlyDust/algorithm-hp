#include <iostream>
#include <vector>
#include <string>
using namespace std;

void make_next(const string& ptr, vector<int>& next) {
	if(ptr.empty()) return;
	next[0] = 0;
	int k = 0;
	for(int i = 1; i < ptr.size(); i++) {
		while(k > 0 && ptr[k] != ptr[i]) k = next[k-1];
		if(ptr[k] == ptr[i]) k++;
		next[i] = k;
	}
}

int kmp(const string& str, const string& ptr) {
	//if(str.empty() || ptr.empty()) return 0;
	vector<int> next(ptr.size(), 0);
	make_next(ptr, next);
	int k = 0;
	for(int i = 1; i < str.size(); i++) {
		while(k > 0 && ptr[k] != str[i]) k = next[k-1];
		if(ptr[k] == str[i]) k++;
		if(k == ptr.size()) {
			cout << i-k+1 << endl;
			//return i-k+1;
		}
	}
	return -1;
}

int main() {
	string str = "bacbababadababacambabacaddababacasdsd";
	string ptr = "ababaca";
	kmp(str, ptr);
//	cout << kmp(str, ptr) << endl;
	return 0;
}
