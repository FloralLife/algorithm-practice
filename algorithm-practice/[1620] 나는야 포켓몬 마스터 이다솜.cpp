#include <iostream>
#include <math.h>
#include <map>

using namespace std;
string poname[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<string, int> poketmon;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string name;
		cin >> name;
		poketmon.insert({ name,i });
		poname[i] = name;
	}
	for (int i = 0; i < M; i++) {
		string po;
		cin >> po;

		if (po[0] <= 57 && po[0] >= 48) {
			int no = 0;
			for (int j = 0; j < po.length(); j++) {
				no += pow(10, j) * (po[po.length() - 1 - j] - '0');
			}
			cout << poname[no] << "\n";
		}
		else {
			cout << poketmon.find(po)->second << "\n";
		}
	}
}