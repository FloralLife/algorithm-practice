#include <iostream>
#include <bitset>
using namespace std;

bitset<1000001> bit;
int n, answer, a[100000], x;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		bit.set(a[i]);
	}
	cin >> x;
	for (int i = 0; i < n; i++) {
		int num = x - a[i];
		if (num <= 0 || num > 100000) continue;
		if (bit[num]) answer++;
	}
	cout << answer / 2;
}