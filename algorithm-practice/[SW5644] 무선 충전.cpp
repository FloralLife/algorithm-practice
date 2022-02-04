#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int route[2][100], M;

struct battery {
	int n, p;
};
vector<battery> bc[10][10];

struct location {
	int x, y;
};

location A[2];

void area(int x, int y, int c, int p, int o) {
	queue<pair<int, location>> q;
	bool visit[10][10] = { false };
	visit[x][y] = true;
	bc[x][y].push_back({ o,p });
	q.push({ 0,{x,y} });
	while (!q.empty()) {
		int n = q.front().first;
		x = q.front().second.x;
		y = q.front().second.y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 10 && nx >= 0 && ny < 10 && ny >= 0) {
				if (visit[nx][ny])
					continue;
				visit[nx][ny] = true;
				if (n < c) {
					bc[nx][ny].push_back({ o,p });
					q.push({ n + 1, { nx,ny } });
				}
			}
		}
	}
}

int move() {
	int charge = 0;
	for (int i = 0; i <= M; i++) {
		for (int a = 0; a < 2; a++) {
			int d = route[a][i] - 1;
			if (d != -1) {
				A[a].x += dx[d];
				A[a].y += dy[d];
			}
		}
		int Abc = bc[A[0].x][A[0].y].size();
		int Bbc = bc[A[1].x][A[1].y].size();
		int power = 0;
		int temp;
		if (Abc && Bbc) {
			for (int a = 0; a < Abc; a++) {
				for (int b = 0; b < Bbc; b++) {
					temp = 0;
					if (bc[A[0].x][A[0].y][a].n == bc[A[1].x][A[1].y][b].n) {
						temp += bc[A[0].x][A[0].y][a].p;
					}
					else {
						temp += bc[A[0].x][A[0].y][a].p + bc[A[1].x][A[1].y][b].p;
					}
					power = power > temp ? power : temp;
				}
			}
		}
		else if (!Abc) {
			for (int b = 0; b < Bbc; b++) {
				temp = 0;
				temp += bc[A[1].x][A[1].y][b].p;
				power = power > temp ? power : temp;
			}
		}
		else if (!Bbc) {
			for (int a = 0; a < Abc; a++) {
				temp = 0;
				temp += bc[A[0].x][A[0].y][a].p;
				power = power > temp ? power : temp;
			}
		}

		charge += power;
	}
	return charge;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				bc[i][j].clear();

			}
		}
		int a, x, y, c, p;
		cin >> M >> a;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> route[i][j];
			}
		}
		for (int i = 0; i < a; i++) {
			cin >> y >> x >> c >> p;
			area(x - 1, y - 1, c, p, i);
		}
		A[0].x = A[0].y = 0;
		A[1].x = A[1].y = 9;
		cout << '#' << t << ' ' << move() << endl;

	}
}