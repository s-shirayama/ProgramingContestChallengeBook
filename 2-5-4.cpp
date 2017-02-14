#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

struct E {int to, co;};
const int MAXN = 100;
const int INF = 1e6;

int main() {
	int N, M, A, B, C, dp1[MAXN], dp2[MAXN];
	vector<E> G[MAXN];
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		A--, B--;
		G[A].push_back(E{B, C});
		G[B].push_back(E{A, C});
	}
	for (int i = 0; i < N; i++) dp1[i] = dp2[i] = INF;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(P(0, 0));
	while(q.size()) {
		int c = q.top().first, d = q.top().second;
		q.pop();
		if (c < dp1[d]) {
			dp2[d] = dp1[d];
			dp1[d] = c;
		} else if (c < dp2[d]) {
			dp2[d] = c;
		} else {
			continue;
		}
		for (E e : G[d]) {
			q.push(P(c+e.co, e.to));
		}
	}
	cout << dp1[N-1] << " " << dp2[N-1] << endl;
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
