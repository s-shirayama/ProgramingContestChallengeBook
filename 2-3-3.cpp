#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MAXW = 1000;

int main() {
	int N, W, w[MAXN], v[MAXN];

	cin >> N >> W;
	for (int i = 0; i < N; i++) cin >> w[i];
	for (int i = 0; i < N; i++) cin >> v[i];

	int dp[2][MAXW+1];
	memset(dp[0], 0, sizeof(dp[0]));
	for (int i = 0; i < N; i++) {
		int _idx = i&1;
		int idx = (i+1)&1;
		memset(dp[idx], 0, sizeof(dp[idx]));
		for (int j = 0; j <= W; j++) {
			dp[idx][j] = max(dp[idx][j], dp[_idx][j]);
			if (j + w[i] <= W) {
				dp[idx][j + w[i]] = max(dp[idx][j + w[i]], dp[_idx][j] + v[i]);
				dp[idx][j + w[i]] = max(dp[idx][j + w[i]], dp[idx][j] + v[i]);
			}
		}
	}
	cout << dp[N&1][W] << endl;

	return 0;
}

/*
3 7
3 4 2
4 5 3

=> 10

*/