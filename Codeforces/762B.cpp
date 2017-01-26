#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define F first
#define S second

const int MAXN = 300000;
int a[3], n;
pli x[MAXN+2];
char s[10];

int main() {
    for (int i = 0; i < 3; ++i)
        scanf("%d", a+i);
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld %s", &x[i].F, s);
        if (s[0] == 'U')
            x[i].S = 0;
        else
            x[i].S = 1;
    }

    sort(x, x+n);

    int res1 = 0;
    ll res2 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[x[i].S] > 0) {
            --a[x[i].S];
            ++res1;
            res2 += x[i].F;
        } else if (a[2] > 0) {
            --a[2];
            ++res1;
            res2 += x[i].F;
        }
    }

    printf("%d %lld\n", res1, res2);
    return 0;
}
