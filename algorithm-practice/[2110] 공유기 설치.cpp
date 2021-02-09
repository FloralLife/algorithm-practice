#include <iostream>
#include <algorithm>
using namespace std;

int N, C, X[200000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int left = 0, right = 0, answer;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		right = right > X[i] ? right : X[i];
	}

	sort(X, X + N);


	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1, exX = X[0];
		for (int i = 1; i < N; i++) {
			if (X[i] - exX >= mid) {
				cnt++;
				exX = X[i];
			}
		}
		if (cnt >= C) {
			left = mid + 1;
			answer = mid;
		}
		else right = mid - 1;
	}
	cout << answer;
	return 0;
}