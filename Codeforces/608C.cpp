//WA
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef pair<int,int> pii;

pii b[100010];
int f[100010];
int n;

int main()
{
    scanf("%d", &n);
    if (n == 1)
    {
        printf("0");
        return 0;
    }

    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &b[i].F, &b[i].S);

    sort(b+1, b+1+n);

    int res = 1;
    f[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        int tmp = b[i].F - b[i].S;
        tmp = lower_bound(b+1, b+1+i, pii(tmp, 0)) - b;
        f[i] = f[tmp - 1] + 1;
        res = max(res, f[i]);
    }

    printf("%d", n - res);

    return 0;
}
