#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, test;
ll a, cnt1, cnt2;

void solve() {
    scanf("%d", &n);
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a);
        if (a >= 2) {
            cnt2++;
            a -= 2;
        }
        cnt1 += a;
    }
    printf("%lld\n", cnt1/2 + cnt2/2);
}

int main() {
    scanf("%d", &test);
    while (test --> 0) {
        solve();
    }
    return 0;
}