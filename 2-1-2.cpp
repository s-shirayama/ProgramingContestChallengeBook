#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MAXM = 100;
int N, M, m[MAXN][MAXM];

bool dfs(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= M || m[i][j] != 1) return false;
	m[i][j] = 2;
	for (int k = 0; k < 9; k++) {
		int dx = k%3 - 1, dy = k/3 - 1;
		dfs(i+dx, j+dy);
	}
	return true;
}

int main() {
	string S;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> S;
		for (int j = 0; j < M; j++) {
			m[i][j] = (S[j] == '.') ? 0 : 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dfs(i, j)) cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}
/*
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

=>3

*/