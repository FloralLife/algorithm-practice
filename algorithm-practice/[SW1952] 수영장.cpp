#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int cost[4] = { 0 };
		int swim[12] = { 0 };
		int d[12] = { 0 };

		for (int i = 0; i < 4; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < 12; i++) {
			cin >> swim[i];
			d[i] = min(cost[1], swim[i] * cost[0]);
		}

		for (int i = 1; i < 12; i++) {
			if (i < 3) {
				d[i] = min(d[i] + d[i - 1], cost[2]);
				continue;
			}
			d[i] = min(d[i - 3] + cost[2], d[i - 1] + d[i]);
		}
		cout << '#' << t << ' ' << min(d[11], cost[3]) << endl;
	}
}