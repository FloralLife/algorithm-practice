#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cntTarget(vector<int> pro, int target) {
	sort(pro.begin(), pro.end());
	int size = pro.size();
	int j = size - 1, cnt = 0;
	for (int i = 0; i < size && i < j; i++) {
		if (i > 0 && pro[i - 1] == pro[i]) {
			continue;
		}
		while (pro[i] + pro[j] > target) {
			j--;
		}
		if (pro[i] + pro[j] == target) {
			cnt++;
			j--;
		}
		while (j < size - 1 && pro[j + 1] == pro[j])
			j--;
	}

	return cnt;
}

int main() {
	int n, target;
	vector<int> profit;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		profit.push_back(num);
	}
	cin >> target;
	cout << cntTarget(profit, target);
}
