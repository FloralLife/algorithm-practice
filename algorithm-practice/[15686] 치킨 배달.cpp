#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

struct location {
	int x, y;
};

vector<location> chk;
int N, M, ans = 10000000;
int map[50][50];
bool visit[13];

int distance(int x, int y, location chicken[13]) {
	int dis = 10000000;
	for (int c = 0; c < M; c++)
		dis = min(abs(chicken[c].x - x) + abs(chicken[c].y - y), dis);
	return dis;

}

void choice(int n, int f, location c[13]) {
	if (n == M) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					sum += distance(i, j, c);
				}
			}
		}
		ans = min(sum, ans);
		return;
	}
	else {
		location chicken[13] = { 0 };
		for (int i = 0; i < n; i++) {
			chicken[i] = c[i];
		}
		for (int i = f; i < chk.size(); i++) {
			if (!visit[i]) {
				chicken[n] = chk[i];
				visit[i] = true;
				choice(n + 1, i, chicken);
				visit[i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chk.push_back({ i,j });
			}
		}
	}
	location chicken[13] = { 0 };
	choice(0, 0, chicken);
	cout << ans;
}