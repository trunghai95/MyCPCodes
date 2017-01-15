#include <bits/stdc++.h>

using namespace std;

char s[10][10];

bool c(int x, int y) {
    if (x < 1 || y < 1 || x > 4 || y > 4) return false;
    return s[x][y] == 'x';
}

bool solve() {
    for (int i = 1; i <= 4; ++i)
    for (int j = 1; j <= 4; ++j)
    if (s[i][j] == '.') {
        if (c(i-1, j) && c(i-2, j)) return true;
        if (c(i-1, j) && c(i+1, j)) return true;
        if (c(i+1, j) && c(i+2, j)) return true;
        if (c(i, j-1) && c(i, j-2)) return true;
        if (c(i, j-1) && c(i, j+1)) return true;
        if (c(i, j+1) && c(i, j+2)) return true;
        if (c(i-1, j-1) && c(i+1, j+1)) return true;
        if (c(i+2, j+2) && c(i+1, j+1)) return true;
        if (c(i-1, j-1) && c(i-2, j-2)) return true;
        if (c(i-1, j+1) && c(i+1, j-1)) return true;
        if (c(i+2, j-2) && c(i+1, j-1)) return true;
        if (c(i-1, j+1) && c(i-2, j+2)) return true;
    }
    return false;
}

int main() {
    for (int i = 1; i <= 4; ++i)
        scanf("%s", s[i]+1);

    if (solve()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
