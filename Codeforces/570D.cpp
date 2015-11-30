#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
const int MAX = 5e5 + 7;
int n, m, p[MAX], depth[MAX], v, h, i;
pii dep[MAX]; // (depth,vertex)
char c[MAX];
map<int, map<int,int> > isC; // 1 no, 2 yes
char s[MAX];
pii* pp;

bool isChild(int &x, int &y)
{
    if (y == 1) return 1;
    if (depth[x] <= depth[y]) return 0;
    if (isC[x][y])
        return (isC[x][y] - 1);
    bool res = isChild(p[x], y);
    isC[x][y] = 1 + res;
    return res;
}

bool isPalin(char* s)
{
    int oddCnt = 0, l = strlen(s), cnt[26], tmp;
    memset(cnt,0,sizeof(cnt));
    for (int i = 0; i < l; ++i)
    {
        tmp = s[i] - 'a';
        ++cnt[tmp];
        if (cnt[tmp]&1)
            ++oddCnt;
        else
            --oddCnt;
    }
    return (oddCnt <= 1);
}

int main()
{
    memset(p,0,sizeof(p));
    memset(depth,0,sizeof(depth));
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    depth[1] = 1;
    dep[1] = pii(1,1);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d",p+i);
        depth[i] = depth[p[i]] + 1;
        isC[i][p[i]] = 2;
        dep[i].first = depth[i];
        dep[i].second = i;
    }
    sort(dep+1,dep+1+n);
    scanf("%s",c+1);
    for (int j = 0; j < m; ++j)
    {
        scanf("%d %d", &v, &h);
        if (depth[v] >= h)
        {
            printf("Yes\n");
            continue;
        }
        pp = lower_bound(dep+1,dep+1+n,pii(h,0));
        if (pp == dep+1+n)
        {
            printf("No\n");
            continue;
        }
        i = 0;
        while (pp < dep+1+n && pp->first == h)
        {
            if (isChild(pp->second,v))
                s[i++] = c[pp->second];
            ++pp;
        }
        s[i] = 0;
        if (isPalin(s))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
