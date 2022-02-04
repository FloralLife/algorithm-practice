#include <string>
#include <math.h>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int score[3] = { 0, 0, 0 };
	int cursor = -1;
	for (int i = 0; i < dartResult.length(); i++) {
		if (dartResult[i] >= '0' && dartResult[i] <= '9') {
			cursor++;
			int n = (int)(dartResult[i] - '0');
			score[cursor] = n;
			if (n == 1) {
				if (dartResult[i + 1] == '0') {
					score[cursor] = 10;
					i++;
				}
			}
		}
		else {
			switch (dartResult[i]) {
			case 'S':
				continue;
			case 'D':
				score[cursor] *= score[cursor];
				break;
			case 'T':
				score[cursor] = pow(score[cursor], 3);
				break;
			case '*':
				score[cursor] *= 2;
				if (cursor == 0) break;
				score[cursor - 1] *= 2;
				break;
			case '#':
				score[cursor] *= -1;
				break;
			}
		}
	}
	for (int i = 0; i < 3; i++)
		answer += score[i];
	return answer;
}