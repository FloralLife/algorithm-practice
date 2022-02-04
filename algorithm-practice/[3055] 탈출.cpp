#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, answer, destx, desty;
int forest[50][50];

queue<pair<int, int>> water, hedgehog;


int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(queue<pair<int, int>>& q, bool flood, int n) {
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        if ((flood && forest[x][y] < -n - 1) || (!flood && forest[x][y] > n)) return;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (flood) {
                if (nx == destx && ny == desty) continue;
                if (forest[nx][ny] >= 0) {
                    forest[nx][ny] = -n - 2;
                    q.push({ nx, ny });
                }
            }
            else {

                if (forest[nx][ny] == 0) {
                    forest[nx][ny] = n + 1;
                    if (nx == destx && ny == desty) return;
                    q.push({ nx, ny });
                }
            }
        }
    }
}

void toBeaver() {
    int n = 1;
    while (!hedgehog.empty() && !forest[destx][desty]) {
        bfs(water, true, n);
        bfs(hedgehog, false, n);
        n++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    char* str = new char[C];

    for (int i = 0; i < R; i++) {
        cin >> str;
        for (int j = 0; j < C; j++) {
            if (str[j] == 'D') destx = i, desty = j;
            else if (str[j] == '*') {
                water.push({ i,j });
                forest[i][j] = -2;
            }
            else if (str[j] == 'X') forest[i][j] = -1;
            else if (str[j] == 'S') {
                hedgehog.push({ i,j });
                forest[i][j] = 1;
            }
        }
    }
    toBeaver();
    if (forest[destx][desty] > 0) cout << forest[destx][desty] - 1;
    else cout << "KAKTUS";
}