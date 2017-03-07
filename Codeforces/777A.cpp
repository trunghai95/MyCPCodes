#include <bits/stdc++.h>

using namespace std;

int n, x;
int lol[3][6] = {{0, 1, 2, 2, 1, 0}, {1, 0, 0, 1, 2, 2}, {2, 2, 1, 0, 0, 1}};

int main() {
    cin >> n >> x;
    n %= 6;

    for (int i = 0; i < 3; ++i) {
        if (lol[i][n] == x) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}
