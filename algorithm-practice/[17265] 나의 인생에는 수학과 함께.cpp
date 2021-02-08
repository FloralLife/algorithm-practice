#include <iostream>
using namespace std;

int block[5][5];
int N, maxres = -10000, minres = 10000;

int dx[] = { 1,0 };
int dy[] = { 0,1 };

int calc(int res, int x, int y, int opr) {
	int num = block[x][y];
	switch (opr) {
	case -5:
		res += num;
		break;
	case -3:
		res -= num;
		break;
	case -6:
		res *= num;
		break;
	}
	return res;
}

void find(int x, int y, int res) {
	if (x == N - 1 && y == N - 1) {
		maxres = maxres > res ? maxres : res;
		minres = minres < res ? minres : res;
	}
	else {
		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
			for (int j = 0; j < 2; j++) {
				int nnx = nx + dx[j], nny = ny + dy[j];
				if (nnx >= N || nnx < 0 || nny >= N || nny < 0) continue;
				find(nnx, nny, calc(res, nnx, nny, block[nx][ny]));
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char input;
			cin >> input;
			block[i][j] = input - '0';
		}
	}

	find(0, 0, block[0][0]);
	cout << maxres << ' ' << minres;
}