#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int m, n, x, y, res;
char mp[30][30], l, w;
pii direct[] = {pii(1,0),pii(0,1),pii(-1,0),pii(0,-1)};

int floodFill(int r, int c, char c1, char c2)
{
    if (r < 0 || r >= m) return 0;
    if (c < 0) c += n;
    if (c >= n) c %= n;
    if (mp[r][c] != c1) return 0;
    int res = 1;
    mp[r][c] = c2;
    for (int i = 0; i < 4; ++i)
    {
        res += floodFill(r+direct[i].first,c+direct[i].second, c1, c2);
    }
    return res;
}

int main()
{
    freopen("in.txt","r",stdin);
    while (!cin.eof())
    {
        res = 0;
        cin >> m >> n;
        for (int i = 0; i < m; ++i)
            cin >> mp[i];
        cin >> x >> y;
        l = mp[x][y];
        w = l-1;
        floodFill(x,y,l,w);
        for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            res = max(res,floodFill(i,j,l,w));
        cout << res << endl;
    }
    return 0;
}
