#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, ans = 0;
	int d[2][3];
	d[0][0] = d[0][1] = d[0][2] = 1;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		d[1][0] = d[0][0] + d[0][1] + d[0][2];
		d[1][1] = d[0][0] + d[0][2];
		d[1][2] = d[0][0] + d[0][1];
		for (int n = 0; n < 3; n++)
			d[0][n] = d[1][n] % 9901;
	}
	for (int i = 0; i < 3; i++) {
		ans += d[0][i];
	}
	cout << ans % 9901;
}