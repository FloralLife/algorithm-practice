#include <iostream>
#include <queue>
using namespace std;

bool visit[2][1000][1000];
int map[1000][1000];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct record {
	int x, y, w, l;
};

int main() {
	int N, M, answer = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	queue<record> you;
	you.push({ 0, 0, 0, 1 });
	visit[0][0][0] = visit[1][0][0] = true;
	while (!you.empty() && answer == -1) {
		int x = you.front().x, y = you.front().y, w = you.front().w, l = you.front().l;
		if (x == N - 1 && y == M - 1) {
			answer = l;
			break;
		}
		you.pop();
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d], nw = w;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (w == 0) {
				if (map[nx][ny] == 1)
					nw = 1;
			}
			else if (w == 1) {
				if (map[nx][ny] == 1)
					continue;
			}
			if (visit[nw][nx][ny]) continue;
			visit[nw][nx][ny] = true;
			you.push({ nx, ny, nw, l + 1 });

		}
	}
	cout << answer;
}