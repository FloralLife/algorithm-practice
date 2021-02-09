#include <iostream>
#include <string.h>

using namespace std;
int NEXT[5001];

int initNEXT(string key) {
	int i, j, max = 0;
	int M = key.length();
	NEXT[0] = -1;
	for (i = 0, j = -1; i <= M; i++, j++) {
		NEXT[i] = j;
		max = max > j ? max : j;
		while (j >= 0 && key[i] != key[j]) {
			j = NEXT[j];
		}
	}
	return max;
}

bool kmp(string str, int start, int len) {
	string key;
	int i, j;
	key = str.substr(start, len);

	initNEXT(key);


	int M = str.length();
	int cnt = 0;
	int st = 0;
	bool flag = true;
	for (i = 0, j = 0; i < M; i++, j++) {

		if (str[i] == key[j] && flag) {
			st = i;
			flag = false;
		}
		else if (j >= 0 && str[i] != key[j]) {
			j = NEXT[j];
			flag = true;
			st = i;
		}
		if (j == len - 1) {

			cnt++;
			j = NEXT[0];
			i = st;
			if (cnt == 2) return true;
			continue;
		}
	}
	return false;
}

int main() {
	string str;
	cin >> str;
	bool flag = true;
	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		int maxx = initNEXT(str.substr(i));
		ans = ans > maxx ? ans : maxx;
	}

	/*for (int i = 0; i < str.length(); i++) {
		cout << NEXT[i] << endl;
	}*/
	cout << ans << endl;
	for (int i = str.length() - 1; i >= 1; i--) {
		for (int j = 0; j <= str.length() - i; j++) {
			if (kmp(str, j, i)) {
				printf("%d\n", i);
				flag = false;
				i = 0;
				j = 5001;
			}
		}
	}
	if (flag) printf("0\n");
	return 0;
}