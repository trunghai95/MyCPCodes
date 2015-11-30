#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int n, m, s, cd, res;
char mp[111][111], in[50007];
pii direct[] = {pii(-1,0), pii(0,1), pii(1,0), pii(0,-1)}, cp, tmp;

bool checkPos(pii x) { return x.first >= 0 && x.second >= 0 && x.first < n && x.second < m && mp[x.first][x.second] != '#'; }

int main()
{
    freopen("in.txt","r",stdin);
    while (1)
    {
        cin >> n >> m >> s;
        if (n == 0)
            return 0;
        res = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> mp[i];
            for (int j = 0; j < m; ++j)
            {
                switch(mp[i][j])
                {
                case 'N': cp = pii(i,j); cd = 0; mp[i][j] = '.'; break;
                case 'S': cp = pii(i,j); cd = 2; mp[i][j] = '.'; break;
                case 'L': cp = pii(i,j); cd = 1; mp[i][j] = '.'; break;
                case 'O': cp = pii(i,j); cd = 3; mp[i][j] = '.'; break;
                }
            }
        }
        cin >> in;
        for (int i = 0; i < s; ++i)
        {
            switch(in[i])
            {
            case 'D':
                cd = (cd + 1) % 4;
                break;
            case 'E':
                cd = (cd + 3) % 4;
                break;
            case 'F':
                tmp.first = cp.first + direct[cd].first;
                tmp.second = cp.second + direct[cd].second;
                if (checkPos(tmp))
                {
                    cp = tmp;
                    if (mp[tmp.first][tmp.second] == '*')
                    {
                        ++res;
                        mp[tmp.first][tmp.second] = '.';
                    }
                }
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}
