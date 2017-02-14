#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20000;

int main() {
	int N, L;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < N; i++) {
		cin >> L;
		q.push(L);
	}
	long long res = 0;
	while(q.size() > 1) {
		int l1 = q.top(); q.pop();
		int l2 = q.top(); q.pop();
		res += l1 + l2;
		q.push(l1 + l2);
	}
	cout << res << endl;
	return 0;
}

/*
3
8 5 8

=> 34

*/