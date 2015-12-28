//WA
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > cycles;
int n, a[1000010], res[1000010], tt[1000010];

bool cmp(const int& x, const int& y)
{
    return cycles[x].size() < cycles[y].size();
}

void f1(int p)
{
    for (int i = 0; i < cycles[p].size(); ++i)
    {
        res[cycles[p][(i+2)%cycles[p].size()]] = cycles[p][i];
    }
}

void f2(int p, int q)
{
    for (int i = 0; i < cycles[p].size(); ++i)
    {
        res[cycles[p][i]] = cycles[q][i];
        res[cycles[q][i]] = cycles[p][(i+1)%cycles[p].size()];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a+i);
        if (a[i] == i)
            res[i] = i, a[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
    if (a[i])
    {
        cycles.push_back(vector<int>());

        int j = i;
        while (a[j])
        {
            cycles.back().push_back(j);
            int tmp = a[j];
            a[j] = 0;
            j = tmp;
        }
    }

    for (int i = 0; i < cycles.size(); ++i)
        tt[i] = i;

    sort(tt, tt+cycles.size(), cmp);

    for (int i = 0; i < cycles.size(); ++i)
    {
        if (cycles[tt[i]].size() & 1)
            f1(tt[i]);
        else if (i < cycles.size() - 1 && cycles[tt[i]].size() == cycles[tt[i+1]].size())
            f2(tt[i], tt[i+1]), ++i;
        else
        {
            printf("-1");
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", res[i]);
    return 0;
}
