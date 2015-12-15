#include <bits/stdc++.h>

using namespace std;

bool elsie[100001];
int n;

int main()
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0, x; i < n; ++i)
    {
        scanf("%d", &x);
        elsie[x] = true;
    }

    int i = 1, j = 1, res = 0;
    n <<= 1;

    while (1)
    {
        while (i <= n && !elsie[i]) ++i;
        if (i > n) break;

        if (j <= i) j = i+1;
        while (j <= n && elsie[j]) ++j;
        if (j > n) break;
        else ++res, ++j;
        ++i;
    }

    printf("%d", res);
    return 0;
}
