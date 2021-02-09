#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 500000

using namespace std;

map<string, int> eme;
vector<string> emeqh;

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		eme.insert({ name,i });
	}
	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;
		if (eme.find(name) != eme.end()) {
			emeqh.push_back(name);
		}
	}

	sort(emeqh.begin(), emeqh.end());
	cout << emeqh.size() << endl;
	for (int i = 0; i < emeqh.size(); i++) {
		cout << emeqh[i] << endl;
	}

	return 0;
}