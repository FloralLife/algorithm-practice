#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001
#define INF 99999999

vector<pair<int, int>> g[MAX];

int main() {
	int n, m;
	int a, b, c;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a, b, c;
		g[a].push_back(make_pair(b, c));
	}

}