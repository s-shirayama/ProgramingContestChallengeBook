#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

struct E {int to, co;};
const int MAXN = 10;

int main() {
	int N, M, A, B, C;
	vector<E> G[MAXN];
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		G[A].push_back(E{B, C});
		G[B].push_back(E{A, C});
	}
	bool used[MAXN];
	memset(used, 0, sizeof(used));
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(P(0, 0));
	int res = 0;
	while (q.size()) {
		int c = q.top().first, d = q.top().second;
		q.pop();
		if (used[d]) continue;
		used[d] = true;
		res += c;
		for (E e : G[d]) {
			q.push(P(e.co, e.to));
		}
	}
	cout << res << endl;
	return 0;
}

/*
7 9
0 1 10
1 2 5
0 3 2
2 3 7
3 4 1
3 5 3
2 5 1
5 6 5
2 6 8
=>17

*/