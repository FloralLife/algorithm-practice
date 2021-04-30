#include <iostream>
using namespace std;

long long strcnt[31][31];

long long takePill(int whole, int half) {
	if (strcnt[whole][half])
		return strcnt[whole][half];
	if (whole == 0 && half == 1)
		return 1;
	long long cnt = 0;
	if (whole > 0)
		cnt += takePill(whole - 1, half + 1);
	if (half > 0)
		cnt += takePill(whole, half - 1);
	strcnt[whole][half] = cnt;
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	while (1)
	{
		cin >> n;
		if (n == 0) return 0;
		n = takePill(n, 0);
		cout << n << endl;
	}
}