#include <bits/stdc++.h>

using namespace std;

int n, m, a[1111], b[1111], s;

int main() {
    scanf("%d %d %d", &s, &n, &m);

    int res = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d", b+i);
    }

    for (int i = 0; i < n; ++i) 
    for (int j = 0; j < m; ++j) {
        if (a[i] + b[j] <= s) {
            res = max(res, a[i] + b[j]);
        }
    }

    printf("%d\n", res);
    return 0;
}
