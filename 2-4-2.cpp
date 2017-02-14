#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;

int main() {
	int N, L, P, A[MAXN], B[MAXN];
	cin >> N >> L >> P;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	int p = P, res = 0;
	priority_queue<int> q;
	int i = 0;
	while (i < N && P < L) {
		while (i < N && A[i] <= P) q.push(B[i++]);
		if (q.empty()) {
			res = -1;
			break;
		}
		if (i < N) {
			P += q.top(); q.pop();
			res++;
		}
	}
	cout << res << endl;
	return 0;
}

/*
4 25 10
10 14 20 21
10 5 2 4

=>2

*/
