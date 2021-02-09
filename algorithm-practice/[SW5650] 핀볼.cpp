#include <iostream>
#include <vector>
using namespace std;

int map[100][100];
pair<int, int> wormhole[5][100][100];
int N, ans, cnt;
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

void dfs(int x, int y, int i) {
	int nx = x + dx[i];
	int ny = y + dy[i];
	if (nx == -1 || nx == N || ny == -1 || ny == N) {
		cnt++;
		if (map[x][y] == -1) return;
		dfs(nx, ny, (i + 2) % 4);
	}
	else {
		switch (map[nx][ny]) {
		case 0:
			dfs(nx, ny, i);
			break;
		case 1:
			cnt++;
			switch (i) {
			case 0: i = 1; break;
			case 1:	i = 3; break;
			case 2: i = 0; break;
			case 3: i = 2; break;
			}
			dfs(nx, ny, i);
			break;
		case 2:
			cnt++;
			switch (i) {
			case 0: i = 3; break;
			case 1: i = 2; break;
			case 2: i = 0; break;
			case 3: i = 1; break;
			}
			dfs(nx, ny, i);
			break;
		case 3:
			cnt++;
			switch (i) {
			case 0: i = 2; break;
			case 1: i = 0; break;
			case 2: i = 3; break;
			case 3: i = 1; break;
			}
			dfs(nx, ny, i);
			break;
		case 4:
			cnt++;
			switch (i) {
			case 0: i = 2; break;
			case 1: i = 3; break;
			case 2: i = 1; break;
			case 3: i = 0; break;
			}
			dfs(nx, ny, i);
			break;
		case 5:
			cnt++;
			switch (i) {
			case 0: i = 2; break;
			case 1: i = 3; break;
			case 2: i = 0; break;
			case 3: i = 1; break;
			}
			dfs(nx, ny, i);
			break;
		case 6:
			dfs(wormhole[0][nx][ny].first, wormhole[0][nx][ny].second, i);
			break;
		case 7:
			dfs(wormhole[1][nx][ny].first, wormhole[1][nx][ny].second, i);
			break;
		case 8:
			dfs(wormhole[2][nx][ny].first, wormhole[2][nx][ny].second, i);
			break;
		case 9:
			dfs(wormhole[3][nx][ny].first, wormhole[3][nx][ny].second, i);
			break;
		case 10:
			dfs(wormhole[4][nx][ny].first, wormhole[4][nx][ny].second, i);
			break;
		case -1:
			if (ans < cnt) {
				ans = cnt;
				return;
			}
			break;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		vector<pair<int, int>> wh[5];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6) {
					wh[map[i][j] - 6].push_back({ i,j });
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			if (wh[i].size()) {
				wormhole[i][wh[i][0].first][wh[i][0].second] = { wh[i][1].first, wh[i][1].second };
				wormhole[i][wh[i][1].first][wh[i][1].second] = { wh[i][0].first, wh[i][0].second };
			}
		}
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (map[x][y]) continue;
				map[x][y] = -1;
				for (int i = 0; i < 4; i++) {
					dfs(x, y, i);
					cnt = 0;
				}
				map[x][y] = 0;
			}
		}
		
		cout << '#' << t << " " << ans << endl;
	}
}