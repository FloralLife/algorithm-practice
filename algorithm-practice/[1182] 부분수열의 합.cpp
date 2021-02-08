#include <iostream>
using namespace std;

int N, S, num[20], answer;

void find(int n, int sum) {
	if (sum == S && n) answer++;
	for (int i = n; i < N; i++) {
		find(i + 1, sum + num[i]);
	}
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	find(0, 0);
	cout << answer;
}