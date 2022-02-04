#include <iostream>
using namespace std;

int d[1001][1001];
int dx[] = { 0,-1,-1 };
int dy[] = { -1,0,-1 };

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &d[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int len = 1000;
			bool square = true;
			if (!d[i][j]) continue;
			for (int n = 0; n < 3; n++) {
				int nx = i + dx[n];
				int ny = j + dy[n];
				if (!d[nx][ny]) {
					square = false;
					break;
				}
				else {
					len = d[nx][ny] < len ? d[nx][ny] : len;
				}
			}
			if (square)
				d[i][j] = len + 1;
			ans = d[i][j] > ans ? d[i][j] : ans;
		}
	}
	cout << ans * ans;
}
