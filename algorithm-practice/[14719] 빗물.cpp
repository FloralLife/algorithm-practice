#include <algorithm>
#include <iostream>
using namespace std;

struct block {
	int h, idx;
};

block world[500];
int height[500];
int H, W, answer;

bool cmp(block a, block b) { return a.h > b.h; }

int fill(block big, block small) {
	int cnt = 0;
	if (big.idx > small.idx) {
		for (int i = small.idx + 1; i < big.idx; i++) {
			if (height[i] == -1) break;
			cnt += small.h - height[i];
			height[i] = -1;
		}
	}
	else if (big.idx < small.idx) {
		for (int i = small.idx - 1; i > big.idx; i--) {
			if (height[i] == -1) break;
			cnt += small.h - height[i];
			height[i] = -1;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		cin >> height[i];
		world[i] = { height[i],i };
	}
	sort(world, world + W, cmp);
	for (int i = 0; i < W - 1; i++) {
		height[world[i].idx] = height[world[i + 1].idx] = -1;
		answer += fill(world[i], world[i + 1]);
	}
	cout << answer;
}