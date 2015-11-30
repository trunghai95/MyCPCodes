#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 100000;
ll a[MAXN+1], mx[MAXN+1];
int t, n;

void init()
{
    a[0] = mx[0] = 0;
    a[1] = mx[1] = 1;
    for (int i = 2; i <= MAXN; ++i)
    {
        a[i] = a[i/2] + ((i&1) ? a[i/2 + 1] : 0);
        mx[i] = max(mx[i-1], a[i]);
    }
}

int main()
{
    init();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%lld\n", mx[n]);
    }
    return 0;
}
