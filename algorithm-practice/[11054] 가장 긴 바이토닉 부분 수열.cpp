#include <iostream>
#include <algorithm>
using namespace std;
int A[1000], dl[1000], dr[1000], d[1000];

int main() {
	int N, ans, mxr, mxl;
	ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++) {
		dl[i] = 1;
		mxl = 1;
		for (int j = 0; j < i; j++)
			if (A[j] < A[i])
				mxl = max(mxl, dl[i] + dl[j]);
		dl[i] = mxl;
	}

	for (int i = N - 1; i >= 0; i--) {
		dr[i] = 1;
		mxr = 1;
		for (int j = N - 1; j >= 0; j--)
			if (A[j] < A[i])
				mxr = max(mxr, dr[i] + dr[j]);
		dr[i] = mxr;
		d[i] = dr[i] + dl[i] - 1;
		ans = max(ans, d[i]);
	}
	cout << ans;

}