#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXM = 1001;

int dp[MAXM][MAXN];

int main() {
	int N, M, MOD;
	cin >> N >> M >> MOD;
	dp[0][0] = 1;
	for (int n = 0; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			dp[m][n] = dp[m-1][n] + ((n >= m)?dp[m][n-m]:0);
		}
	}
	cout << dp[M][N] << endl;
	return 0;	
}

/*
4 3 10000

=>4
*/