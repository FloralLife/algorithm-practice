#include <iostream>
using namespace std;

int N, S, M;
bool V[101][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int answer = -1;
	cin >> N >> S >> M;
	V[0][S] = true;

	for (int i = 0; i < N; i++) {
		int v;
		cin >> v;
		for (int j = 0; j <= M; j++) {
			if (V[i][j]) {
				if (j - v >= 0) V[i + 1][j - v] = true;
				if (j + v <= M) V[i + 1][j + v] = true;
			}
		}
	}

	for (int i = 0; i <= M; i++) {
		if (V[N][i]) answer = answer > i ? answer : i;
	}
	cout << answer;
}