#include <iostream>
using namespace std;

int N, answer;
int block[20][20];

void copy(int a[][20], int b[][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void merge(int n, int d) {
	switch (d) {
	case 1:
		for (int i = 0; i < N; i++) {
			if (block[i][n] == 0) continue;
			for (int j = i; j < N; j++) {
				if (i == j) continue;
				if (block[j][n] == 0) continue;
				if (block[j][n] == block[i][n]) {
					block[i][n] *= 2;
					block[j][n] = 0;
				}
				break;
			}
		}
		break;
	case 2:
		for (int i = N - 1; i >= 0; i--) {
			if (block[n][i] == 0) continue;
			for (int j = i; j >= 0; j--) {
				if (i == j) continue;
				if (block[n][j] == 0) continue;
				if (block[n][j] == block[n][i]) {
					block[n][i] *= 2;
					block[n][j] = 0;
				}
				break;
			}
		}
		break;
	case 3:
		for (int i = N - 1; i >= 0; i--) {
			if (block[i][n] == 0) continue;
			for (int j = i; j >= 0; j--) {
				if (i == j) continue;
				if (block[j][n] == 0) continue;
				if (block[j][n] == block[i][n]) {
					block[i][n] *= 2;
					block[j][n] = 0;
				}
				break;
			}
		}
		break;
	case 4:
		for (int i = 0; i < N; i++) {
			if (block[n][i] == 0) continue;
			for (int j = i; j < N; j++) {
				if (i == j) continue;
				if (block[n][j] == 0) continue;
				if (block[n][j] == block[n][i]) {
					block[n][i] *= 2;
					block[n][j] = 0;
				}
				break;
			}
		}
		break;
	}

}

void shift(int n, int d) {
	switch (d) {
	case 1:
		for (int i = 0; i < N; i++) {
			if (block[i][n] == 0) continue;
			int j = 0;
			for (j; j < i; j++) {
				if (block[j][n] == 0) break;
			}
			if (j == i) continue;
			block[j][n] = block[i][n];
			block[i][n] = 0;
		}
		break;

	case 2:
		for (int i = N - 1; i >= 0; i--) {
			if (block[n][i] == 0) continue;
			int j = N - 1;
			for (j; j > i; j--) {
				if (block[n][j] == 0) break;
			}
			if (j == i) continue;
			block[n][j] = block[n][i];
			block[n][i] = 0;
		}
		break;
	case 3:
		for (int i = N - 1; i >= 0; i--) {
			if (block[i][n] == 0) continue;
			int j = N - 1;
			for (j; j > i; j--) {
				if (block[j][n] == 0) break;
			}
			if (j == i) continue;
			block[j][n] = block[i][n];
			block[i][n] = 0;
		}
		break;

	case 4:
		for (int i = 0; i < N; i++) {
			if (block[n][i] == 0) continue;
			int j = 0;
			for (j; j < i; j++) {
				if (block[n][j] == 0) break;
			}
			if (j == i) continue;
			block[n][j] = block[n][i];
			block[n][i] = 0;
		}
		break;
	}
}

int maxBlock() {
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			max = max > block[i][j] ? max : block[i][j];
		}
	}
	return max;
}

void find(int cnt) {
	if (cnt == 5) {
		int max = maxBlock();
		answer = max > answer ? max : answer;
	}
	else {
		int _block[20][20];
		copy(block, _block);
		for (int d = 1; d < 5; d++) {
			for (int n = 0; n < N; n++) {
				merge(n, d);
				shift(n, d);
			}
			find(cnt + 1);
			copy(_block, block);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> block[i][j];
		}
	}
	find(0);
	cout << answer;
}