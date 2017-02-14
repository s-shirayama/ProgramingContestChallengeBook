#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MAXK = 1e5;

int main() {
	int N, K, A[MAXN], M[MAXN];
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> M[i];

	bool dp[2][MAXK+1];
	dp[0][0] = true;
	for (int i = 0; i < N; i++) {
		int _idx = i&1, idx = (i+1)&1;
		memset(dp[idx], 0, sizeof(dp[idx]));
		for (int j = 0; j <= K; j++) {
			if (dp[_idx][j]) {
				if (dp[idx][j] == true) continue;
				dp[idx][j] = true;
				int m = M[i];
				for (int k = 1; k <= m && j + k * A[i] <= MAXK; k++) {
					dp[idx][j + k * A[i]] = true;
					if (dp[_idx][j + k * A[i]]) m = k + M[i];
				}
			}
		}
	}
	cout << ((dp[N&1][K]) ? "Yes" : "No") << endl;

	return 0;
}

/*
3 17
3 5 8
3 2 2

=>Yes
*/