#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int INF = 1e7;

int main() {
	int N, A[MAXN], dp[MAXN];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	int res = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
		res = max(res, dp[i]);
	}
	cout << res << endl;
/*
	int N, A, dp[2][MAXN];
	cin >> N;

	int idx = 0;
	fill(dp[idx], dp[idx] + MAXN, INF);
	dp[idx][0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A;
		idx ^= 1;
		fill(dp[idx], dp[idx] + MAXN, INF);
		dp[idx][0] = 0;
		for (int j = 1; j <= i; j++) {
			dp[idx][j] = dp[idx^1][j];
			if (dp[idx^1][j-1] < A && (dp[idx^1][j] == INF || dp[idx^1][j] > A)) dp[idx][j] = A;
		}
	}
	int res = 0;
	for (int i = 1; i <= N; i++) if (dp[idx][i] < INF) res = i;
	cout << res << endl;
*/
	return 0;
}
/*
5
4 2 3 1 5

=> 3

*/