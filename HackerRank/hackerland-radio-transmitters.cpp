#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100000;
int n;
ll k, x[MAXN+5];

int main() {
    scanf("%d %lld", &n, &k);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", x+i);
    sort(x+1, x+1+n);

    int i = 1;
    int res = 0;
    while (i <= n) {
        ++res;
        ll last = x[i];
        while (i <= n && x[i] - last <= k)
            ++i;
        if (i > n) {
            break;
        }
        --i;
        last = x[i];
        while (i <= n && x[i] - last <= k)
            ++i;
    }

    printf("%d\n", res);
    return 0;
}
