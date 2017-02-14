#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

const int MAXNM = 20000;

struct E {int to, co;};

int N, M, R;
bool used[MAXNM];
vector<E> G[MAXNM];
priority_queue<P> q;

int solve(int idx) {
	q.push(P(0, idx));
	int res = 0;
	while (q.size()) {
		int c = q.top().first, d = q.top().second;
		q.pop();
		if (used[d]) continue;
		res += c;
		used[d] = true;
		for (E e : G[d]) q.push(P(e.co, e.to));
	}
	return res;
}

int main() {
	cin >> N >> M >> R;
	for (int i = 0; i < R; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		B += N;
		G[A].push_back(E{B, C});
		G[B].push_back(E{A, C});
	}
	int res = 10000*(N+M);
	for (int i = 0; i < N+M; i++) res -= solve(i);

	cout << res << endl;
	return 0;
}

/*
5 5 8
4 3 6831
1 3 4583
0 0 6592
0 1 3063
3 3 4975
1 3 2049
4 2 2104
2 2 781

=> 71071

*/