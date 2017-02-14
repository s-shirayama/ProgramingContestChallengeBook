#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const int MAXN = 100;
const int MAXM = 100;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

int main() {
	int N, M, m[MAXN][MAXM];
	string S;
	cin >> N >> M;
	
	queue<pair<int, PII>> q;
	PII g;

	for (int i = 0; i < N; i++) {
		cin >> S;
		for (int j = 0; j < M; j++) {
			m[i][j] = (S[j] == '#') ? 0 : 1;
			if (S[j] == 'S') q.push(make_pair(1, PII(j, j)));
			if (S[j] == 'G') g = PII(i, j);
		}
	}
	int c = 0;
	while (q.size()) {
		pair<int, PII> p = q.front();
		q.pop();
		c = p.first;
		int x = p.second.first, y = p.second.second;
		if (x == g.first && y == g.second) break;
		if (m[x][y] == 0) continue;
		m[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int _x = x + dx[i], _y = y + dy[i];
			if (_x >= 0 && _x < N && _y >= 0 && _y < M && m[_x][_y] == 1) q.push(make_pair(c+1, PII(_x, _y)));
		}
	}
	cout << c << endl;
	return 0;
}

/*
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#

=>22
*/
