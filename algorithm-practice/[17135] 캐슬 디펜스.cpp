#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, D, answer;
int map[16][15];
int dx[] = { 0, -1, 0 };
int dy[] = { -1, 0, 1 };

struct location {
	int x, y, d;
};

bool invade(int board[16][15]) {
	bool check = false;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) continue;
			board[i][j] = 0;
			if (i < N - 1) board[i + 1][j] = 1;
			check = true;
		}
	}
	return check;
}

pair<int, int> findTarget(int board[16][15], int archer) {
	queue<location> q;
	q.push({ N, archer, 0 });
	bool visit[16][15] = { 0, };
	visit[N][archer] = true;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, dis = q.front().d;
		q.pop();
		for (int d = 0; d < 3; d++) {
			int nx = x + dx[d], ny = y + dy[d], nd = dis + 1;
			if (nx > N || nx < 0 || ny >= M || ny < 0) continue;
			if (visit[nx][ny] || nd > D) continue;
			if (board[nx][ny] == 1) return { nx, ny };
			visit[nx][ny] = true;
			q.push({ nx, ny, nd });
		}
	}
	return { -1, -1 };
}

int count(int archers[3]) {
	int cnt = 0;
	int board[16][15] = { 0, };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			board[i][j] = map[i][j];
	while (1) 
	{
		vector<pair<int, int>> target;
		for (int i = 0; i < 3; i++) {
			pair<int, int> t = findTarget(board, archers[i]);
			if (t.first == -1) continue;
			target.push_back(t);
		}
		for (int i = 0; i < target.size(); i++)
		{
			int x = target[i].first, y = target[i].second;
			if (board[x][y] == 0) continue;
			board[x][y] = 0;
			cnt++;
		}
		if (!invade(board)) return cnt;
	}
}

void find(int n, int archers[3], int p)
{
	if (n == 3) {
		int cnt = count(archers);
		if (cnt > answer) answer = cnt;
	}
	else {
		for (int i = p + 1; i < M; i++) {
			archers[n] = i;
			find(n + 1, archers, i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	int archers[3];
	find(0, archers, -1);
	cout << answer;
}