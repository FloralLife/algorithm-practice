#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

long long fact[21];
int x, y;

long long factorial(long long n) {
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}


long long combi(int cx, int cy) {
	return fact[cx + cy] / (fact[cx] * fact[cy]);
}

vector<int> find(int t) {
	vector<int> route;
	for (int i = 1; i <= x + y; i++)
		fact[i] = factorial(i);
	int cx, cy, cnt = 0;
	cx = cy = 0;
	while (1) {
		int com = combi(cx, cy);
		if (com == t) {
			for (int i = cx; i < x; i++) {
				route.push_back(0);
			}
			for (int i = cy; j < y; j++) {
				route.push_back(1);
			}
			return route;
		}
		else if (cnt + com < t) {
			cy++;
			route.push_back(1);
			cnt += com;
		}
	}
}


int main() {

}