#include <iostream>
using namespace std;

#define mod 1000000000
int d[100][11];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i < 10; i++)
		d[0][i] = 1;
	d[0][10] = 9;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				d[i][j] = d[i - 1][1];
			else if (j == 9)
				d[i][j] = d[i - 1][8];
			else
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % mod;
			d[i][10] += d[i][j];
			d[i][10] %= mod;
		}
	}
	cout << d[N - 1][10];
}