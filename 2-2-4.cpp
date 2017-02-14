#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, L;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> q;
	while (N--) {
		cin >> L;
		q.push(L);
	}
	int cost = 0;
	while (q.size() > 1) {
		int d1 = q.top(); q.pop();
		int d2 = q.top(); q.pop();
		cost += d1 + d2;
		q.push(d1 + d2);
	}
	cout << cost << endl;
	return 0;
}
/*
3
8 5 8

=> 34
*/
