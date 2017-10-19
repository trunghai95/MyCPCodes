#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;
int test, n, a[MAXN+2];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);
        n *= 3;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
        }
        sort(a+1, a+1+n);

        int i = 1, j = n;

        while (i < j) {
            res += a[j-1];
            j -= 2;
            ++i;
        }

        printf("%d\n", res);
    }
    return 0;
}
