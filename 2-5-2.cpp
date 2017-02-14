#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;

const int MAXN = 10;
const int INF = 1e6;

int main() {
	int N, M, A, B, C, dp[MAXN], nxt[MAXN];
	vector<P> G[MAXN];
	cin >> N >> M;
	for (int i = 0; i < N; i++) dp[i] = INF, nxt[i] = -1;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		G[A].push_back(P(C, B));
		G[B].push_back(P(C, A));
	}
	priority_queue<PP, vector<PP>, greater<PP>> q;
	q.push(PP(0,P(0, -1)));
	while(q.size()) {
		PP pp = q.top();
		int c = pp.first, d = pp.second.first, pre = pp.second.second;
		q.pop();
		if (c >= dp[d]) continue;
		dp[d] = c;
		if (pre > -1) nxt[pre] = d;
		for (P p : G[d]) {
			q.push(PP(c + p.first, P(p.second, d)));
		}
	}
	cout << dp[N-1] << endl;
	for (int i = 0; i < N && nxt[i] != -1; i = nxt[i]) {
		cout << i << "->";
	}
	cout << N-1 << endl;
	return 0;
}

/*
7 9
0 1 2
0 2 5
1 3 6
2 3 2
1 4 10
3 5 1
4 5 3
4 6 5
5 6 9

=> 16
=> 0->2->3->5->4->6

*/