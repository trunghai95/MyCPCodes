#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 40;
int n;
ll a[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
    }

    sort(a+1, a+1+n);

    ll co = 1, res = 0;

    for (int i = n; i >= 1; --i) {
        res += co * a[i];
        co *= 2;
    }

    printf("%lld\n", res);
    return 0;
}
