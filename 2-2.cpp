#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;


int main() {
	int A, C;
	vector<PII> v;
	cin >> A;
	int c[6] = {1,5,10,50,100,500};
	for (int i = 0; i < 6; i++) {
		cin >> C;
		v.push_back(PII(c[i], C));
	}
	sort(v.begin(), v.end(), greater<PII>());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		int _c = v[i].first, _n = v[i].second;
		int _cnt = min(_n, A/_c);
		cnt += _cnt;
		A -= _c * _cnt;
		if (A == 0) break;
	}
	cout << cnt << endl;
	return 0;
}
/*
620
2 3 1 3 0 2

=> 6
*/