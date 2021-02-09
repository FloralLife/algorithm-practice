#include <iostream>
using namespace std;

int main() {
	int N, ans, cnt[2];
	cin >> N;
	cnt[0] = 1;
	cnt[1] = 1;
	ans = 1;
	for (int i = 2; i <= N; i++) {
		ans = (cnt[0] + cnt[1]) % 15746;
		cnt[0] = cnt[1];
		cnt[1] = ans;
	}
	cout << ans;
}