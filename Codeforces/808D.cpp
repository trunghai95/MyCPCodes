#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int n;
ll a[MAXN+2], s[MAXN+2], goal;

int find(ll g, int lo, int hi) {
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (s[mid] < g) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return lo;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
        s[i] = s[i-1] + a[i];
    }

    if (s[n]&1) {
        printf("NO\n");
        return 0;
    }

    goal = s[n]/2;

    int p = find(goal, 1, n);

    if (s[p] == goal) {
        printf("YES\n");
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        p = find(goal + a[i], i, n);
        if (s[p] == goal + a[i]) {
            printf("YES\n");
            return 0;
        }
        if (i > 1) {
            p = find(goal - a[i], 1, i-1);
            if (s[p] == goal - a[i]) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}
