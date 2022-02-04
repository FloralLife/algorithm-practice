#include <iostream>
using namespace std;

int main() {
	int N, M, answer;
	cin >> N >> M;
	int px = 0, nx, edgeDistance = 0, distance = 0;

	for (int i = 0; i < M; i++) {
		cin >> nx;
		if (i == 0) {
			edgeDistance = edgeDistance > nx ? edgeDistance : nx;
			px = nx;
		}
		if (i == M - 1) {
			edgeDistance = edgeDistance > N - nx ? edgeDistance : N - nx;
		}
		distance = distance > nx - px ? distance : nx - px;
		px = nx;
	}
	answer = edgeDistance > (distance + 1) / 2 ? edgeDistance : (distance + 1) / 2;
	cout << answer;
}