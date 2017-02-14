#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+1;

int main() {
	int N;
	cin >> N;

	bool chk[MAXN];
	memset(chk, 0, sizeof(chk));
	int res = 0;
	for (int i = 2; i <= N; i++) {
		if (chk[i] == false) {
			res++;
			for (int j = 2; i * j <= N; j++) {
				chk[i*j] = true;
			}
		}
	}
	cout << res << endl;
	return 0;
}
/*
11

=> 5

1000000

=> 78498
*/