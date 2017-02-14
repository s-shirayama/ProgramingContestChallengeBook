#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXM = 1001;

int main() {
	int N, M;
	string S1, S2;
	cin >> N >> M >> S1 >> S2;

	int dp[MAXN][MAXM];
	dp[0][0] = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
			if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if (i > 0 && j > 0 && S1[i] == S2[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
		}
	}
	cout << dp[N][M] << endl;
	return 0;
}
/*
4 4
abcd
becd

=> 3

6 6
aafbcd
abcfcc

=> 3
*/