#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const int MAXN = 100000;
int n;
ll a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a+i);
    sort(a, a+n);
    ll res = 1;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] <= i)
        {
            printf("0");
            return 0;
        }

        res *= (a[i] - i);
    }

    printf("%lld", res);
    return 0;
}
