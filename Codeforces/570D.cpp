#include <bits/stdc++.h>

using namespace std;

#define MAXN 500000
#define MAXLOG 19

int n, m, p[MAXN+1][MAXLOG+1], cnt[MAXN+1][MAXLOG+1][26], h[MAXN+1];
int ppow[MAXLOG+1], res[26];
vector<int> child[MAXN+1][MAXLOG+1];
char s[MAXN+2];

void init()
{
    memset(p, -1, sizeof(p));
    ppow[0] = 1;
    for (int i = 1; i <= MAXLOG; ++i)
        ppow[i] = ppow[i-1] * 2;
}

void dfs(int v, int u = -1)
{
    if (u != -1)
        h[v] = h[u] + 1;
    for (int i = 1; i <= MAXLOG; ++i)
    if (p[v][i-1] != -1)
    {
        p[v][i] = p[p[v][i-1]][i-1];
        child[p[v][i]][i].push_back(v);
        ++cnt[p[v][i]][i][s[v]-'a'];
    }
    else break;

    for (int i = 0; i < (int)child[v][0].size(); ++i)
        dfs(child[v][0][i], v);
}

bool solve(int vv, int hh)
{
    memset(res, 0, sizeof(res));
    hh -= h[vv];
    if (hh <= 0)
        return true;
    vector<int> q;
    q.push_back(vv);
    while (!q.empty())
    {
        int i = MAXLOG;
        while (ppow[i] > hh) --i;
        if (ppow[i] == hh)
        {
            for (int j = 0; j < (int)q.size(); ++j)
            for (int k = 0; k < 26; ++k)
                res[k] += cnt[q[j]][i][k];
            break;
        }
        vector<int> tmp;
        for (int j = 0; j < (int)q.size(); ++j)
        for (int k = 0; k < (int)child[q[j]][i].size(); ++k)
            tmp.push_back(child[q[j]][i][k]);
        q = tmp;
    }

    int cc = 0;
    for (int i = 0; i < 26; ++i)
        cc += (res[i]&1);

    return (cc <= 1);
}

int main()
{
    init();
    scanf("%d %d", &n, &m);

    for (int i = 2; i <= n; ++i)
        scanf("%d", p[i]);

    scanf("%s", s+1);

    for (int i = 2; i <= n; ++i)
    {
        child[p[i][0]][0].push_back(i);
        ++cnt[p[i][0]][0][s[i]-'a'];
    }

    h[1] = 1;
    dfs(1);

    int vv, hh;

    while (m--)
    {
        scanf("%d %d", &vv, &hh);
        if (solve(vv, hh))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}