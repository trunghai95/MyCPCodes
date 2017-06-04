#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int test, n, a[MAXN+2];

bool solve() {
    if (n % 2 == 0 || a[0] != 1 || a[n-1] != 1) {
        return false;
    }

    for (int i = 1, j = n - 2; i <= j; ++i, --j) {
        if (a[i] != a[j]) return false;
        if (a[i] != a[i-1] + 1) return false;
    }

    return true;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", a+i);
        }

        printf("%s\n", solve()?"yes":"no");
    }
    return 0;
}
