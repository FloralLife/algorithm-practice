#include <iostream>
#include <queue>
using namespace std;

struct Yeongjo {
	int x, y, l, r;
};

int map[1000][1000];
int N, M, L, R, answer = 1;
queue<Yeongjo> land;

void updown(Yeongjo yj) {
	int nx = yj.x;
	nx++;
	while (map[nx][yj.y] == 0 && nx < N) {
		map[nx][yj.y] = 2;
		land.push({ nx++, yj.y, yj.l, yj.r });
		answer++;
	}
	nx = yj.x;
	nx--;
	while (map[nx][yj.y] == 0 && nx >= 0) {
		map[nx][yj.y] = 2;
		land.push({ nx--, yj.y, yj.l, yj.r });
		answer++;
	}
}

int main() {
	cin >> N >> M;
	cin >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 2) {
				land.push({ i,j,L,R });
			}
		}
	}

	while (!land.empty()) {
		Yeongjo YJ = land.front();
		land.pop();
		updown(YJ);
		if (YJ.y - 1 >= 0 && YJ.l && map[YJ.x][YJ.y - 1] == 0) {
			map[YJ.x][YJ.y - 1] = 2;
			land.push({ YJ.x, YJ.y - 1, YJ.l - 1, YJ.r });
			answer++;
		}
		if (YJ.y + 1 < M && YJ.r && map[YJ.x][YJ.y + 1] == 0) {
			map[YJ.x][YJ.y + 1] = 2;
			land.push({ YJ.x, YJ.y + 1, YJ.l, YJ.r - 1 });
			answer++;
		}
	}
	cout << answer;
}