#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int NEXT[1000002];
char text[1000002];
char pattern[1000002];
int cntpo[1000002];
int n;

void initNEXT(string key) {
	int i, j;
	int M = key.length();
	NEXT[0] = -1;
	for (i = 0, j = -1; i <= M; i++, j++) {
		NEXT[i] = j;
		while (j >= 0 && key[i] != key[j]) {
			j = NEXT[j];
		}
	}
}

int kmp(string str, string key) {
	int i, j;
	int M = str.length(), N = key.length();
	int cnt = 0;
	int st = 0;
	bool flag = true;
	for (i = 0, j = 0; i < M && j < N; i++, j++) {
		while (j >= 0 && str[i] != key[j]) {
			/*cout << i << " " << j << endl;
			cout << "불일치 : str == ";
			for (int z = i - j; z <= i; z++) {
				cout << str[z];
			}
			cout << " key == ";
			for (int z = 0; z <= j; z++) {
				cout << key[z];
			}
			cout << endl;*/
			j = NEXT[j];
		}
		if (j == N - 1) {
			/*cout << i << " " << j << endl;
			cout << "일치 : str == ";
			for (int z = i - N + 1; z <= i; z++) {
				cout << str[z];
			}
			cout << " key == ";
			for (int z = 0; z < N; z++) {
				cout << key[z];
			}
			cout << endl;*/
			cnt++;
			cntpo[n++] = i - N + 2;
			i--;
			j = NEXT[j] - 1;
		}

	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin.getline(text, 1000002);
	cin.getline(pattern, 1000002);
	initNEXT(pattern);
	/*for (int i = 0; i < strlen(pattern); i++) {
		cout << NEXT[i] << " ";
	}
	cout << endl;*/

	int ans = kmp(text, pattern);
	cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		cout << cntpo[i] << '\n';
	}
	return 0;
}