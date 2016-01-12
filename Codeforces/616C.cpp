#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n, m, sz[1005][1005];
char mp[1005][1005];
vector<int> s;

bool avail(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] == '.');
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", mp[i] + 1);

    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    if (mp[i][j] == '.' && sz[i][j] == 0)
    {
        queue<pii> q;
        q.push(pii(i,j));
        s.push_back(1);
        sz[i][j] = s.size();

        while (!q.empty())
        {
            pii u = q.front(); q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int xx = u.first + dx[i], yy = u.second + dy[i];
                if (avail(xx, yy) && sz[xx][yy] == 0)
                {
                    q.push(pii(xx,yy));
                    sz[xx][yy] = s.size();
                    ++s.back();
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        if (mp[i][j] == '*')
        {
            int rr = 1;
            set<int> st;
            for (int k = 0; k < 4; ++k)
            if (sz[i + dx[k]][j + dy[k]] > 0)
                st.insert(sz[i + dx[k]][j + dy[k]] - 1);

            for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
                rr += s[*it];
            rr %= 10;
            mp[i][j] = rr + '0';
        }
        printf("%s\n", mp[i]+1);
    }
    return 0;
}
