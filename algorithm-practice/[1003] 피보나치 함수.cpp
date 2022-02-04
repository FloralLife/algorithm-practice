#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int cnt0[3];
		int cnt1[3];
		cnt0[0] = 1;
		cnt0[1] = 0;
		
		cnt1[0] = 0;
		cnt1[1] = 1;
		int n;
		scanf("%d", &n);
		for (int i = 0; i <= n; i++) {
			if (i == 0) {
				cnt0[2] = 1;
				cnt1[2] = 0;
			}
			else if (i == 1) {
				cnt0[2] = 0;
				cnt1[2] = 1;
			}
			else {
				cnt0[2] = cnt0[0] + cnt0[1];
				cnt0[0] = cnt0[1];
				cnt0[1] = cnt0[2];

				cnt1[2] = cnt1[1] + cnt1[0];
				cnt1[0] = cnt1[1];
				cnt1[1] = cnt1[2];
			}
		}
		printf("%d %d\n", cnt0[2], cnt1[2]);
	}
}