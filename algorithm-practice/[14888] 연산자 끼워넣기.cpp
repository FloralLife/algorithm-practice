#include <iostream>
using namespace std;

int N, MIN = 1000000000, MAX = -1000000000;
int opr[4], A[100];

void copyarr(int a[4], int b[4]) {
	for (int i = 0; i < 4; i++) {
		a[i] = b[i];
	}
}

void find(int n, int sum) {
	if (n == N) {
		MAX = MAX > sum ? MAX : sum;
		MIN = MIN < sum ? MIN : sum;
		return;
	}
	else {
		int _opr[4], _sum;
		copyarr(_opr, opr);
		_sum = sum;
		for (int i = 0; i < 4; i++) {
			if (opr[i]) {
				switch (i) {
				case 0:
					sum += A[n];
					break;
				case 1:
					sum -= A[n];
					break;
				case 2:
					sum *= A[n];
					break;
				case 3:
					sum /= A[n];
					break;
				}
				opr[i]--;
				find(n + 1, sum);
				sum = _sum;
				copyarr(opr, _opr);
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> opr[i];
	}
	find(1, A[0]);
	cout << MAX << endl << MIN;
}