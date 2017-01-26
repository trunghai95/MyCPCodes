#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int n, p[MAXN+2], res[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", p+i);
    for (int i = 1; i <= n; ++i)
        res[p[p[i]]] = i;

    for (int i = 1; i <= n; ++i)
        printf("%d\n", res[i]);
    return 0;
}
