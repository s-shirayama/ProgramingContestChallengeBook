#include <bits/stdc++.h>
using namespace std;

// Greatest Common Divisor (Euclidean Algorithm)
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int X1, Y1, X2, Y2;
	cin >> X1 >> Y1 >> X2 >> Y2;
	int x = abs(X2 - X1), y = abs(Y2 - Y1);
/*
	// x >= y
	if (x < y) swap(x, y);
	int res = 0;
	for (int i = 1; i <= sqrt(y); i++) {
		if (y%i == 0) {
			if (x%(y/i) == 0) {
				res = y/i;
				break;
			} else if (x%i == 0) {
				res = i;
			}
		}
	}
*/
	int res = gcd(x, y);
	cout << res-1 << endl;
	return 0;
}

/*
1 11 5 3

=> 3

*/