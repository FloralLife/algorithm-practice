#include <iostream>
using namespace std;

int N, M, A[300][300];

void leftSide(int idx, int& temp) {
	int ttemp = temp;
	temp = A[N - idx - 1][idx];
	for (int i = N - idx - 1; i > idx + 1; i--) {
		A[i][idx] = A[i - 1][idx];
	}
	A[idx + 1][idx] = ttemp;
}

void bottomSide(int idx, int& temp) {
	int ttemp = temp;
	temp = A[N - idx - 1][M - idx - 1];
	for (int i = M - idx - 1; i > idx + 1; i--) {
		A[N - idx - 1][i] = A[N - idx - 1][i - 1];
	}
	A[N - idx - 1][idx + 1] = ttemp;
}

void rightSide(int idx, int& temp) {
	int ttemp = temp;
	temp = A[idx][M - idx - 1];
	for (int i = idx; i < N - idx - 2; i++) {
		A[i][M - idx - 1] = A[i + 1][M - idx - 1];
	}
	A[N - idx - 2][M - idx - 1] = ttemp;
}

void topSide(int idx, int& temp) {
	int ttemp = temp;
	temp = A[idx][idx];
	for (int i = idx; i < M - idx - 2; i++) {
		A[idx][i] = A[idx][i + 1];
	}
	A[idx][M - idx - 2] = ttemp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int R;
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	int size = N < M ? N / 2 : M / 2;

	while (R--) {
		for (int i = 0; i < size; i++) {
			int temp = A[i][i];
			leftSide(i, temp);
			bottomSide(i, temp);
			rightSide(i, temp);
			topSide(i, temp);
		}
	}

	for (int a = 0; a < N; a++) {
		for (int s = 0; s < M; s++) {
			cout << A[a][s] << ' ';
		}
		cout << endl;
	}
}