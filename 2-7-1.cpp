#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;

int main() {
	int N, X[MAXN], Y[MAXN];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i];
	for (int i = 0; i < N; i++) cin >> Y[i];
	sort(X, X+N);
	sort(Y, Y+N, greater<int>());
	long long res = 0;
	for (int i = 0; i < N; i++) {
		res += (LL)X[i] * Y[i];
	}
	cout << res << endl;
	return 0;
}
/*
3
1 3 -5
-2 4 1

=> -25

5
1 2 3 4 5
1 0 1 0 1

=>6
*/