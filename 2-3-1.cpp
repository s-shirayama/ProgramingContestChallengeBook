#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MAXW = 10000;

int main() {
	int N, W, w[MAXN], v[MAXN];
	cin >> N >> W;
	for (int i = 0; i < N; i++) cin >> w[i];
	for (int i = 0; i < N; i++) cin >> v[i];

	int dp[2][MAXW];
	int idx = 0, _idx;
	memset(dp[idx], 0, sizeof(dp[idx]));
	dp[idx][0] = 0;
	for (int i = 0; i < N; i++) {
		_idx = idx;
		idx ^= 1;
		memset(dp[idx], 0, sizeof(dp[idx]));
		for (int j = 0; j <= W; j++) {
			dp[idx][j] = max(dp[idx][j], dp[_idx][j]);
			if (j + w[i] <= W) dp[idx][j + w[i]] = max(dp[idx][j + w[i]], dp[_idx][j] + v[i]);
		}
	}
	cout << dp[idx][W] << endl;
	return 0;
}
/*
4 5
2 1 3 2
3 2 4 2

=> 7
*/