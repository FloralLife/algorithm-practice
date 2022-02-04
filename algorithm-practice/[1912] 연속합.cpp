#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int N[100001], max, sum;
	for (int i = 1; i <= n; i++) {
		cin >> N[i];
	}
	max = N[1];
	sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += N[i];
		max = max < sum ? sum : max;
		if (sum < 0)
			sum = 0;
	}
	cout << max;
}