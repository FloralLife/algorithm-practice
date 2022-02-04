#include <iostream>
#include <stdlib.h>
using namespace std;

bool visit[15];
int queen[15];
int N, ans;

void locate(int n) {
	if (n == N) {
		ans++;
	}

	else {
		for (int i = 0; i < N; i++) {
			bool check = true;
			if (!visit[i]) {
				visit[i] = true;
				queen[n] = i;
				for (int j = 0; j < n; j++) {
					if (abs(queen[j] - queen[n]) == abs(j - n)) {
						check = false;
						break;
					}
				}
				if (check)
					locate(n + 1);
				visit[i] = false;
			}
		}
	}
}

int main() {
	cin >> N;
	locate(0);
	cout << ans;

	return 0;
}