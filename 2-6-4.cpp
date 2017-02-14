#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 1e6+1;

int main() {
	LL A, B;
	cin >> A >> B;
	bool chk[MAXN], chk2[MAXN];
	memset(chk, 0, sizeof(chk));
	memset(chk2, 0, sizeof(chk2));
	for (int i = 2; LL(i) * i < B; i++) {
		if (chk[i] == false) {
			for (int j = i * 2; LL(j) * j < B; j += i) chk[j] = true;
			for (LL j = max((A + i - 1)/i * i, 2LL); j < B; j += i) chk2[j-A] = true;
		}
	}
	int res = 0;
	for (LL i = A; i < B; i++) if (chk2[i-A] == false) res++;
	cout << res << endl;
	return 0;
}

/*
22 37

=> 3

22801763489 22801787297

=> 1000
*/