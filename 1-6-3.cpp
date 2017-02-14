#include <bits/stdc++.h>
using namespace std;

int K[5] = {3,5,7,4,8};

bool binary_search(int n) {
	int l = 0, r = 4;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (K[m] < n) l = m;
		else r = m;
	}
	return (K[r] == n);
}

int main() {
	sort(K, K+5);
	cout << binary_search(1) << " " << binary_search(5) << endl;
	return 0;
}