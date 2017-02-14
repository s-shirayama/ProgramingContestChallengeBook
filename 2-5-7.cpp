#include <bits/stdc++.h>
using namespace std;
struct E {int fr, to, co;};

const int MAXN = 5*1e3;
const int MAXR = 1e5;
const int INF = 1e9;

int main() {
	int N, R, A, B, C;
	cin >> N >> R;
	vector<E> G;
	for (int i = 0; i < R; i++) {
		cin >> A >> B >> C;
		A--, B--;
		G.push_back(E{A, B, C});
		G.push_back(E{A, B, C});
	}

	int d[MAXN];
	fill(d, d + N, INF);
	d[0] = 0;
	for (int i = 0; i < N; i++) {
		// d[e.to] <= d[e.fr] + e.co
		for (E e : G) {
			if (d[e.fr] < INF) d[e.to] = min(d[e.to], d[e.fr] + e.co);
		}
	}
	cout << d[N-1] << endl;
	return 0;
}

/*
4 4 
1 2 100
2 3 250
2 4 200
3 4 100

=> 450

*/