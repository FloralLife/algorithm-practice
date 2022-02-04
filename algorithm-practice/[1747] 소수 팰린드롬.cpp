#include <iostream>
#include <bitset>
#include <string>
using namespace std;

#define MAXPRIME 1003002

bitset<MAXPRIME> isComposite;


bool checkPalindrome(int n) {
	int d = 0;
	string num = to_string(n);
	if (n == 0) d = 1;
	else
		while (n) {
			d++;
			n /= 10;
		}

	int l = 0, r = d - 1;
	while (l < r) {
		if (num[l++] != num[r--]) return false;
	}
	return true;
}

void eratosthenes() {
	isComposite.set(0);
	isComposite.set(1);
	for (int i = 2; i * i < MAXPRIME; i++) {
		if (isComposite[i]) continue;
		for (int j = i + i; j < MAXPRIME; j += i) {
			isComposite.set(j);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	eratosthenes();
	while (1) {
		if (!isComposite[N] && checkPalindrome(N))
			break;
		N++;
	}
	cout << N;
}
