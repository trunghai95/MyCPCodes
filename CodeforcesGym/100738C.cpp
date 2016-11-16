#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100000;
int n;
ll d, a[MAXN+5], res;

int main() {
    scanf("%d %lld", &n, &d);
    d <<= 1;

    for (int i = 0; i < n; ++i) {
        scanf("%lld", a+i);
    }

    for (int i = 1; i < n; ++i)
    if (a[i] >= a[i-1]) {
        ll dif = a[i] - a[i-1];
        res += dif / d + 1;
    }

    printf("%lld\n", res);
    return 0;
}
