#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int m, n, r[3], c[3], p[3], cnt, t, res;
bool ck[8][8];

bool valid(int x, int y) { return (x >= 0 && y >= 0 && x < m && y < n); }

int dist(int x1, int y1, int x2, int y2) { return abs(x1-x2) + abs(y1-y2); }

int bfs(int x, int y)
{
    int res=0, xt, yt;
    bool ck2[8][8];
    memcpy(ck2,ck,sizeof(ck));
    queue<pii> q;
    q.push(pii(x,y));
    ck2[0][1] = 1;
    while (!q.empty())
    {
        xt = q.front().first;
        yt = q.front().second;
        q.pop();
        ++res;
        if (valid(xt+1,yt) && !ck2[xt+1][yt])
        {
            q.push(pii(xt+1,yt));
            ck2[xt+1][yt] = 1;
        }
        if (valid(xt-1,yt) && !ck2[xt-1][yt])
        {
            q.push(pii(xt-1,yt));
            ck2[xt-1][yt] = 1;
        }
        if (valid(xt,yt+1) && !ck2[xt][yt+1])
        {
            q.push(pii(xt,yt+1));
            ck2[xt][yt+1] = 1;
        }
        if (valid(xt,yt-1) && !ck2[xt][yt-1])
        {
            q.push(pii(xt,yt-1));
            ck2[xt][yt-1] = 1;
        }
    }
    return res;
}

void proc(int step, int x, int y)
{
    if (step == t && x == 0 && y == 1)
    {
        ++res;
        return;
    }
    if ((x == 0 && y == 1) || step == t)
        return;

    for (int i = 0; i < 3; ++i)
    {
        if (step == p[i] && (x != r[i] || y != c[i]))
            return;
        if (x == r[i] && y == c[i] && step != p[i])
            return;
        if (step < p[i] && (p[i]-step < dist(r[i],c[i],x,y)))
            return;
    }

    ck[x][y] = 1;
    if (bfs(0,1) != (t-step))
    {
        ck[x][y] = 0;
        return;
    }
    if (valid(x+1,y) && !ck[x+1][y]) proc(step+1,x+1,y);
    if (valid(x-1,y) && !ck[x-1][y]) proc(step+1,x-1,y);
    if (valid(x,y+1) && !ck[x][y+1]) proc(step+1,x,y+1);
    if (valid(x,y-1) && !ck[x][y-1]) proc(step+1,x,y-1);
    ck[x][y] = 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cnt = 1;
    while (1)
    {
        scanf("%d %d", &m, &n);
        if (m == 0)
            return 0;
        res = 0;
        memset(ck,0,sizeof(ck));
        t = m*n;
        p[0] = t/4;
        p[1] = t/2;
        p[2] = 3*t/4;
        scanf("%d %d %d %d %d %d",r,c,r+1,c+1,r+2,c+2);
        proc(1,0,0);
        printf("Case %d: %d\n",cnt++,res);
    }
    return 0;
}
