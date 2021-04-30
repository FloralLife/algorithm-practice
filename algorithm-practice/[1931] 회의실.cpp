#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> conferences;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		conferences.push_back({ end, start });
	}
	sort(conferences.begin(), conferences.end());

	int cnt = 0, temp = 0;
	for (int i = 0; i < N; i++) {
		if (conferences[i].second >= temp) {
			temp = conferences[i].first;
			cnt++;
		}
	}
	cout << cnt;
}
