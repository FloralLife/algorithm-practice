#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int A[50][50];
bool inUnion[50][50];
int N, L, R;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

bool move(int x, int y, bool inUnion[50][50]) {
	bool movement = false;
	int population = A[x][y];
	vector<pair<int, int>> country;
	queue<pair<int, int>> q;
	country.push_back({ x,y });
	q.push({ x, y });
	while (!q.empty()) {
		x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
			if (inUnion[nx][ny]) continue;
			int dif = abs(A[x][y] - A[nx][ny]);
			if (dif >= L && dif <= R) {
				country.push_back({ nx,ny });
				q.push({ nx,ny });
				inUnion[nx][ny] = true;
				population += A[nx][ny];
				movement = true;
			}
		}
	}
	population /= country.size();
	for (int i = 0; i < country.size(); i++) {
		A[country[i].first][country[i].second] = population;
	}
	return movement;
}


int main() {
	cin >> N;
	cin >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	int cnt = 0;
	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				inUnion[i][j] = false;
			}
		}
		bool moved = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!inUnion[i][j]) {
					inUnion[i][j] = true;
					if (move(i, j, inUnion)) {
						moved = true;
					}
				}
			}
		}

		if (moved) cnt++;
		else break;
	}
	cout << cnt;
}