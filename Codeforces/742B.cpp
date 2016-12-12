#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, x, a;
ll cnt[200000], res;

int main() {
    scanf("%d %d", &n, &x);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        res += cnt[a^x];
        ++cnt[a];
    }

    printf("%lld\n", res);
    return 0;
}
