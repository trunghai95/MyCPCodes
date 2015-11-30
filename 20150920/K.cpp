#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define F first
#define S second

int test, r, c, res;
char s[11];
bool g[10][10], ck[40000000];
pii p;

struct Node
{
    int id, dist;
    bool s[10][10];

    bool isGoal()
    {
        for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (g[i][j] != s[i][j]) return 0;
        return 1;
    }
};

bool checkPos(pii &p)
{
    return (g[p.F][p.S] && g[p.F][p.S+1] && g[p.F][p.S-1] && g[p.F+1][p.S] && g[p.F-1][p.S]);
}

void color(bool s[10][10], pii &p)
{
    s[p.F][p.S] = s[p.F][p.S+1] = s[p.F][p.S-1] = s[p.F+1][p.S] = s[p.F-1][p.S] = 1;
}

int encode(int x, int y) { return (x-3)*(r-4) + y - 3; }
pii decode(int x) { return pii((x+1)/(c-4) + ((x+1)%(c-4) != 0) + 2, x%(c-4) + 3); }

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &test);

    for (int ii = 1; ii <= test; ++ii)
    {
        scanf("%d %d", &r, &c);
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= r; ++i)
        {
            scanf("%s", s+1);
            for (int j = 1; j <= c; ++j)
                g[i][j] = (s[j] == '#');
        }

        if (g[1][1] || g[1][c] || g[r][1] || g[r][c])
        {
            printf("Image #%d: impossible\n\n", ii);
            continue;
        }

        if (c < 3 || r < 3)
        {
            bool f = 1;
            for (int i = 1; i <= r && f; ++i)
            for (int j = 1; j <= c; ++j)
                if (g[i][j]) { f = 0; break; }

            if (f) printf("Image #%d: 0\n\n", ii);
            else printf("Image #%d: impossible\n\n", ii);

            continue;
        }

        Node s;
        s.id = 0;
        s.dist = 0;
        memset(s.s, 0, sizeof(s.s));

        for (int i = 2; i < r && s.dist != -1; ++i)
        {
            if (g[i][1] && !s.s[i][1])
            {
                if (g[i][2] && g[i][3] && g[i-1][2] && g[i+1][2])
                    s.s[i][1] = s.s[i][2] = s.s[i][3] = s.s[i-1][2] = s.s[i+1][2] = 1, ++s.dist;
                else s.dist = -1;
            }

            if (g[i][c] && !s.s[i][c])
            {
                if (g[i][c-1] && g[i][c-2] && g[i-1][c-1] && g[i+1][c-1])
                    s.s[i][c] = s.s[i][c-1] = s.s[i][c-2] = s.s[i-1][c-1] = s.s[i+1][c-1] = 1, ++s.dist;
                else s.dist = -1;
            }
        }

        for (int i = 2; i < c && s.dist != -1; ++i)
        {
            if (g[1][i] && !s.s[1][i])
            {
                if (g[2][i] && g[3][i] && g[2][i-1] && g[2][i+1])
                    s.s[1][i] = s.s[2][i] = s.s[3][i] = s.s[2][i-1] = s.s[2][i+1] = 1, ++s.dist;
                else s.dist = -1;
            }

            if (g[r][i] && !s.s[r][i])
            {
                if (g[r-1][i] && g[r-2][i] && g[r-1][i-1] && g[r-1][i+1])
                    s.s[r][i] = s.s[r-1][i] = s.s[r-2][i] = s.s[r-1][i-1] = s.s[r-1][i+1] = 1, ++s.dist;
                else s.dist = -1;
            }
        }

        if (s.isGoal())
        {
            printf("Image #%d: %d\n\n", ii, s.dist);
            continue;
        }
        else if (s.dist == -1 || c == 3 || r == 3)
        {
            printf("Image #%d: impossible\n\n", ii);
            continue;
        }

        int bNum = (r-4)*(c-4);
        memset(ck, 0, sizeof(ck));
        ck[0] = 1;
        queue<Node> q;
        q.push(s);
        res = -1;

        while (!q.empty() && res == -1)
        {
            Node u = q.front(); q.pop();

            for (int i = 0; i < bNum; ++i)
            {
                if (!(u.id & (1 << i)) && !ck[u.id | (1<<i)])
                {
                    p = decode(i);
                    if (checkPos(p))
                    {
                        Node tmp = u;
                        tmp.dist = u.dist + 1;
                        tmp.id |= 1<<i;
                        color(tmp.s, p);
                        if (tmp.isGoal()) { res = tmp.dist; break; }
                        q.push(tmp);
                        ck[tmp.id] = 1;
                    }
                }
            }
        }

        if (res == -1) printf("Image #%d: impossible\n\n", ii);
        else printf("Image #%d: %d\n\n", ii, res);
    }
    return 0;
}
