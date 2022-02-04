#include <string>
#include <vector>

using namespace std;

int map[16];

string toBinary(int n, int num) {
	string line = "";

	for (int i = 0; i < n; i++) {
		if (num == 0) {
			line = '0' + line;
		}
		else if (num % 2) {
			line = '1' + line;
			num /= 2;
		}
		else {
			line = '0' + line;
			num /= 2;
		}
	}
	for (int i = 0; i < n; i++) {
		if (line[i] == '1')
			line[i] = '#';
		else line[i] = ' ';
	}
	return line;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		map[i] = arr1[i] | arr2[i];
		answer.push_back(toBinary(n, map[i]));
	}
	return answer;
}