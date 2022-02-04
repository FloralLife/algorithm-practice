#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, mx, ans = 0;
	int A[1000], d[1000];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++) {
		d[i] = 1;
		mx = 1;
		for (int j = 0; j < i; j++)
			if (A[j] < A[i])
				mx = max(mx, d[i] + d[j]);
		d[i] = mx;
		ans = max(ans, mx);
	}
	cout << ans;
}