#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll test, f, h, w, p[600], a[600];

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%lld", &test);
    while (test--)
    {
        scanf("%lld %lld %lld", &f, &h, &w);
        for (int i = 0; i < f; ++i)
            scanf("%lld", p+i);
        p[f] = w;
        sort(p, p+f+1);
        a[0] = p[0];
        for (ll i = 1; i <= f; ++i)
            a[i] = p[i] - p[i-1];
        sort(a, a+f+1);
        printf("%lld\n", a[0]*h);
    }
    return 0;
}
