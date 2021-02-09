#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int d[1000][10] = { 0 };
	for (int i = 0; i < 10; i++) {
		d[0][i] = 1;
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				d[i + 1][j] += d[i][k];
				d[i + 1][j] %= 10007;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += d[N - 1][i];
		ans %= 10007;
	}
	cout << ans;
}