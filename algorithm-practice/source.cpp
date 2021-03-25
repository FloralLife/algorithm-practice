#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N, M;

bool invade(int board[1][15]) {
	bool check = false;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) continue;
			board[i][j] = 0;
			if (i < N - 1) board[i + 1][j] = 1;
			check = true;
		}
	}
	return check;
}

int distance(pair<int, int> archer, pair<int, int> enemy) {
	return abs(archer.first - enemy.first) + abs(archer.second - enemy.second);
}

vector<pair<int, int>> findTarget(int board[15][15], pair<int, int> archers[3]) {

}

int count(int board[15][15], pair<int, int> archers[3]) {
	vector<pair<int, int>> target;
	
}