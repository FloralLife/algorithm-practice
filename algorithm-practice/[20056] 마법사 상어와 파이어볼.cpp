#include <iostream>
#include <vector>
using namespace std;

struct Fireball {
	int r, c, m, s, d;
};

vector<Fireball> fireball;
vector<Fireball> board[50][50];
int N, M, K;

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

int inRange(int num) {
	num %= N;
	if (num < 0) num += N;
	return num;
}

int move() {
	while (K--) {
		int size = fireball.size();
		for (int i = 0; i < size; i++) {
			int r = inRange(fireball[i].r + (dx[fireball[i].d] * fireball[i].s));
			int c = inRange(fireball[i].c + (dy[fireball[i].d] * fireball[i].s));
			fireball[i].r = r;
			fireball[i].c = c;

			board[r][c].push_back(fireball[i]);

			if (!board[r][c].empty()) {
				fireball.erase(fireball.begin() + i--);
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireball.push_back({ r,c,m,s,d });
	}
}