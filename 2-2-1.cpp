#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const int MAXN = 1e5;

int main() {
	int N, S[MAXN], E[MAXN];
	cin >> N;
	for (int i = 0; i < N; i++) scanf("%d", S+i);
	for (int i = 0; i < N; i++) scanf("%d", E+i);

	PII p[MAXN];
	for (int i = 0; i < N; i++) {
		p[i] = PII(E[i], S[i]);
	}
	sort(p, p+N);
	int idx = 0, res = 0;
	for (int i = 0; i < N; i++) {
		if (p[i].second >= idx) {
			idx = p[i].first;
			res++;
		}
	}
	cout << res << endl;
	return 0;
}

/*
5
1 2 4 6 8
3 5 7 9 10

=> 3
*/