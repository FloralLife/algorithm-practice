#include <iostream>
#include <math.h>
#include <memory.h>
using namespace std;

int N, X, ans;
int map[20][20];
bool horvisit[20][20];
bool vervisit[20][20];

int vx[] = { -1,1 };
int vy[] = { 0,0 };
int hx[] = { 0,0 };
int hy[] = { -1,1 };

void horizon() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {

			for (int i = 0; i < 2; i++) {
				bool slope = true;
				for (int d = 1; d <= X; d++) {
					int nx = x + d * hx[i];
					int ny = y + d * hy[i];
					if (nx >= N || nx < 0 || ny < 0 || ny >= N) {
						slope = false;
						break;
					}
					if (map[nx][ny] != map[x][y] - 1 || horvisit[nx][ny]) {
						slope = false;
						break;
					}
				}
				if (slope) {
					for (int d = 1; d <= X; d++)
						horvisit[x + d * hx[i]][y + d * hy[i]] = true;

				}
			}
		}
	}
}
void vertical() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {

			for (int i = 0; i < 2; i++) {
				bool slope = true;
				for (int d = 1; d <= X; d++) {
					int nx = x + d * vx[i];
					int ny = y + d * vy[i];
					if (nx >= N || nx < 0 || ny < 0 || ny >= N) {
						slope = false;
						break;
					}
					if (map[nx][ny] != map[x][y] - 1 || vervisit[nx][ny]) {
						slope = false;
						break;
					}
				}
				if (slope) {
					for (int d = 1; d <= X; d++) {
						vervisit[x + d * vx[i]][y + d * vy[i]] = true;
					}
				}
			}
		}
	}
}

int check() {
	vertical();
	horizon();
	bool airstrip = true;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		airstrip = true;
		for (int j = 1; j < N; j++) {
			int h = map[i][j - 1] - map[i][j];
			if (abs(h) > 1) {
				airstrip = false;
				break;
			}
			else if ((h == 1 && !horvisit[i][j]) || (h == -1 && !horvisit[i][j - 1])) {
				airstrip = false;
				break;
			}
			else if (h == 1 && horvisit[i][j] && j + X < N && map[i][j + X] == map[i][j - 1]) {
				airstrip = false;
				break;
			}
			else if (h == -1 && horvisit[i][j - 1] && j - X - 1 >= 0 && map[i][j - X - 1] == map[i][j]) {
				airstrip = false;
				break;
			}

		}
		if (airstrip)
			cnt++;


	}
	for (int i = 0; i < N; i++) {
		airstrip = true;
		for (int j = 1; j < N; j++) {
			int v = map[j - 1][i] - map[j][i];
			if (abs(v) > 1) {
				airstrip = false;
				break;
			}
			else if ((v == 1 && !vervisit[j][i]) || (v == -1 && !vervisit[j - 1][i])) {
				airstrip = false;
				break;
			}
			else if (v == 1 && vervisit[j][i] && j + X < N && map[j + X][i] == map[j - 1][i]) {
				airstrip = false;
				break;
			}
			else if (v == -1 && vervisit[j - 1][i] && j - X - 1 >= 0 && map[j - X - 1][i] == map[j][i]) {
				airstrip = false;
				break;
			}

		}
		if (airstrip)
			cnt++;
	}
	return cnt;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(vervisit, false, sizeof(vervisit));
		memset(horvisit, false, sizeof(horvisit));
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		cout << '#' << t << ' ' << check() << endl;
	}
}