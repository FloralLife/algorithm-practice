#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int s;
	int stair[300];
	int sum1[300];
	int sum2[300];
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> stair[i];
	}
	sum1[0] = stair[0];
	sum1[1] = sum1[0] + stair[1];
	sum2[0] = 0;
	sum2[1] = stair[1];
	for (int i = 2; i < s; i++) {
		sum1[i] = sum2[i - 1] + stair[i];
		sum2[i] = max(sum2[i - 2], sum1[i - 2]) + stair[i];
	}
	int ans = max(sum1[s - 1], sum2[s - 1]);
	cout << ans;
}