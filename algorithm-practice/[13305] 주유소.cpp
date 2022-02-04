#include <iostream>
using namespace std;

long long oil[100000], road[100000], answer = 0;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> road[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> oil[i];
    }
    int cheap = 2000000000;
    for (int i = 0; i < N - 1; i++) {
        if (cheap > oil[i]) cheap = oil[i];
        answer += road[i] * cheap;
    }
    cout << answer;
}