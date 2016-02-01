#include <bits/stdc++.h>

using namespace std;

struct Node
{
    vector<int> parent, child;
};

int a, b, n, p, r1, r2, r3;
Node node[5000];
bool visited[5000];
bool e[5000][5000];

void proc(int u)
{
    visited[u] = true;

    for (int i = 0; i < node[u].child.size(); ++i)
    if (!visited[node[u].child[i]])
        proc(node[u].child[i]);

    for (int i = 0; i < node[u].child.size(); ++i)
    for (int j = 0; j < node[u].parent.size(); ++j)
    if (!e[node[u].parent[j]][node[u].child[i]])
    {
        node[node[u].child[i]].parent.push_back(node[u].parent[j]);
        node[node[u].parent[j]].child.push_back(node[u].child[i]);
        e[node[u].parent[j]][node[u].child[i]] = true;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    while (scanf("%d %d %d %d", &a, &b, &n, &p) != EOF)
    {
        memset(visited, 0, sizeof(visited));
        memset(e, 0, sizeof(e));
        for (int i = 0; i < 5000; ++i)
            node[i] = Node();
        for (int i = 0, u, v; i < p; ++i)
        {
            scanf("%d %d", &u, &v);
            node[u].child.push_back(v);
            node[v].parent.push_back(u);
            e[u][v] = true;
        }

        for (int i = 0; i < n; ++i)
        if (!visited[i])
            proc(i);

        r1 = r2 = r3 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (node[i].child.size() >= n - a)
                ++r1;
            if (node[i].child.size() >= n - b)
                ++r2;
            if (node[i].parent.size() >= b)
                ++r3;
        }

        printf("%d\n%d\n%d\n", r1, r2, r3);
    }

    return 0;
}
