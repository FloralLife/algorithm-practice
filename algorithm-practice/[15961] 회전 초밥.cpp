#include <iostream>
#include <set>
using namespace std;

int N, d, k, c;
int answer;
int sushi[3000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}
	for (int i = 0; i < N; i++) {
		set<int> s;
		for (int j = 0; j < k; j++) {
			s.insert(sushi[(i + j) % N]);
		}
		s.insert(c);
		int cnt = s.size();
		answer = answer > cnt ? answer : cnt;
	}
	cout << answer;
}