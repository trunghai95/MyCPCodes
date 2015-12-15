#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

struct Room
{
    bool on, visited;
    vector<pii> lit;
    Room(): on(false), visited(false) {}
};

Room r[101][101];
bool visited[101][101];
int n, m, x, y, a, b;

bool valid(int xx, int yy) { return (xx > 0 && xx <= n && yy > 0 && yy <= n); }

int main()
{
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> a >> b;
        r[x][y].lit.push_back(pii(a,b));
    }

    r[1][1].on = true;
    for (int i = 0; i < r[1][1].lit.size(); ++i)
        r[r[1][1].lit[i].first][r[1][1].lit[i].second].on = true;

    while (1)
    {
        memset(visited, 0, sizeof(visited));
        queue<pii> q;
        q.push(pii(1,1));
        visited[1][1] = true;
        int tmp = 0;

        while (!q.empty())
        {
            int ux = q.front().first, uy = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ax = ux + dx[i], ay = uy + dy[i];
                if (valid(ax, ay) && r[ax][ay].on && !visited[ax][ay])
                {
                    tmp += (!r[ax][ay].visited);
                    r[ax][ay].visited = visited[ax][ay] = true;
                    for (int j = 0; j < r[ax][ay].lit.size(); ++j)
                        r[r[ax][ay].lit[j].first][r[ax][ay].lit[j].second].on = true;
                    q.push(pii(ax, ay));
                }
            }
        }

        if (!tmp) break;
    }

    int res = 0;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
        res += r[i][j].on;
    cout << res;
    return 0;
}
