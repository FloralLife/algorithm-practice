#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int* num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> S;

	num = new int[N];
	for (int i = 0; i < N; i++) cin >> num[i];

	int sum = 0, i = 0, j = 0, answer = 100001;
	while (j < N) {
		sum += num[j++];
		while (sum >= S) {
			answer = min(answer, j - i);
			sum -= num[i++];
		}
	}
	if (answer == 100001) cout << 0;
	else cout << answer;
}