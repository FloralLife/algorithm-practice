#include <iostream>
using namespace std;

int main() {
	int T, N;
	long long ans, cnt[5];
	cin >> T;
	while (T--) {
		cin >> N;
		cnt[0] = 1;
		cnt[1] = 1;
		cnt[2] = 1;
		cnt[3] = 2;
		cnt[4] = 2;

		ans = cnt[N - 1];

		for (int i = 6; i <= N; i++) {
			ans = cnt[0] + cnt[4];
			cnt[0] = cnt[1];
			cnt[1] = cnt[2];
			cnt[2] = cnt[3];
			cnt[3] = cnt[4];
			cnt[4] = ans;
		}
		cout << ans << '\n';
	}
}