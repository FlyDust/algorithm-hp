#include <iostream>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

int gcd(int x, int y) {
	return (x % y == 0) ? y : gcd(y, x%y);
}

int main() {
	int n;
	cin >> n;
	//res = 1*n*(n-1) + n*n; //以1为底，及左右相同
	int res = (1ll * n * (2 * n - 1)) % MOD;
	set<int> s;
	for(int i = 2; i * i <= n; i++) {
		if(s.find(i) == s.end()) continue;
		int tmp = i;
		int cnt = 0;
		while(tmp <= n) {
			s.insert(tmp);
			tmp *= i;
			cnt++;
		}
		for(int j = 1; j <= cnt; j++) {
			for(int k = j+1; k <= cnt; k++) {
				res += (n / (k / gcd(k, j))) % MOD;
			}
		}
	}
	cout << res << endl;
	return 0;
}
