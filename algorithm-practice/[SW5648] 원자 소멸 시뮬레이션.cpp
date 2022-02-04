#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

struct at {
	int x, y, d, K, n;
};

vector<at> atom;
int N, ans;
int map[4001][4001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

void simul(int n) {
	if (n <= 0)
		return;
	else {
		vector<int> crash;
		for (int t = 1; t <= N; t++) {
			int i = atom[t].d;
			if (i == -1)
				continue;
			int x = atom[t].x;
			int y = atom[t].y;

			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx == -1 || nx == 4001 || ny == -1 || ny == 4001) {
				n--;
				atom[t].d = -1;
				map[x][y] = 0;
				continue;
			}
			if (map[nx][ny]) {
				if (atom[map[nx][ny]].n == atom[t].n + 1) {
					crash.push_back(t);
					crash.push_back(map[nx][ny]);
					atom[t].d = -1;
					atom[map[nx][ny]].d = -1;
					map[nx][ny] = t;
					atom[map[nx][ny]].n += 1;
					map[x][y] = 0;
					continue;
				}
			}

			atom[t].x = nx;
			atom[t].y = ny;
			atom[t].n += 1;
			map[nx][ny] = t;
			map[x][y] = 0;
		}
		sort(crash.begin(), crash.end());
		crash.erase(unique(crash.begin(), crash.end()), crash.end());

		for (int i = 0; i < crash.size(); i++) {

			ans += atom[crash[i]].K;
			map[atom[crash[i]].x][atom[crash[i]].y] = 0;
			n--;
		}
		simul(n);
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int x, y, d, K;
		cin >> N;
		atom.push_back({ 0,0,0,0,0 });
		for (int i = 1; i <= N; i++) {
			cin >> y >> x >> d >> K;
			x += 1000;
			y += 1000;
			x *= 2;
			y *= 2;
			map[x][y] = i;
			atom.push_back({ x,y,d,K,0 });
		}
		simul(N);
		cout << "#" << t << ' ' << ans << endl;
		atom.clear();
		ans = 0;
	}
}