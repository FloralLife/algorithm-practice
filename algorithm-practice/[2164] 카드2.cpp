#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	queue<int> card;
	for (int i = 0; i < N; i++) {
		card.push(i);
	}
	while (N > 1) {
		card.pop();
		card.push(card.front());
		card.pop();
		N--;
	}
	cout << card.front() + 1;
}
