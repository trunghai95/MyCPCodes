#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n, m;
int p[MAXN + 1];

bool cmp(const int& x, const int& y) { return x > y; }

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &p[i]);

    sort(p+1, p+1+m, cmp);

    int resprice = -1, ressum = -1;
    int tt = min(n, m);
    for (int i = 1; i <= tt; ++i)
    {
        int tmp = p[i] * i;
        if (tmp > ressum)
        {
            ressum = tmp;
            resprice = p[i];
        }
    }

    printf("%d %d", resprice, ressum);
    return 0;
}
