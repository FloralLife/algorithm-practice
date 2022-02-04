#include <iostream>
#include <map>

using namespace std;

int R, C, answer;
char board[20][20];
bool visit[20][20];
map<char, bool> havebeen;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void find(int x, int y, int cnt) {
	answer = cnt > answer ? cnt : answer;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
		if (visit[nx][ny] || havebeen[board[nx][ny]]) continue;
		visit[nx][ny] = havebeen[board[nx][ny]] = true;
		find(nx, ny, cnt + 1);
		visit[nx][ny] = havebeen[board[nx][ny]] = false;
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		scanf("%s", board[i]);
	}
	visit[0][0] = havebeen[board[0][0]] = true;
	find(0, 0, 1);
	cout << answer;
}