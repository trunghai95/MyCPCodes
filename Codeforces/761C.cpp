#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int n, m, a[MAXN+2][3], res;
char s[MAXN+2];

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isChar(char c) {
    return c >= 'a' && c <= 'z';
}

void Try(int i, int j, int k) {
    if (a[i][0] == -1 || a[j][1] == -1 || a[k][2] == -1)
        return;
    res = min(res, a[i][0] + a[j][1] + a[k][2]);
}

int main() {
    scanf("%d %d", &n, &m);

    res = 2e9;

    memset(a, -1, sizeof(a));
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < m; ++j) {
            if (isDigit(s[j])) {
                if (a[i][0] == -1) {
                    a[i][0] = min(j, m - j);
                } else {
                    a[i][0] = min(a[i][0], min(j, m-j));
                }
            } else if (isChar(s[j])) {
                if (a[i][1] == -1) {
                    a[i][1] = min(j, m - j);
                } else {
                    a[i][1] = min(a[i][1], min(j, m-j));
                }
            } else {
                if (a[i][2] == -1) {
                    a[i][2] = min(j, m - j);
                } else {
                    a[i][2] = min(a[i][2], min(j, m-j));
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
    for (int k = 0; k < n; ++k)
    if (i != j && j != k && i != k) {
        Try(i, j, k);
    }

    printf("%d\n", res);
    return 0;
}
