#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, answer, lab[8][8];
vector<pair<int, int>> virus;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int countSafety() {
	int copy_lab[8][8];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_lab[i][j] = lab[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) q.push(virus[i]);
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (copy_lab[nx][ny] == 0) {
				q.push({ nx, ny });
				copy_lab[nx][ny] = 2;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_lab[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void find(int n) {
	if (n == 3) {
		answer = max(answer, countSafety());
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (lab[i][j] == 0) {
					lab[i][j] = 1;
					find(n + 1);
					lab[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) virus.push_back({ i,j });
		}
	}
	find(0);
	cout << answer;
}