#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt[20];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0, x; i < n; ++i)
    {
        scanf("%d", &x);
        ++cnt[x];
    }
    int res = 0;
    for (int i = 1; i <= m; ++i)
    for (int j = i + 1; j <= m; ++j)
        res += cnt[i] * cnt[j];

    printf("%d", res);
    return 0;
}
