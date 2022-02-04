#include <iostream>
#include <algorithm>
using namespace std;


int wine[10001], sum[10001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	sum[1] = wine[1];
	sum[2] = wine[1] + wine[2];
	sum[3] = max(wine[1], wine[2]) + wine[3];

	for (int i = 3; i <= n; i++) {
		sum[i] = max(sum[i - 1], max(sum[i - 2] + wine[i], sum[i - 3] + wine[i - 1] + wine[i]));
	}
	cout << sum[n];
}