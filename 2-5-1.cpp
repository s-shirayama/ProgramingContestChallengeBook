#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int MAXN = 1000;
int C[MAXN];
vector<int> G[MAXN];

bool dfs(int d, int c) {
	if (C[d] > 0) return (C[d] == c);
	C[d] = c;
	for (int s : G[d]) if (!dfs(s, (c==1)?2:1)) return false;
	return true;
}

int main() {
	int N, M, A, B;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		G[A].push_back(B);
		G[B].push_back(A);
	}
	bool res = true;

	// DFS
	for (int i = 0; i < N; i++) if (C[i] == 0 && !dfs(i, 1)) {
		res = false;
		break;
	}

	/*
	// BFS
	queue<P> q;
	q.push(P(1, 0));
	while (q.size()) {
		int c = q.front().first, d = q.front().second;
		q.pop();
		if (C[d] > 0) {
			if (C[d] == c) continue;
			res = false;
			break;
		}
		C[d] = c;
		for (int a : G[d]) q.push(P((c == 1)?2:1, a));
	}
	*/
	cout << (res?"Yes":"No") << endl;
	return 0;
}

/*
3 3
0 1
0 2
1 2

=> No

4 4
0 1
0 3
1 2
2 3

=> Yes

*/
