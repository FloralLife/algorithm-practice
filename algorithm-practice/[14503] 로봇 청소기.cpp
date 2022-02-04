#include <iostream>
#include <queue>
using namespace std;

bool visit[50][50];
bool map[50][50];
int N, M;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct vacuum {
	int r, c, d;
};

int clean(int r, int c, int d) {
	visit[r][c] = true;
	int cnt = 1;
	queue<vacuum> robot;
	robot.push({ r,c,d });
	int x, y, i, n = 0;
	while (1) {
		if (!robot.empty()) {
			x = robot.front().r;
			y = robot.front().c;
			i = robot.front().d;
			robot.pop();
			i = (i + 3) % 4;
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!map[nx][ny] && !visit[nx][ny]) {
					visit[nx][ny] = true;
					cnt++;
					robot.push({ nx,ny,i });
					n = 0;
				}
				else {
					if (n < 4) {
						robot.push({ x,y,i });
						n++;
					}
					else
						n = 0;
				}
			}
			i = (i + 1) % 4;
		}
		else {
			i = (i + 2) % 4;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx == -1 || nx == N || ny == -1 || ny == M || map[nx][ny]) {
				return cnt;
			}
			else if (!map[nx][ny]) {
				robot.push({ nx, ny, (i + 2) % 4 }); 
			}
		}
	}
}

int main() {
	cin >> N >> M;
	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cout << clean(r, c, d);
}