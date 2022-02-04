#include <iostream>
#include <queue>
using namespace std;

struct edge {
	int node1, node2, w;
};

int group[10001];


int V, E;

bool operator<(edge a, edge b) {
	return a.w > b.w;
}

int findGroup(int n) {
	if (n == group[n]) return n;
	else {
		group[n] = findGroup(group[n]);
		return group[n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<edge> edge_sort;
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		group[i] = i;
	}
	for (int i = 0; i < E; i++) {
		edge e;
		cin >> e.node1 >> e.node2 >> e.w;
		edge_sort.push(e);
	}
	int cnt = 0;
	while (!edge_sort.empty()) {
		edge e = edge_sort.top();
		edge_sort.pop();
		int group1 = findGroup(e.node1);
		int group2 = findGroup(e.node2);
		if (group1 == group2) continue;
		group[group2] = group1;
		cnt += e.w;
	}
	cout << cnt;
}