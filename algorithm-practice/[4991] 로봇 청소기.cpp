#include <iostream>
#include <bitset>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;

bitset<10> use;
vector<pair<int, int>> dirty;
pair<int, int> start;
int w, h, answer = -1;
int order[10];
int dist[11][10];
bool room[20][20];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct movement {
	int x, y, dis;
};

int getDistance(pair<int, int> from, pair<int, int> to) {
	queue<movement> q;
	bool visit[20][20] = { 0, };
	q.push({ from.first, from.second, 0 });
	visit[from.first][from.second] = true;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, dis = q.front().dis;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (visit[nx][ny] || room[nx][ny]) continue;
			if (nx == to.first && ny == to.second)
				return dis + 1;
			visit[nx][ny] = true;
			q.push({ nx, ny, dis + 1 });
		}
	}
	return -1;
}

int measure(int n) {
	int sum;
	if (dist[n][order[0]] == 0) {
		sum = getDistance(start, dirty[order[0]]);
		dist[n][order[0]] = sum;
	}
	else sum = dist[n][order[0]];

	if (sum == -1) return -1;
	for (int i = 0; i < n - 1; i++) {
		int d;
		if (dist[order[i]][order[i + 1]] == 0) {
			d = getDistance(dirty[order[i]], dirty[order[i + 1]]);
			dist[order[i]][order[i + 1]] = d;
		}
		else d = dist[order[i]][order[i + 1]];
		if (d == -1) return -1;
		sum += d;
	}
	return sum;
}

void permutate(int n, int size) {
	if (n == size) {
		int sum = measure(n);
		if (answer == -1 || answer > sum) answer = sum;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (use[i]) continue;
			use.set(i);
			order[n] = i;
			permutate(n + 1, size);
			use.reset(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> w >> h;
		int cnt = 0;
		if (w == 0 && h == 0) return 0;
		for (int i = 0; i < h; i++) {
			string c;
			cin >> c;
			for (int j = 0; j < w; j++) {
				if (c[j] == 'o') start = { i,j };
				else if (c[j] == '*') {
					dirty.push_back({ i,j });
					cnt++;
				}
				else if (c[j] == 'x') room[i][j] = true;
			}
		}
		permutate(0, cnt);
		printf("%d\n", answer);

		dirty.clear();
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (room[i][j]) room[i][j] = false;
		for (int i = 0; i < cnt + 1; i++) {
			for (int j = 0; j < cnt; j++) {
				if (dist[i][j]) dist[i][j] = 0;
			}
		}
		answer = -1;
	}
}