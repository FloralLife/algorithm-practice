#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int N, P, W, L, G, score = 0;
	cin >> N >> P;
	cin >> W >> L >> G;

	map<string, char> win;
	string name;
	char victory;
	for (int i = 0; i < P; i++) {
		cin >> name >> victory;
		if (victory == 'W') {
			win[name] = victory;
		}
	}

	bool iron = true;
	for (int i = 0; i < N; i++) {
		if (!iron) continue;
		cin >> name;
		if (win[name]) {
			score += W;
			if (score >= G) {
				iron = false;
			}
		}
		else score = score > L ? score - L : 0;
	}

	if (iron) cout << "I AM IRONMAN!!";
	else cout << "I AM NOT IRONMAN!!";
	return 0;
}