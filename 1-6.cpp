#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2;
int main() {
	int N, a;
	vector<int> A;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end(), greater<int>());
	int res = 0;
	for (int i = 0; i < N - 2; i++) {
		if (A[i] < A[i+1] + A[i+2]) {
			res = A[i] + A[i+1] + A[i+2];
			break;
		}
	}
	cout << res << endl;
	return 0;
}

/*
5
2 3 4 5 10

4
4 5 10 20
*/
