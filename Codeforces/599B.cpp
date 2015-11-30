#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;

struct Farr
{
    int val, id;
};

bool cmp(const Farr& x, const Farr&y)
{
    return x.val < y.val;
}

Farr f[MAX];
int a[MAX], n, m;

int main()
{
    scanf("%d %d", &n, &m);
    f[0].val = -100;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &f[i].val);
        f[i].id = i;
    }

    sort(f+1, f+1+n, cmp);

    bool flag = 0;
    for (int i = 1; i <= m; ++i)
    {
        Farr tmp;
        scanf("%d", &tmp.val);
        tmp.id = -100;
        int pos = lower_bound(f+1, f+1+n, tmp, cmp) - f;

        if (pos > n || f[pos].val != tmp.val)
        {
            printf("Impossible");
            return 0;
        }

        if (f[pos + 1].val == tmp.val || f[pos - 1].val == tmp.val)
        {
            flag = 1;
        }

        a[i] = f[pos].id;
    }

    if (flag)
    {
        printf("Ambiguity");
        return 0;
    }

    printf("Possible\n");
    for (int i = 1; i <= m; ++i)
        printf("%d ", a[i]);
    return 0;
}
