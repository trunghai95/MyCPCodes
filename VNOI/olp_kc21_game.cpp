#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 500005;
int n, a[MAXN], premin[MAXN], sufmin[MAXN];
ll res, sum;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    premin[0] = a[0];
    for (int i = 1; i < n; i++) {
        premin[i] = min(premin[i-1], a[i]);
    }

    sufmin[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        sufmin[i] = min(sufmin[i+1], a[i]);
    }

    for (int i = 0; i < n; i++) {
        sum += premin[i];
        res += sufmin[i];
    }
    res = max(res, sum);
    printf("%lld\n", res);
    return 0;
}