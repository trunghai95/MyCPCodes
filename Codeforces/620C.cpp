#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<pii> res;
set<int> cur;
int n, x, last;

int main()
{
    scanf("%d", &n);
    last = 1;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &x);
        if (cur.find(x) == cur.end())
        {
            cur.insert(x);
        }
        else
        {
            cur.clear();
            res.push_back(pii(last, i));
            last = i+1;
        }
    }

    scanf("%d", &x);
    if (cur.find(x) == cur.end())
    {
        if (!res.empty())
            res.back().second = n;
    }
    else
        res.push_back(pii(last, n));

    if (res.empty())
        printf("-1");
    else
    {
        printf("%d\n", res.size());
        for (int i = 0; i < res.size(); ++i)
            printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}
