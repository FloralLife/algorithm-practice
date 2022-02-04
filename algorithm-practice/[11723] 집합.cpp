#include <iostream>
#include <string.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool S[20] = { false };
	int M, num;
	char opr[10];
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> opr;
		if (!strcmp(opr, "add")) {
			cin >> num;
			if (S[num - 1]) continue;
			S[num - 1] = true;
		}
		else if (!strcmp(opr, "remove")) {
			cin >> num;
			if (S[num - 1])
				S[num - 1] = false;
		}
		else if (!strcmp(opr, "check")) {
			cin >> num;
			if (S[num - 1]) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(opr, "toggle")) {
			cin >> num;
			S[num - 1] = !S[num - 1];
		}
		else if (!strcmp(opr, "all")) {
			for (int i = 0; i < 20; i++)
				S[i] = true;
		}
		else if (!strcmp(opr, "empty")) {
			for (int i = 0; i < 20; i++) {
				S[i] = false;
			}
		}
	}
	return 0;
}