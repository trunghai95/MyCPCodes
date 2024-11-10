#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MAXN = 200005;
int n;
ll a[MAXN];

ll solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    ll res = a[0];
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        if (a[i] <= res) {
            continue;
        }
        ll sum = a[i] + res;
        if (sum % 2 == 0) {
            res = sum / 2;
        } else {
            res = sum / 2 + 1;
        }
    }
    return res;
}

int main() {
    int test;
    scanf("%d", &test);

    while (test --> 0) {
        printf("%lld\n", solve());
    }
    return 0;
}