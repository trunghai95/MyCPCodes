#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, k, a, m, i, x, sum;
set<pii> seg;

int main()
{
    scanf("%d %d %d %d", &n, &k, &a, &m);
    seg.insert(pii(n, 1));
    sum = (n+1)/(a+1);

    for (i = 0; i < m && sum >= k; ++i)
    {
        scanf("%d", &x);
        set<pii>::iterator it = seg.lower_bound(pii(x, -1));
        int l = (*it).second, r = (*it).first;
        seg.erase(it);
        sum -= (r - l + 2)/(a+1);
        if (x - 1 >= l)
        {
            sum += (x - l + 1)/(a+1);
            seg.insert(pii(x-1, l));
        }
        if (x + 1 <= r)
        {
            sum += (r - x + 1)/(a+1);
            seg.insert(pii(r, x+1));
        }
    }

    if (sum >= k)
        printf("-1");
    else
        printf("%d", i);
    return 0;
}