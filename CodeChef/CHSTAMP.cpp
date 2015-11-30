#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 5e4;
const int INF = 2e9;

struct Node
{
    int point, time;
    Node() {}
    Node(int _p, int _t): point(_p), time(_t) {}
};

bool cmpSort(const Node& x, const Node& y) { return x.time > y.time; }
struct cmpHeap
{
    bool operator() (const Node& x, const Node& y)
    {
        return x.time < y.time;
    }
};

vector<Node> adj[MAX+1];
bool ck[MAX+1];
priority_queue<Node, vector<Node>, cmpHeap > heap;
int f[MAX+1], cnt[MAX+1], n, m;

int main()
{
    //freopen("in.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    while (test--)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= MAX; ++i)
            adj[i].clear();
        for (int i = 0, x; i < n; ++i)
        {
            scanf("%d", &x);
            ++cnt[x];
        }

        for (int i = 0, t, a, b; i < m; ++i)
        {
            scanf("%d %d %d", &t, &a, &b);
            adj[a].push_back(Node(b, t));
            adj[b].push_back(Node(a, t));
        }

        for (int i = 1; i <= MAX; ++i)
        {
            f[i] = i;
            sort(adj[i].begin(), adj[i].end(), cmpSort);
        }

        for (int root = MAX; root; --root)
        if (!adj[root].empty())
        {
            vector<int> tmp;
            while (!heap.empty()) heap.pop();

            heap.push(Node(root, INF));

            while (!heap.empty())
            {
                Node u = heap.top();
                heap.pop();

                if (ck[u.point]) continue;

                ck[u.point] = true;
                tmp.push_back(u.point);
                f[u.point] = max(f[u.point], root);

                for (int i = adj[u.point].size() - 1; i >= 0 && adj[u.point][i].time <= u.time; --i)
                {
                    heap.push(adj[u.point][i]);
                    adj[u.point].pop_back();
                }
            }

            for (int i = 0; i < tmp.size(); ++i)
                ck[tmp[i]] = false;
        }

        ll res = 0;
        for (int i = 1; i <= MAX; ++i)
            res += (ll)f[i] * cnt[i];

        printf("%lld\n", res);
    }
    return 0;
}
