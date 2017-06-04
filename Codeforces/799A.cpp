#include <bits/stdc++.h>

using namespace std;

int n, t, k, d;

int main() {
    scanf("%d %d %d %d", &n, &t, &k, &d);

    int r1 = (n - 1) / k + 1;
    r1 = r1 * t;

    int tmp = (d - 1) / t + 1;
    n -= tmp * k;
    // cout << n << '\n';
    if (n <= 0) {
        cout << "NO\n";
        return 0;
    }
    if (d % t != 0) {
        n += k;
    }
    int r2 = (n - 1) / (k*2) + 1;
    r2 = r2 * t + d;

    // cout << r1 << ' ' << r2 << '\n';

    if (r2 < r1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
