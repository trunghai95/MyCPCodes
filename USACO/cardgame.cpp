#include <bits/stdc++.h>

using namespace std;

int n;
int elsie[50001];
int bessie[50001];
bool ck[100001];

bool cmpngc(const int& x, const int& y) { return x > y; }

int main()
{
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", elsie+i), ck[elsie[i]] = true;;

    int m = 0;
    for (int i = (n << 1); i >= 1; --i)
    if (!ck[i]) bessie[++m] = i;

    sort(elsie+1, elsie+1+(n>>1));
    sort(bessie+1, bessie+1+(n>>1));
    sort(elsie+1+(n>>1), elsie+n+1, cmpngc);
    sort(bessie+1+(n>>1), bessie+n+1, cmpngc);

    int res = 0;
    int i = 1, j = 1;

    while (i <= (n >> 1) && j <= (n >> 1))
    {
        while (j <= (n >> 1) && bessie[j] < elsie[i]) ++j;
        if (j <= (n >> 1)) ++res, ++j;
        ++i;
    }

    i = j = (n >> 1) + 1;
    while (i <= n && j <= n)
    {
        while (j <= n && bessie[j] > elsie[i]) ++j;
        if (j <= n) ++res, ++j;
        ++i;
    }

    printf("%d", res);

    return 0;
}
