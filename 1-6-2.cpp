#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int main() {
	int L, N, X;
	cin >> L >> N;
	int _min = 0, _max = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &X);
		_min = max(_min, min(X, L-X));
		_max = max(_max, max(X, L-X));
	}
	cout << _min << " " << _max << endl;
	return 0;
}

/*
10 3
2 6 7

=> 4 8
*/