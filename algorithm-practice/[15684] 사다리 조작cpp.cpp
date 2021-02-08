#include <iostream>
using namespace std;

bool ladder[30][10];
bool visit[30][10][3];
int N, H, M, answer = 100;

// �迭����
void copyarr(bool arr1[30][10], bool arr2[30][10]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			arr2[i][j] = arr1[i][j];
		}
	}
}

// ó�� ���� �����ٿ��� ��ٸ� �� �ر��� �������� ����
void down(int& x, int& y) {
	while (x < H) {
		if (y - 1 >= 0 && ladder[x][y - 1]) y--;
		else if (ladder[x][y]) y++;
		x++;
	}
}

// i������ ������ i������ �������� üũ�ϴ� �Լ�
bool check() {
	for (int i = 0; i < N; i++) {
		int x = 0;
		int y = i;
		down(x, y);
		if (y != i) return false;
	}
	return true;
}

// ��ٸ��� ���� �߰��غ��� �Լ�
void makeladder(int cnt, int n) {
	if (cnt > 3) return;
	else if (!check()) {
		bool _ladder[30][10] = { false };
		copyarr(ladder, _ladder);

		for (int i = n / (N - 1); i < H; i++) {
			for (int j = 0; j < N - 1; j++) {
				n++;
				if (ladder[i][j + 1] || ladder[i][j] || (j - 1 >= 0 && ladder[i][j - 1])) continue;
				ladder[i][j] = true;
				makeladder(cnt + 1, n);
				copyarr(_ladder, ladder);
			}
		}
	}
	else {
		answer = cnt < answer ? cnt : answer;
	}
}

int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a - 1][b - 1] = true;
	}

	makeladder(0, 0);
	answer = answer > 3 ? -1 : answer;
	cout << answer;
	return 0;
}