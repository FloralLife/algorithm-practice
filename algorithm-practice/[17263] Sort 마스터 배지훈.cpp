#include <iostream>
using namespace std;

int main() {
	int N, a, answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		answer = a > answer ? a : answer;
	}
	cout << answer;
}