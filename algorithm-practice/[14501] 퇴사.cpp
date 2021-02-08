#include <iostream>
#include <algorithm>
using namespace std;

int T[16], P[16], d[16];

int main() {
	int N;
	cin >> N;
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = 1; i <= N; i++) {
		int end = i + T[i] - 1;
		if (end <= N)
			d[end] = max(d[end], d[i - 1] + P[i]);
		d[i] = max(d[i - 1], d[i]);

		if (d[i] > ans)
			ans = d[i];
	}
	cout << ans;
}