#include <bits/stdc++.h>

using namespace std;

int n, a, mx, mn, rmx, rmn;

int main() {
    scanf("%d %d", &n, &a);
    mx = mn = a;

    for (int i = 1; i < n; ++i) {
        scanf("%d", &a);
        if (a > mx) {
            mx = a;
            ++rmx;
        }

        if (a < mn) {
            mn = a;
            ++rmn;
        }
    }

    printf("%d %d\n", rmx, rmn);
    return 0;
}
