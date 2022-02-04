#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct babyShark {
	int x, y, cnt;
};

int space[20][20];
int N, answer;
vector<pair<int, int>> fish;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int bfs(pair<int, int> shark, int idx, int size) {
	int route[20][20] = { 0, };
	route[shark.first][shark.second] = 0;
	queue<pair<int, int>> q;
	q.push({ shark.first, shark.second });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (space[nx][ny] > size) continue;

			if (nx == fish[idx].first && ny == fish[idx].second) return route[x][y] + 1;

			if (!route[nx][ny]) {
				route[nx][ny] = route[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return 500;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	pair<int, int> shark;
	int fish_cnt = 0, answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> space[i][j];
			if (space[i][j] > 0 && space[i][j] <= 6) {
				fish.push_back({ i,j });
				fish_cnt++;
			}
			else if (space[i][j] == 9) {
				shark = { i,j };
				space[i][j] = 0;
			}
		}
	}
	int size = 2, ate = 0;
	while (fish_cnt--) {
		int nearest = 500, idx = 500;
		for (int i = 0; i < fish.size(); i++) {
			if (space[fish[i].first][fish[i].second] < size) {
				int dist = bfs(shark, i, size);
				if (dist < nearest) {
					idx = i;
					nearest = dist;
				}
			}
		}
		if (nearest == 500) break;
		answer += nearest;
		if (++ate == size) size++, ate = 0;
		shark.first = fish[idx].first, shark.second = fish[idx].second;
		fish.erase(fish.begin() + idx);
	}
	cout << answer;
}
