#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

int N, answer = 1000000;
int status[20][20];
bool team[20];

int calculate(vector<int> teamStart, vector<int> teamLink) {
	int start = 0, link = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			if (i == j) continue;
			start += status[teamStart[i]][teamStart[j]];
			link += status[teamLink[i]][teamLink[j]];
		}
	}
	return abs(start - link);
}

void find(int n, int c) {
	if (n == N / 2) {
		vector<int> teamStart, teamLink;
		for (int i = 0; i < N; i++) {
			if (team[i]) teamStart.push_back(i);
			else teamLink.push_back(i);
		}
		int result = calculate(teamStart, teamLink);
		answer = answer < result ? answer : result;
	}
	else {
		for (int i = c; i < N; i++) {
			team[i] = true;
			find(n + 1, i + 1);
			team[i] = false;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> status[i][j];
		}
	}
	find(0, 0);
	cout << answer;
}