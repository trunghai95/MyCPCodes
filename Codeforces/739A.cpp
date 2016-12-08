#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int n, m, l, r, bound = 2e9;


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &l, &r);
        bound = min(bound, r-l);
    }
    ++bound;

    printf("%d\n", bound);
    for (int i = 0; i < n; ++i)
        printf("%d ", i % bound);
    printf("\n");
    return 0;
}
