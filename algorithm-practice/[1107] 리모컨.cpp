#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

bool broken[10];
int answer, mindif = 500000, digit, N;


int getDigit(int n) {
	int i;
	for (i = 0; n > 0; i++) {
		n /= 10;
	}
	return i;
}

void find(int n, int chanel) {
	if (n >= digit - 1 && n <= digit + 1 && n != 0) {
		int dif = abs(N - chanel);
		if (dif < mindif) {
			answer = chanel;
			mindif = dif;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (broken[i]) continue;
		int num = i * pow(10, n);
		if (n <= digit) {
			chanel += num;
			find(n + 1, chanel);
			chanel -= num;
		}
	}
}

int main() {
	int M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		broken[num] = true;
	}
	digit = getDigit(N);
	find(0, 0);
	answer = min(getDigit(answer) + mindif, abs(100 - N));
	cout << answer << endl;
}