#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1003;
int n, c[MAXN][MAXN], res[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        res[i] = 1;
        for (int j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (i != j) {
                if (c[i][j] > c[1][1]) {
                    if (i > j) {
                        res[i]++;
                    }
                } else {
                    if (i < j) {
                        res[i]++;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}