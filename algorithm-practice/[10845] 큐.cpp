#include <iostream>
#include <string.h>
using namespace std;

class MyQueue {
private:
	int arr[10000];
	int in = 0, out = 0;
public:
	void push(int num) { arr[in++] = num; }

	void pop() {
		if (empty()) cout << -1 << endl;
		else cout << arr[out++] << endl;
	}

	void size() { cout << in - out << endl; }

	bool empty() { return in == out; }

	void front() {
		if (empty()) cout << -1 << endl;
		else cout << arr[out] << endl;
	}

	void back() {
		if (empty()) cout << -1 << endl;
		else cout << arr[in - 1] << endl;
	}
};

int main() {
	int N;
	MyQueue myQueue;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char str[15];
		scanf("%s", &str);
		if (strcmp(str, "push") == 0) {
			int n;
			cin >> n;
			myQueue.push(n);
		}
		else if (strcmp(str, "pop") == 0) {
			myQueue.pop();
		}
		else if (strcmp(str, "size") == 0) {
			myQueue.size();
		}
		else if (strcmp(str, "empty") == 0) {
			cout << myQueue.empty() << endl;
		}
		else if (strcmp(str, "front") == 0) {
			myQueue.front();
		}
		else if (strcmp(str, "back") == 0) {
			myQueue.back();
		}
	}
}