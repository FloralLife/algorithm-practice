#include <iostream>
#include <stdio.h>
using namespace std;

int N, opr[4], n[12];
int MAX = -99999999;
int MIN = 99999999;

void copy(int a[4], int b[4]) {
	for (int i = 0; i < 4; i++)
		b[i] = a[i];
}

void req(int cnt, int sum) {
	int oprcpy[4];
	int sumcpy;
	if (cnt < N - 1) {
		cnt++;
		copy(opr, oprcpy);
		sumcpy = sum;
		for (int i = 0; i < 4; i++) {
			if (opr[i]) {
				switch (i) {
				case 0:sum = sum + n[cnt];
					break;
				case 1:sum = sum - n[cnt];
					break;
				case 2:sum = sum * n[cnt];
					break;
				case 3:sum = sum / n[cnt];
					break;
				}
				opr[i]--;
				req(cnt, sum);
				copy(oprcpy, opr);
				sum = sumcpy;
			}
		}
	}
	else {
		MAX = sum > MAX ? sum : MAX;
		MIN = sum < MIN ? sum : MIN;
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < 4; i++)
			cin >> opr[i];
		for (int i = 0; i < N; i++)
			cin >> n[i];
		req(0, n[0]);
		int ans = MAX - MIN;
		cout << '#' << t + 1 << ' ' << ans << endl;
		MAX = -99999999;
		MIN = 99999999;
	}
}
