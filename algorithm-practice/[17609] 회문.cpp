#include <iostream>
#include <string>
using namespace std;

bool pseudo(string str, int& left, int& right) {
	while (left <= right) {
		if (str[left] != str[right]) {
			return false;
		}
		left++, right--;
	}
	return true;
}

int palindrome(string str) {
	int left = 0, right = str.size() - 1;
	if (pseudo(str, left, right)) return 0;
	int l = left + 1, r = right;
	if (pseudo(str, l, r)) return 1;
	l = left, r = right - 1;
	if (pseudo(str, l, r)) return 1;
	return 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> str;
		cout << palindrome(str) << endl;
	}
}