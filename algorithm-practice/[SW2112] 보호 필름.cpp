#include <iostream>
#include <algorithm>
using namespace std;

int D, W, K, ans = 10000000;
bool film[13][20];
bool visit[13];

void copyarr(bool a[13][20], bool b[13][20]) {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			b[i][j] = a[i][j];
		}
	}
}

bool check(bool f[13][20]) {
	bool flag = true;
	for (int i = 0; i < W; i++) {
		int cnt = 0, mx = 0;
		if (flag) {
			for (int j = 1; j < D; j++) {
				if (f[j - 1][i] == f[j][i]) {
					cnt++;
					mx = max(cnt, mx);
				}
				else {
					cnt = 0;
				}
			}
		}
		if (mx < K - 1)
			flag = false;
	}
	return flag;
}



void input(int k, int n, bool f[13][20]) {

	if (check(f) || k == D) {
		ans = min(ans, k);
	}
	else if (ans > k) {
		bool filmcopy[13][20] = { 0 };
		copyarr(f, filmcopy);
		for (int i = n; i < D; i++) {
			if (!visit[i]) {
				visit[i] = true;
				for (int j = 0; j < W; j++)
					filmcopy[i][j] = true;
				input(k + 1, i, filmcopy);
				for (int j = 0; j < W; j++)
					filmcopy[i][j] = false;

				input(k + 1, i, filmcopy);
				for (int j = 0; j < W; j++)
					filmcopy[i][j] = f[i][j];
				visit[i] = false;
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
			}
		}
		if (K == 1) {
			cout << '#' << t << ' ' << 0 << '\n';
		}
		else {
			input(0, 0, film);
			cout << '#' << t << ' ' << ans << '\n';

			ans = 10000000;
		}
	}
}