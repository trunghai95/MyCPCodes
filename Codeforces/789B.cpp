#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
ll b, q, l, a;
int n;
set<ll> s;

int main() {
    scanf("%lld %lld %lld %d", &b, &q, &l, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a);
        s.insert(a);
    }

    if (abs(b) > l) {
        printf("0\n");
        return 0;
    }

    if (b == 0) {
        if (s.count(0)) {
            printf("0\n");
        } else {
            printf("inf\n");
        }
        return 0;
    }

    if (q == 0) {
        int res = 0;
        if (!s.count(b)) {
            ++res;
        }

        if (s.count(0)) {
            printf("%d\n", res);
        } else {
            printf("inf\n");
        }
        return 0;
    }

    if (q == 1) {
        if (s.count(b)) {
            printf("0\n");
        } else {
            printf("inf\n");
        }
        return 0;
    }

    if (q == -1) {
        if (s.count(b) && s.count(-b)) {
            printf("0\n");
        } else {
            printf("inf\n");
        }
        return 0;
    }

    int res = 0;

    while (true) {
        if (!s.count(b)) {
            ++res;
        }

        b = b * q;
        if (abs(b) > l) {
            break;
        }
    }

    printf("%d\n", res);
    return 0;
}
