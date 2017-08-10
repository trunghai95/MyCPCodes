#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a, b;

int main() {
    scanf("%d", &n);

    while (n --> 0) {
        scanf("%lld %lld", &a, &b);
        ll lo = 1, hi = 1e6;

        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            if (mid * mid * mid < a*b) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        if (lo*lo*lo == a*b && a % lo == 0 && b % lo == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
