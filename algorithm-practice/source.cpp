#include <iostream>
#include <queue>
using namespace std;

#define WALL -1

int map[2][1000][1000];
bool visit[2][1000][1000];
int N, M;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct record {
	int x, y, w;
};

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int n;
			cin >> n;
			if (n) map[0][i][j] = map[1][i][j] = -1;
		}
	}
	queue<record> you;
	you.push({ 0,0,0 });
	visit[0][0][0] = visit[1][0][0] = true;
	map[0][0][0] = 1;
	while (!you.empty()) {
		int x = you.front().x, y = you.front().y, w = you.front().w;
		
	}

}