#include <iostream>
using namespace std;

void print(int dp[3001], int n) {
	for (int i = 0; i <= n; i++) {
		cout << dp[i] << ' ';
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	int dp[3001] = { 0, };
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		dp[i + 1] += dp[i];
		dp[i + 1] %= 1000000007;
		if (i + 2 <= n) {
			dp[i + 2] += dp[i];
			dp[i + 2] %= 1000000007;
		}
		if (i + 4 <= n) {
			dp[i + 4] += dp[i];
			dp[i + 4] %= 1000000007;
		}
		if (i + 6 <= n) {
			dp[i + 6] += dp[i];
			dp[i + 6] %= 1000000007;
		}
		print(dp, n);
	}

	cout << dp[n];
	return 0;
}