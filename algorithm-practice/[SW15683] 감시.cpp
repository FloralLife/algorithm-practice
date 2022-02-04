#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <memory.h>
using namespace std;

struct camera {
	int x, y;
	int num;
};

int N, M;
bool visit[8][8];
int map[8][8];
vector<camera> cam;
priority_queue<int, vector<int>, greater<int>> pq;

void move(int x, int y, int n) {
	visit[x][y] = true;
	int i = n % 4;
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };
	int nx = x + dx[i];
	int ny = y + dy[i];
	if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
		if (map[nx][ny] != 6)
			move(nx, ny, i);
	}
}

void cctv(int x, int y, int n, int i) {
	switch (n) {
	case 1:
		move(x, y, i);
		break;
	case 2:
		move(x, y, i);
		move(x, y, i + 2);
		break;
	case 3:
		move(x, y, i);
		move(x, y, i + 1);
		break;
	case 4:
		move(x, y, i);
		move(x, y, i + 1);
		move(x, y, i + 2);
		break;
	case 5:
		move(x, y, i);
		move(x, y, i + 1);
		move(x, y, i + 2);
		move(x, y, i + 3);
		break;
	}
}


void check() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!visit[i][j] && map[i][j] != 6)
				cnt++;
	pq.push(cnt);
}
void rotate() {
	for (int i = 0; i < pow(4, cam.size()); i++) {
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < cam.size(); j++) {
			int n = pow(4, j);
			cctv(cam[j].x, cam[j].y, cam[j].num, i / n);
		}
		check();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0 || map[i][j] == 6) continue;
			cam.push_back({ i,j,map[i][j] });
		}
	}
	rotate();
	cout << pq.top();
}
