#include <iostream>
#include <string>
using namespace std;

int palindrome(string str) {
	int len = str.size();
	bool pseudo = false;
	len = len / 2;
	int i, j, psdi, psdj;
	if (len % 2) i = len - 1, j = len + 1;
	else i = len - 1, j = len;
	while (1) {
		if (i == 0 && j == str.size() - 1) {
			return pseudo ? 1 : 0;
		}
		if (str[i] != str[j]) {
			if (!pseudo) {

			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	string str;

	for (int i = 0; i < T; i++) {
		cin >> str;
		cout << palindrome(str);
	}

}