#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int N, answer, area[100][100];
bool safe[100][100];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int x, int y, int high) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	safe[x][y] = true;
	while (!q.empty()) {
		x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (safe[nx][ny] || area[nx][ny] <= high) continue;
			q.push({ nx, ny });
			safe[nx][ny] = true;
		}
	}
}

int safetyArea(int high) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!safe[i][j] && area[i][j] > high) {
				bfs(i, j, high);
				cnt++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (safe[i][j]) safe[i][j] = false;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int highest = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];
			highest = highest < area[i][j] ? area[i][j] : highest;
		}
	}
	for (int h = 0; h < highest; h++) {
		answer = max(safetyArea(h), answer);
	}
	cout << answer;
}