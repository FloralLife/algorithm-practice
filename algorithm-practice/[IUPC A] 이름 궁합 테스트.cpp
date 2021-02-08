#include <iostream>
using namespace std;

int stroke[26] = {
	3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1
};

int main() {
	int N, M, chemi[200];
	char A[100], B[100];
	cin >> N >> M;
	cin >> A >> B;

	int a = 0, b = 0;
	for (int i = 0; i < N + M;) {
		if (a<N) chemi[i++] = stroke[(int)(A[a++] - 'A')];
		if (b<M) chemi[i++] = stroke[(int)(B[b++] - 'A')];
	}

	int n = N + M;
	while (n-- > 2) {
		for (int i = 0; i < n; i++) {
			chemi[i] = (chemi[i] + chemi[i + 1]) % 10;
		}		
	}

	int answer = chemi[0] * 10 + chemi[1];
	cout << answer << "%";
}