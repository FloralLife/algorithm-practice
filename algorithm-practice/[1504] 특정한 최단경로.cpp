#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 801
#define INF 999999999


vector<pair<int, int>> g[MAX];
int N, E;

long D(int s, int d) {
	vector<long> dis(N + 1, INF);
	dis[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		int a = -pq.top().first;
		int b = pq.top().second;
		pq.pop();

		if (dis[b] < a) continue;

		for (int i = 0; i < g[b].size(); i++) {
			int n = g[b][i].first;
			int nn = a + g[b][i].second;
			if (dis[n] > nn) {
				dis[n] = nn;
				pq.push({ -nn,n });
			}
		}
	}
	return dis[d];
}

int main() {
	int a, b, c;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	int n1, n2;
	cin >> n1 >> n2;

	long n12 = D(1, n1) + D(n1, n2) + D(n2, N);
	long n21 = D(1, n2) + D(n2, n1) + D(n1, N);

	if (min(n12, n21) >= INF)
		cout << -1;
	else
		cout << min(n12, n21);

	return 0;
}
