#include <bits/stdc++.h>
using namespace std;


class UF {
private:
	vector<int> par, rank;

public:
	UF(int n) {
		par.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	}
	
	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y]) {
			par[x] = y;
		} else {
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
	
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

int main() {
	int N, K;
	cin >> N >> K;
	// X: x, Y: x+N, X:x+2N
	UF uf(N*3);
	int ans = 0;
	for (int i = 0; i < K; i++) {
		int TYPE, X, Y;
		cin >> TYPE >> X >> Y;
		X--, Y--;
		if (X < 0 || X >= N || Y < 0 || Y >= N) {
			ans++;
			continue;
		}
		if (TYPE == 1) {
			if (uf.same(X, Y+N) || uf.same(X, Y+N*2)) {
				ans++;
				continue;
			}
			uf.unite(X, Y);
			uf.unite(X+N, Y+N);
			uf.unite(X+N*2, Y+N*2);
		} else {
			if (uf.same(X, Y) || uf.same(X, Y+N*2)) {
				ans++;
				continue;
			}
			uf.unite(X, Y+N);
			uf.unite(X+N, Y+N*2);
			uf.unite(X+N*2, Y);
		}
	}
	cout << ans << endl;
	return 0;
}

/*
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5

=> 3
*/
