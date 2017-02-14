#include <bits/stdc++.h>
using namespace std;
struct E {int fr, to, co;};

const int MAXN = 1e3;
const int INF = 1e9;

int main() {
	int N, ML, MD;
	cin >> N >> ML >> MD;

	vector<E> G1, G2;
	int A, B, C;
	for (int i = 0; i < ML; i++) {
		cin >> A >> B >> C;
		G1.push_back(E{--A, --B, C});
	}
	for (int i = 0; i < MD; i++) {
		cin >> A >> B >> C;
		G2.push_back(E{--A, --B, C});
	}
	int d[MAXN];
	fill(d, d+N, INF);
	d[0] = 0;
	for (int i = 0; i < N; i++) {
		// d[i] <= d[i+1] + 0
		for (int j = 0; j < N - 1; j++) if (d[j+1] < INF) d[j] = min(d[j], d[j+1]);
		// d[e.to] <= d[e.fr] + e.co
		for (E e : G1) if (e.fr < INF) d[e.to] = min(d[e.to], d[e.fr] + e.co);
		// d[e.fr] <= d[e.to] - e.co;
		for (E e : G2) if (e.to < INF) d[e.fr] = min(d[e.fr], d[e.to] - e.co);
	}
	int res = d[N-1];
	if (d[0] < 0) res = -1;
	else if (res == INF) res = -2;
	cout << res << endl;
	return 0;
}

/*
4 2 1
1 3 10
2 4 20
2 3 3

=> 27

*/