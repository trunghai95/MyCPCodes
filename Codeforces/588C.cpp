#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 20;
int n, cnt[maxn], w;

int main()
{
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0, x; i < n; ++i)
    {
        scanf("%d", &x);
        ++cnt[x];
    }

    int res = 0;
    for (int i = 0; i < maxn; ++i)
    if (cnt[i])
    {
        cnt[i+1] += (cnt[i] >> 1);
        res += (cnt[i] & 1);
    }

    printf("%d", res);
    return 0;
}
