#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long f1, f2, ans;
	f1 = 0;
	f2 = 1;
	ans = 1;
	for (int i = 2; i <= n; i++) {
		ans = (f1 + f2)% 1000000000000000000;
		f1 = f2;
		f2 = ans;
	}
	cout << ans;
	return 0;
} 