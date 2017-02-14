#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXM = 10001;
const int INF = 1e6;

int main() {
	int N, M, MOD, A, dp[2][MAXM];
	cin >> N >> M >> MOD;
	int idx = 0;
	memset(dp[idx], 0, sizeof(dp[idx]));
	dp[idx][0] = 1;
	for (int i = 0; i < N; i++) {
		cin >> A;
		idx ^= 1;
		memset(dp[idx], 0, sizeof(dp[idx]));
		dp[idx][0] = 1;
		for (int j = 1; j <= M; j++) {
			dp[idx][j] = dp[idx^1][j] + dp[idx][j-1];
			if (j - 1 - A >= 0) dp[idx][j] -= dp[idx^1][j-1-A];
			dp[idx][j] %= MOD;
		}
/*
		for (int j = 0; j <= M; j++) if (dp[idx^1][j] > 0) {
			for (int a = 0; a <= min(A, M-j); a++) {
				dp[idx][j+a] = (dp[idx][j+a]+ dp[idx^1][j]) % MOD;
			}
		}
*/
	}
	cout << dp[idx][M] << endl;
	return 0;

}

/*
3 3 10000
1 2 3

=>6
*/