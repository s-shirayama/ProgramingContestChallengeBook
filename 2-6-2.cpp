#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	bool res = true;
	for (int i = 2; i <= sqrt(N); i++) {
		if (N%i == 0) {
			res = false;
			break;
		}
	}
	cout << (res?"Yes":"No") << endl;
	return 0;
}

/*

53
=> Yes

295927
=> No
*/
