#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 20001;
const int INF = 987654321;

int V, E, K;
vector<pair<int, int>> g[MAX];

vector<int> D(int s, int v) {
	vector<int> d(v, INF);
	d[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		int a = -pq.top().first;
		int c = pq.top().second;
		pq.pop();

		if (d[c] < a) continue;

		for (int i = 0; i < g[c].size(); i++) {
			int n = g[c][i].first;
			int nn = a + g[c][i].second;
			if (d[n] > nn) {
				d[n] = nn;
				pq.push(make_pair(-nn, n));
			}
		}
	}
	return d;
}

int main() {
	cin >> V >> E >> K;
	V++;

	for (int i = 0; i < E; i++) {
		int s, d, c;
		cin >> s >> d >> c;
		g[s].push_back(make_pair(d, c));
	}
	vector<int> result = D(K, V);

	for (int i = 1; i < V; i++) {
		if (result[i] == INF)
			cout << "INF\n";
		else
			cout << result[i] << "\n";
	}
	return 0;
}