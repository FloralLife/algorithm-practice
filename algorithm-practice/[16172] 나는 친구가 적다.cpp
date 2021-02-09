#include <iostream>
#include <string.h>

using namespace std;

int NEXT[200000];
char S[200001], K[200001];



void initNEXT(char* k) {
	int i, j, M = strlen(k);
	NEXT[0] = -1;
	for (i = 0, j = -1; i < M; i++, j++) {
		NEXT[i] = k[i] == k[j] ? NEXT[j] : j;
		while (j >= 0 && k[i] != k[j]) {
			j = NEXT[j];
		}
	}
}

int KMP(char* s, char* k) {
	int i, j, M = strlen(s), N = strlen(k);
	for (i = 0, j = 0; i < M && j < N; i++) {
		if (s[i] <= 57 && s[i] >= 48) continue;
		while (j >= 0 && s[i] != k[j]) {
			j = NEXT[j];
		}
		j++;
	}
	if (j == N) return 1;
	else return 0;
}

int main() {
	cin >> S;
	cin >> K;
	initNEXT(K);
	cout << KMP(S, K);
	return 0;
}