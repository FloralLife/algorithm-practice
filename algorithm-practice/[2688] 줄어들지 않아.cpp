#include <iostream>
using namespace std;

long long d[64][11] = { 0, };

long long dp(int n) {
	if (d[n - 1][10] != 0) return d[n - 1][10];
	for (int i = 0; i < 10; i++) d[0][i] = 1;
	d[0][10] = 10;
	for (int i = 1; i < n; i++) {
		if (d[i][10] != 0) continue;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
			}
			d[i][10] += d[i][j];
		}
	}
	return d[n - 1][10];
}

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << dp(n) << endl;
	}
}