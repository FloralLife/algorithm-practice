#include <iostream>
using namespace std;

int N;
int a[100], b[100];

void minHeapify(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int child = i;
		while (child > 0) {
			int parent = (child - 1) / 2;
			int root = parent;
			if (arr[root] > arr[child]) {
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			child = root;
		}
	}
}
void maxHeapify(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int child = i;
		while (child > 0) {
			int parent = (child - 1) / 2;
			int root = parent;
			if (arr[root] < arr[child]) {
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			child = root;
		}
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		cin >> b[i];

	maxHeapify(a, N);
	for (int i = N - 1; i >= 0; i--) {
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		maxHeapify(a, i);
	}

	minHeapify(b, N);
	for (int i = N - 1; i >= 0; i--) {
		int temp = b[i];
		b[i] = b[0];
		b[0] = temp;
		minHeapify(b, i);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += a[i] * b[i];
	}
	cout << ans;

	return 0;
}