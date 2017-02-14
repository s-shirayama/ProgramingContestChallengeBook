#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100;

int memo[MAXN + 1];

int fibo(int n) {
	if (memo[n] > 0) return memo[n];
	if (n < 3) return 1;
	return memo[n] = (fibo(n - 1) + fibo(n - 2)) % MOD;
}

int main() {
	int N;
	cin >> N;
	cout << fibo(N) << endl;
}