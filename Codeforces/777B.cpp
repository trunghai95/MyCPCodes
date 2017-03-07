#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n;
char a[MAXN+2], b[MAXN+2];

int solve1() {
    int i = 1, j = 1, res = 0;

    while (i <= n) {
        while (j <= n && b[j] < a[i]) {
            ++j;
        }

        if (j <= n) {
            ++res;
        } else {
            break;
        }

        ++i;
        ++j;
    }

    return n - res;
}

int solve2() {
    int i = 1, j = 1, res = 0;

    while (i <= n) {
        while (j <= n && b[j] <= a[i]) {
            ++j;
        }

        if (j <= n) {
            ++res;
        } else {
            break;
        }

        ++i;
        ++j;
    }

    return res;
}

int main() {
    scanf("%d %s %s", &n, a+1, b+1);
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);

    printf("%d\n%d\n", solve1(), solve2());
    return 0;
}
