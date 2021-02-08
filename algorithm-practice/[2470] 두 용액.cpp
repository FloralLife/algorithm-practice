#include <iostream>
#include <algorithm>
using namespace std;

int N, value[100000], answer;
int minsum = 2111111111;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> value[i];
	}
	sort(value, value + N);

	int i = 0, j = N - 1;
	pair<int, int> minpair;
	while (i != j) {
		int small = value[i], big = value[j];
		int sum = abs(big + small);
		if (sum < minsum) {
			minpair = { value[i], value[j] };
			minsum = sum;
		}

		int left = abs(small), right = abs(big);
		if (left > right) i++;
		else if (left < right) j--;
		else if (left == right) {
			if (value[i] == -value[j]) {
				minpair = { value[i], value[j] };
				break;
			}
		}
	}
	cout << minpair.first << " " << minpair.second;
}