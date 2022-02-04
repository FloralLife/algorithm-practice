#include <iostream>
#include <queue>
using namespace std;

int paper[500][500];
bool been[500][500];
int N, M, answer;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void exception_handling(int x, int y, int cnt) {
	int sum;
	// っ
	if (x - 1 >= 0 && x + 1 < N && y - 1 >= 0 && y < M) {
		sum = cnt + paper[x - 1][y] + paper[x][y - 1] + paper[x + 1][y];
		if (answer < sum) answer = sum;
	}
	// で
	if (x - 1 >= 0 && x < N && y - 1 >= 0 && y + 1 < M) {
		sum = cnt + paper[x - 1][y] + paper[x][y - 1] + paper[x][y + 1];
		if (answer < sum) answer = sum;
	}
	// た
	if (x - 1 >= 0 && x + 1 < N && y >= 0 && y + 1 < M) {
		sum = cnt + paper[x - 1][y] + paper[x][y + 1] + paper[x + 1][y];
		if (answer < sum) answer = sum;
	}
	// ぬ
	if (x >= 0 && x + 1 < N && y - 1 >= 0 && y + 1 < M) {
		sum = cnt + paper[x][y - 1] + paper[x][y + 1] + paper[x + 1][y];
		if (answer < sum) answer = sum;
	}
}

void find_max(int n, int x, int y, int cnt) {
	if (n == 4) {
		if (answer < cnt) answer = cnt;
	}
	else {
		if (n == 1) exception_handling(x, y, cnt);
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (been[nx][ny] == true) continue;
			been[nx][ny] = true;
			find_max(n + 1, nx, ny, cnt + paper[nx][ny]);
			been[nx][ny] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> paper[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			been[i][j] = true;
			find_max(1, i, j, paper[i][j]);
			been[i][j] = false;
		}
	}
	cout << answer;
}