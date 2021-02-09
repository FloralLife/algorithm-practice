#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int S[17][17];
bool visit[17];
int N, ans;

int synergy(int s[]) {
	int syn = 0;

	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			if (i == j) continue;
			syn += S[s[i]][s[j]];
		}
	}
	return syn;
}

void choice(int n, int a[], int b[]) {
	if (n == N / 2) {
		ans = min(abs(synergy(a) - synergy(b)), ans);
	}
	else {
		for (int i = 1; i <= N; i++) {
			int aa[16] = { 0 };
			int bb[16] = { 0 };
			for (int i = 0; i < n; i++) {
				aa[i] = a[i];
			}
			if (n == 0 || (!visit[i] && aa[n - 1] < i)) {
				aa[n] = i;
				visit[i] = true;
				if (n == N / 2 - 1) {
					int cnt = 0;
					for (int e = 1; e <= N; e++) {
						if (!visit[e]) {
							bb[cnt] = e;
							cnt++;
						}
					}
				}
				choice(n + 1, aa, bb);
				visit[i] = false;
			}
		}
	}
}


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> S[i][j];
			}
		}
		ans = 99999999;
		memset(visit, false, sizeof(visit));
		int a[16], b[16];
		choice(0, a, b);
		cout << '#' << t << ' ' << ans << endl;
	}
}