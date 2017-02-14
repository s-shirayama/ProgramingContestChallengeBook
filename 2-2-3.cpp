#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int MAXX = 1000;
int main() {
	int N, R, X[MAXN];
	cin >> N >> R;
	for (int i = 0; i < N; i++) cin >> X[i];
	int cnt = 0;
	int i = 0;
	while (i < N) {
		int l = X[i++];
		cnt++;
		while (X[i] <= l + R && i < N) i++;
		int c = X[i-1];
		while (X[i] <= c + R && i < N) i++;
	}
	cout << cnt << endl;
	return 0;	
}

/*
6 10
1 7 15 20 30 50

=> 3
*/
