#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int N, K, A[MAXN];

bool func(int idx, int sum) {
	if (sum > K) return false;
	if (idx == N) return (sum == K);
	return func(idx + 1, sum + A[idx]) | func(idx + 1, sum);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	cout << (func(0, 0) ? "Yes" : "No") << endl;
	return 0;
}

/*
4 13
1 2 4 7

=>Yes

4 15
1 2 4 7

=>No
*/