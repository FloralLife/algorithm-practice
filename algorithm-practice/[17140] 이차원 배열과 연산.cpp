#include <iostream>
#include <algorithm>
using namespace std;

int row, col, t;
int r, c, k;

int arr[100][100];
int rowcnt[100], colcnt[100];

int findIdx(int n, pair<int, int> array[100], int size) {
	for (int i = 0; i < size; i++) {
		if (array[i].second == n) return i;
	}
	return size;
}

void R(int n, int& max) {
	int cnt = 0, i;
	pair<int, int> rowarr[100];
	for (i = 0; i < rowcnt[n]; i++) {
		if (arr[n][i] == 0) continue;
		int idx = findIdx(arr[n][i], rowarr, cnt);
		if (idx == cnt) {
			rowarr[idx].first = 1;
			rowarr[idx].second = arr[n][i];
			cnt++;
		}
		else rowarr[idx].first++;
	}
	sort(rowarr, rowarr + cnt);
	for (i = 0; i < cnt && i < 50; i++) {
		arr[n][2 * i] = rowarr[i].second;
		arr[n][2 * i + 1] = rowarr[i].first;
		colcnt[2 * i] = n + 1;
		colcnt[2 * i + 1] = n + 1;
	}
	rowcnt[n] = 2 * i;
	if (max < rowcnt[n]) max = rowcnt[n];
}

void C(int n, int& max) {
	int cnt = 0, i;
	pair<int, int> colarr[100];
	for (i = 0; i < colcnt[n]; i++) {
		if (arr[i][n] == 0) continue;
		int idx = findIdx(arr[i][n], colarr, cnt);
		if (idx == cnt) {
			colarr[idx].first = 1;
			colarr[idx].second = arr[i][n];
			cnt++;
		}
		else colarr[idx].first++;
	}
	sort(colarr, colarr + cnt);
	for (i = 0; i < cnt && i < 50; i++) {
		arr[2 * i][n] = colarr[i].second;
		arr[2 * i + 1][n] = colarr[i].first;
		rowcnt[2 * i] = n + 1;
		rowcnt[2 * i + 1] = n + 1;
	}
	colcnt[n] = 2 * i;
	if (max < colcnt[n]) max = colcnt[n];
}

void paddingR() {
	for (int i = 0; i < row; i++) {
		for (int j = rowcnt[i]; j < col; j++) {
			arr[i][j] = 0;
		}
	}
}

void paddingC() {
	for (int i = 0; i < col; i++) {
		for (int j = colcnt[i]; j < row; j++) {
			arr[j][i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> k;
	row = col = 3;

	for (int i = 0; i < 3; i++) {
		rowcnt[i] = colcnt[i] = 3;
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	for (t = 0; t <= 100; t++) {
		if (arr[r - 1][c - 1] == k) break;
		int maxrow = 0, maxcol = 0;
		if (row >= col) {
			for (int n = 0; n < row; n++) {
				R(n, maxcol);
				paddingR();
			}
			col = maxcol;

		}
		else {
			for (int n = 0; n < col; n++) {
				C(n, maxrow);
				paddingC();
			}
			row = maxrow;
		}
	}
	if (t <= 100) cout << t;
	else cout << -1;
}