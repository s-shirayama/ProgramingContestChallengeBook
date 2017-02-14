#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000;

int main() {
	int N;
	string S;
	cin >> N >> S;
	string T(S);
	reverse(T.begin(), T.end());
	int len = S.length(), idxS = 0, idxT = 0;
	for (int i = N; i > 0; i--) {
		bool chk = false;
		for (int j = 0; j < N - idxS - idxT; j++) {
			if (S[idxS+j] > T[idxT+j]) {
				cout << T[idxT++];
				chk = true;
				break;
			} else if (S[idxS+j] < T[idxT+j]) {
				cout << S[idxS++];
				chk = true;
				break;
			}
		}
		if (!chk) cout << S[idxS++];
	}
	cout << endl;
	return 0;
}
/*
6
ACDBCB

=>ABCBCD
*/