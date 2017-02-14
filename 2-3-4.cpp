#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2;
const int MAXV = 1e4;
const int MAXW = 1e9;

int main() {
	int N, W, w[MAXN], v[MAXN];
	cin >> N >> W;
	for (int i = 0; i < N; i++) cin >> w[i];
	for (int i = 0; i < N; i++) cin >> v[i];

	int dp[2][MAXV+1];
	fill(dp[0], dp[0] + MAXV + 1, MAXW+1);
	dp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		int _idx = i&1, idx = (i+1)&1;
		fill(dp[idx], dp[idx] + MAXV + 1, MAXW+1);
		for (int j = 0; j <= MAXV; j++) {
			dp[idx][j] = min(dp[idx][j], dp[_idx][j]);
			if (j + v[i] <= MAXV) {
				dp[idx][j + v[i]] = min(dp[idx][j + v[i]], dp[_idx][j] + w[i]);
//				dp[idx][j + v[i]] = min(dp[idx][j + v[i]], dp[idx][j] + w[i]);
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= MAXV; i++) {
		if (dp[N&1][i] <= W) res = i;
	}
	cout << res << endl;

	return 0;
}

/*
4 5
2 1 3 2
3 2 4 2

=> 7
*/
