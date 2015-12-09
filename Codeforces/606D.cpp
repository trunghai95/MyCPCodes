#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct Edge
{
    int w, id, onMST;
};

bool cmp(const Edge& x, const Edge& y)
{
    if (x.w == y.w) return x.onMST > y.onMST;
    return x.w < y.w;
}

int n, m;
Edge e[100010];
pii res[100010];
queue<int> q;

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    if (n == 2)
    {
        printf("1 2");
        return 0;
    }


    for (int i = 1; i <= m; ++i)
        scanf("%d %d", &e[i].w, &e[i].onMST), e[i].id = i;

    sort(e+1, e+1+m, cmp);

    if (!e[1].onMST || !e[2].onMST)
    {
        printf("-1");
        return 0;
    }

    res[e[1].id] = pii(1,2);
    res[e[2].id] = pii(1,3);
    int xx = 3;
    int lw = 2;
    q.push(3);
    for (int i = 3; i <= m; ++i)
    {
        if (e[i].onMST)
        {
            res[e[i].id] = pii(1,++xx);
            q.push(xx);
        }
        else
        {
            if (lw >= q.front())
                q.pop(), lw = 2;

            if (q.empty())
            {
                printf("-1");
                return 0;
            }

            res[e[i].id] = pii(lw, q.front());
            ++lw;
        }
    }

    for (int i = 1; i <= m; ++i)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}
