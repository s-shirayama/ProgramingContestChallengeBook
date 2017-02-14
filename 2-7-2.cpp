#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40;

int main() {
	int N, R[MAXN][MAXN];
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> R[i][j];
		}
	}
	int res = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			if (R[j][i] == 1) {
				res += i - j;
				for (int k = j; k < i; k++) {
					swap(R[k], R[k+1]);
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
/*
2
1 0
1 1

=> 0

3
0 0 1
1 0 0
0 1 0

=> 2

4
1 1 1 0
1 1 0 0
1 1 0 0
1 0 0 0

=> 4

*/