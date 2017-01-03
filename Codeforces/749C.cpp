#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
char s[MAXN+5];
int f[MAXN+5][2], n, cnt[2];

int main() {
    scanf("%d %s", &n, s+1);

    for (int i = n-1; i >= 0; --i) {
        if (s[i+1] == 'D') {
            ++cnt[0];
            f[i][0] = i+1;
            f[i][1] = f[i+1][1];
        } else if (s[i+1] == 'R') {
            ++cnt[1];
            f[i][0] = f[i+1][0];
            f[i][1] = i+1;
        }
    }

    f[n][0] = f[0][0];
    f[n][1] = f[0][1];
    for (int i = n-1; i >= 0; --i) {
        if (f[i][0] == 0) {
            f[i][0] = f[i+1][0];
        }
        if (f[i][1] == 0) {
            f[i][1] = f[i+1][1];
        }
    }

    int i = 1, j, k;
    while (cnt[0] && cnt[1]) {
        if (s[i] == 'D') {
            j = f[i][1];
            while (s[j] != 'R') {
                k = f[j][1];
                f[j][1] = f[k][1];
                j = k;
            }
            --cnt[1];
            s[j] = '.';
            f[i][1] = f[j][1];
        } else if (s[i] == 'R') {
            j = f[i][0];
            while (s[j] != 'D') {
                k = f[j][0];
                f[j][0] = f[k][0];
                j = k;
            }
            --cnt[0];
            s[j] = '.';
            f[i][0] = f[j][0];
        }
        if (++i > n) i = 1;
    }

    if (!cnt[0]) {
        printf("R\n");
        return 0;
    }

    if (!cnt[1]) {
        printf("D\n");
        return 0;
    }
    return 0;
}
