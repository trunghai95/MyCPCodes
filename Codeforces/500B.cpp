#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;
int n, a[MAXN+2];
char s[MAXN+2][MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    for (int i = 1; i <= n; ++i)
        scanf("%s", s[i]+1);

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    if (s[i][j] == '1') {
        for (int k = 1; k <= n; ++k)
        if (k != i && k != j && (s[i][k] == '1' || s[j][k] == '1')) {
            s[i][k] = s[k][i] = s[j][k] = s[k][j] = '1';
        }
    }

    for (int i = 1; i <= n; ++i)
    for (int j = i+1; j <= n; ++j) {
        if (s[i][j] == '1' && a[i] > a[j])
            swap(a[i], a[j]);
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
