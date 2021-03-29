#include <iostream>
using namespace std;

int N, answer = 1000000000;
int city[20][20];
int x, y, d1, d2;

void area5(bool area[20][20]) {
	for (int i = 0; i <= d1 + d2; i++) {
		int l = i < d1 ? y - i : y - d1 + (i - d1);
		int r = i < d2 ? y + i : y + d2 - (i - d2);
		for (int j = l; j <= r; j++) {
			area[x + i][j] = true;
		}
	}
}

int maxDiff() {
	int cnt[5] = { 0, };
	bool area[20][20] = { 0, };
	area5(area);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (area[i][j])
				cnt[4] += city[i][j];
			else {
				if (i >= 0 && i < x + d1 && j >= 0 && j <= y)
					cnt[0] += city[i][j];
				else if (i >= 0 && i <= x + d2 && j > y && j < N)
					cnt[1] += city[i][j];
				else if (i >= x + d1 && i < N && j >= 0 && j < y - d1 + d2)
					cnt[2] += city[i][j];
				else if (i > x + d2 && i < N && j >= y - d1 + d2 && j < N)
					cnt[3] += city[i][j];
			}
		}
	}
	int min = 1000000000;
	int max = 0;
	for (int i = 0; i < 5; i++) {
		min = min > cnt[i] ? cnt[i] : min;
		max = max < cnt[i] ? cnt[i] : max;
	}
	return max - min;
}

void find(int n) {
	switch (n) {
	case 0:
		for (int i = 0; i < N - 2; i++) {
			x = i;
			find(n + 1);
		}
		break;
	case 1:
		for (int i = 1; i < N - 1; i++) {
			y = i;
			find(n + 1);
		}
		break;
	case 2:
		for (int i = 1; i <= N - 1; i++) {
			if (x + i >= N - 1 || y - i < 0) continue;
			d1 = i;
			find(n + 1);
		}
		break;
	case 3:
		for (int i = 1; i <= N - 1; i++) {
			if (x + d1 + i >= N || y + i >= N) continue;
			d2 = i;
			find(n + 1);
		}
		break;
	case 4:
		int diff = maxDiff();
		if (diff < answer) answer = diff;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
		}
	}
	find(0);
	cout << answer;
}