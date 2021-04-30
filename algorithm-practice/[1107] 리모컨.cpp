#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

int N, answer, digit;
bitset<10> broken;

int digitNo(int n) {
	int d = 0;
	if (n == 0) return 1;
	while (n) {
		d++;
		n /= 10;
	}
	return d;
}

void maxmin()
{
	int digit_min, digit_max;
	int maxnum, minnum;
	if (digit > 1) {
		for (digit_min = 9; digit_min >= 0; digit_min--) {
			if (!broken[digit_min]) break;
		}
		minnum = 0;
		for (int i = 0; i < digit - 1; i++) {
			minnum *= 10;
			minnum += digit_min;
		}
		minnum = abs(N - minnum) + digit - 1;
		answer = minnum < answer ? minnum : answer;
	}
	if (digit < 6) {
		for (digit_max = 0; digit_max <= 9; digit_max++) {
			if (!broken[digit_max]) break;
		}
		maxnum = 0;
		for (int i = 0; i < digit + 1; i++) {
			if (digit_max == 0) {
				for (int j = 1; j < 10; j++) {
					if (!broken[j]) {
						maxnum = j * pow(10, digit);
						break;
					}
				}
				break;
			}
			maxnum *= 10;
			maxnum += digit_max;
		}
		maxnum = abs(N - maxnum) + digit + 1;
		answer = maxnum < answer ? maxnum : answer;
	}
}

void find(int n, int ch) {
	if (n == digit) {
		int cnt = abs(N - ch) + digitNo(ch);
		answer = cnt < answer ? cnt : answer;
	}
	else {
		ch *= 10;
		for (int i = 0; i < 10; i++) {
			if (broken[i]) continue;
			find(n + 1, ch + i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		broken.set(b);
	}
	answer = abs(N - 100);
	digit = digitNo(N);
	maxmin();
	find(0, 0);
	cout << answer;
}