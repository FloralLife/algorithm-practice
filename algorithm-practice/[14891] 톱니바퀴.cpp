#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;

bool gear[4][8];
bool visit[4];

void rotate(int n, int d) {
    int temp;
    switch (d) {
    case 1:
        temp = gear[n][7];
        for (int i = 7; i > 0; i--) {
            gear[n][i] = gear[n][i - 1];
        }
        gear[n][0] = temp;
        break;

    case -1:
        temp = gear[n][0];
        for (int i = 0; i < 7; i++) {
            gear[n][i] = gear[n][i + 1];
        }
        gear[n][7] = temp;
        break;
    }
}

void move(int n, int d) {
    visit[n] = true;
    bool left = false, right = false;

    if (n - 1 >= 0 && !visit[n - 1])
        if (gear[n - 1][2] != gear[n][6])
            left = true;

    if (n + 1 <= 3 && !visit[n + 1])
        if (gear[n][2] != gear[n + 1][6])
            right = true;

    rotate(n, d);

    if (left)
        move(n - 1, d * -1);

    if (right)
        move(n + 1, d * -1);
}

int main() {
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1d", &gear[i][j]);
        }
    }
    int K, n, d;
    cin >> K;
    for (int i = 0; i < K; i++) {
        memset(visit, false, sizeof(visit));
        cin >> n >> d;
        move(n - 1, d);
    }
    for (int i = 0; i < 4; i++) {
        if (gear[i][0]) {
            ans += pow(2, i);
        }
    }
    cout << ans;
}