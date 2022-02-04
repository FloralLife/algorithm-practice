#include <iostream>
#include <math.h>
using namespace std;


/*
		|
	1	|	2
 天天天(n,n)天天天
	3	|	4
		|
*/
int whereis(int n, int& r, int& c) {
	if (r < n && c < n) return 1;
	else if (r < n && c >= n) {
		c -= n;
		return 2;
	}
	else if (r >= n && c < n) {
		r -= n;
		return 3;
	}
	else if (r >= n && c >= n) {
		r -= n, c -= n;
		return 4;
	}
}

int main() {
	int N, r, c;
	cin >> N >> r >> c;
	int n = pow(2, N - 1);
	int ans = 0;
	while (n) {
		switch (whereis(n, r, c)) {
		case 4:
			ans += n * n;
		case 3:
			ans += n * n;
		case 2:
			ans += n * n;
		}
		n /= 2;
	}
	cout << ans;
}