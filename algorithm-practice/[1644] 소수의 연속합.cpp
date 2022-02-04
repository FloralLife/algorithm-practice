#include <iostream>
#include <vector>
#include <math.h>
#include <bitset>

using namespace std;

int N, answer;
vector<int> prime;
bitset<4000001> notPrime;


void findPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (notPrime[i]) continue;
		for (int j = i * 2; j <= n; j += i) {
			notPrime.set(j);
		}
	}
}

int main() {
	cin >> N;
	int l = 0, r = 0, sum = 0, answer = 0;
	findPrime(N);
	for (int i = 2; i <= N; i++) {
		if (!notPrime[i]) {
			prime.push_back(i);
			sum += prime[r++];
			while (sum >= N) {
				if (sum == N) answer++;
				sum -= prime[l++];
			}
		}
	}
	cout << answer;
}