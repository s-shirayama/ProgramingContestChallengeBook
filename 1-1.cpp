#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50;

int main() {
	int N, M, k;
	vector<int> K;
//	cin >> N >> M;
N = 1000, M = 1000;
	for (int i = 0; i < N; ++i) {
//		cin >> k;
k = i + 1;
		K.push_back(k);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				int m = M - K[i] - K[j] - K[k];
				vector<int>::iterator l = lower_bound(K.begin(), K.end(), m);
				if (l != K.end() && *l == m) {
					cout << "Yes" << endl;
					return 0;
				}
			}

		}
	}
	cout << "No" << endl;
	return 0;
}

/*
3 10
1 3 5

3 9
1 3 5
*/
