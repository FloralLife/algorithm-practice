#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, answer = 100, room[8][8];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<pair<int, int>> cctv;

void copy(int from[][8], int to[][8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			to[i][j] = from[i][j];
		}
	}
}

int count() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (room[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void monitor(int x, int y, int direction) {
	direction %= 4;
	while (1) {
		x += dx[direction], y += dy[direction];
		if (x < 0 || x >= N || y < 0 || y >= M) return;
		if (room[x][y] == 6) return;
		if (room[x][y] == 0) room[x][y] = -1;
	}
}

void camera(int n, int direction) {
	int x = cctv[n].first, y = cctv[n].second;
	switch (room[x][y]) {
	case 1:
		monitor(x, y, direction);
		break;
	case 2:
		monitor(x, y, direction);
		monitor(x, y, direction + 2);
		break;
	case 3:
		monitor(x, y, direction);
		monitor(x, y, direction + 1);
		break;
	case 4:
		monitor(x, y, direction);
		monitor(x, y, direction + 1);
		monitor(x, y, direction + 3);
		break;
	case 5:
		monitor(x, y, direction);
		monitor(x, y, direction + 1);
		monitor(x, y, direction + 2);
		monitor(x, y, direction + 3);
		break;
	}
}

void find(int n) {
	if (n == cctv.size()) {
		answer = min(count(), answer);
	}
	else {
		int copy_room[8][8];
		copy(room, copy_room);
		for (int i = 0; i < 4; i++) {
			camera(n, i);
			find(n + 1);
			copy(copy_room, room);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
			if (room[i][j] != 0 && room[i][j] != 6) cctv.push_back({ i,j });
		}
	}
	find(0);
	cout << answer;
}