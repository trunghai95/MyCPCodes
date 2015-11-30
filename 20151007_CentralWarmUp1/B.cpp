#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> pis;
int test, n, edge[111][111], age[111];
map<string, int> id;
vector<pis> res;

int getId(string s)
{
    map<string, int>::iterator it = id.find(s);
    if (it == id.end())
    {
        res.push_back(pis(0, s));
        return id[s] = id.size() - 1;
    }
    return id[s];
}

bool cmp(pis x, pis y) { return x.first > y.first || (x.first == y.first && x.second < y.second);}

int main()
{
    cin >> test;
    for (int ii = 1; ii <= test; ++ii)
    {
        memset(edge, 0, sizeof(edge));
        memset(age, -1, sizeof(age));
        id.clear();
        res.clear();
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            string fn, cn;
            cin >> fn >> cn;
            int u = getId(fn), v = getId(cn);
            cin >> edge[u][v];
            edge[v][u] = -edge[u][v];
        }

        int s = id["Ted"];
        queue<int> q;
        q.push(s);
        age[s] = 100;

        while (!q.empty())
        {
            s = q.front(); q.pop();

            for (int i = 0; i <= n; ++i)
            {
                if (age[i] == -1 && edge[s][i])
                {
                    age[i] = age[s] - edge[s][i];
                    q.push(i);
                }
            }
        }

        for (int i = 0; i < res.size(); ++i)
            res[i].first = age[i];

        cout << "DATASET " << ii << endl;
        sort(res.begin(), res.end(), cmp);
        for (int i = 0; i < res.size(); ++i)
        {
            if (res[i].second != "Ted")
                cout << res[i].second << ' ' << res[i].first << endl;
        }
    }
    return 0;
}
