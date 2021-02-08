#include <iostream>
#include <queue>
using namespace std;

int N;
int board[100][100];
queue<pair<int, char>> dir;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int dummy() {
	queue<pair<int, int>> snake;
	snake.push({ 0,0 });
	pair<int, int> cur = { 0,0 };
	board[0][0] = 1;
	int d = 1;
	int time = 0;
	pair<int, char> di = dir.front();
	dir.pop();
	while (1) {
		if (time == di.first) {
			switch (di.second) {
			case 'L':
				d = (d + 3) % 4;
				break;
			case 'D':
				d = (d + 1) % 4;
				break;
			}
			if (!dir.empty()) {
				di = dir.front();
				dir.pop();
			}
		}
		time++;
		int nx = cur.first + dx[d];
		int ny = cur.second + dy[d];

		if (nx >= N || nx < 0 || ny < 0 || ny >= N)
			return time;
		if (board[nx][ny] == 1)
			return time;
		if (board[nx][ny] != 2) {
			pair<int, int> last = snake.front();
			board[last.first][last.second] = 0;
			snake.pop();
		}
		board[nx][ny] = 1;
		cur = { nx,ny };
		snake.push(cur);
	}
}

int main() {
	int K, L, r, c, X;
	char C;
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		board[r - 1][c - 1] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		dir.push({ X,C });
	}

	cout << dummy();
}