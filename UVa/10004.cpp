#include <bits/stdc++.h>

using namespace std;

int n, l, adjMat[200][200], c[200], x, y, f;
queue<int> q;

int main()
{
    while (1)
    {
        cin >> n;
        if (!n) return 0;
        cin >> l;
        f = 1;
        q = queue<int>();
        memset(adjMat,0,sizeof(adjMat));
        memset(c,-1,sizeof(c));
        for (int i = 0; i < l; ++i)
        {
            cin >> x >> y;
            adjMat[x][y] = adjMat[y][x] = 1;
        }
        q.push(0);
        while (!q.empty())
        {
            x = q.front(); q.pop();
            for (int i = 0; i < n; ++i)
            if (adjMat[x][i])
            {
                if (c[i] == -1)
                {
                    c[i] = 1 - c[x];
                    q.push(i);
                }
                else if (c[i] == c[x])
                {
                    f = 0;
                    break;
                }
            }
            if (!f) break;
        }
        if (f) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}
