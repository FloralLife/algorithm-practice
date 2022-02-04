#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int d[1001][1001];

int main() {
	string a = "|", b = "&";
	string A, B;
	cin >> A >> B;
	A = a + A;
	B = b + B;
	int asize = A.size(), bsize = B.size();
	for (int i = 1; i < asize; i++) {
		for (int j = 1; j < bsize; j++) {
			int same = A[i] == B[j] ? 1 : 0;
			d[i][j] = max(max(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1] + same);
		}
	}
	cout << d[asize - 1][bsize - 1];

}