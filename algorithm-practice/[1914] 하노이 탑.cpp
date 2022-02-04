#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int N;
/*
* 모든 경우를 전부 셀 경우 시간초과가 납니다. 2^100만큼 돌아야 하기 때문.
*
void loooongInt() {
	bool flag = false;
	for (int i = 3; i >= 0; i--) {
		if (!flag && cnt[i]) {
			printf("%d", cnt[i]);
			flag = true;
			continue;
		}
		if(flag) printf("%09d", cnt[i]);
	}
}

void move(int src, int route) {
	cnt[0]++;
	for (int i = 0; i < 4; i++) {
		if (cnt[i] && cnt[i] % tenten == 0) {
			cnt[i + 1]++;
			cnt[i] = 0;
		}
	}
	if (N <= 20) printf("%d %d\n", src, route);
}
*/

void hanoi(int n, int src, int route, int dest) {
	if (n == 1) {
		printf("%d %d\n", src, dest);
		//move(src, dest);
	}
	else {
		hanoi(n - 1, src, dest, route);
		printf("%d %d\n", src, dest);
		//move(src, dest);
		hanoi(n - 1, route, src, dest);
	}
}

int main() {
	cin >> N;
	string answer = to_string(pow(2, N));
	answer = answer.substr(0, answer.find("."));
	answer[answer.length() - 1] -= 1;
	cout << answer << endl;
	if (N <= 20) hanoi(N, 1, 2, 3);
}