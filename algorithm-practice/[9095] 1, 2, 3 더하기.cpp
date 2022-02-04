#include <iostream>
using namespace std;

int main() {
    int T, n, i = 3;
    int d[11] = { 1, 2, 4 };
    cin >> T;
    while (T--) {
        cin >> n;
        if (n > i) {
            for (int j = i; j < n; j++, i++) {
                d[i] = d[i - 1] + d[i - 2] + d[i - 3];
            }
        }
        cout << d[n - 1] << endl;
    }
}