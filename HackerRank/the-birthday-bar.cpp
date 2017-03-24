#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;
int n, m, d, a[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    scanf("%d %d", &d, &m);

    int res = 0;

    for (int i = 1; i <= n - m + 1; ++i) {
        int sum = 0;

        for (int j = i; j <= i + m - 1; ++j) {
            sum += a[j];
        }

        if (sum == d) {
            ++res;
        }
    }

    printf("%d\n", res);
    return 0;
}
