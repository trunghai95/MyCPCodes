#include <bits/stdc++.h>

using namespace std;

const int N = 5009, z = 5000;
int  t, n, m, f[N][N], llog[N], tt;

int Log(int x) {
    int cnt = 0;
    while (x) cnt++, x /= 2;
    return cnt;
}

void init() {
    for (int i=1;i<=z;i++) llog[i] = Log(i);
    for (int i=1;i<=z;i++)
        for (int j=1;j<=z;j++) f[i][j] = z;

    for (int i=1;i<=z;i++) f[1][i] = i;
    for (int i=2;i<=z;i++) {
        for (int j=1;j<=z;j++) {
            if (i > llog[j]) f[i][j] = f[i-1][j];
            else
            for (int k=2;k<=j;k++)
                f[i][j] = min(f[i][j], max(f[i-1][k-1], f[i][j-k])+1);
        }
    }
}

int main() {
    init();
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", f[n][m]);
    }

    return 0;
}
