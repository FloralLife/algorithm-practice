#include <iostream>
using namespace std;

int d[1001][1001];

int main() {
	int N, K;
	cin >> N >> K;
	d[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) d[i][j] = d[i - 1][j];
			else if (j == i) d[i][j] = d[i - 1][j - 1];
			else d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007;
		}
	}
	cout << d[N][K];
}