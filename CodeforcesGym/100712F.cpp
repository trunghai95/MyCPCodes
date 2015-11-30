#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef pair<int,int> pii;
const int MAX = 1e5 + 7;
int n, t, m, label[MAX], cnt, res;
pair<int,pii> edge[MAX];

int findSet(int x) { return label[x] == x ? x : (label[x] = findSet(label[x])); }
bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }
void unionSet(int x, int y) { label[findSet(x)] = findSet(y); }

int main()
{
    freopen("in.txt","r",stdin);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            label[i] = i;
        for (int i = 0; i < m; ++i)
            cin >> edge[i].S.F >> edge[i].S.S >> edge[i].F;
        sort(edge,edge+m);
        for (int i = 0, cnt = 0; i < m; ++i)
        if (!isSameSet(edge[i].S.F,edge[i].S.S))
        {
            ++cnt;
            unionSet(edge[i].S.F,edge[i].S.S);
            res = edge[i].F;
            if (cnt == n-1) break;
        }
        cout << res << endl;
    }
    return 0;
}
