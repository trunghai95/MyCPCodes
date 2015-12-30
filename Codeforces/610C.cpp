#include <bits/stdc++.h>

using namespace std;

struct Mat
{
    char mp[600][600];
    int sz;

    Mat() { memset(mp, 0, sizeof(mp)); }

    void construct(Mat &m, Mat &mn)
    {
        sz = (m.sz << 1);

        for (int i = 0; i < m.sz; ++i)
        for (int j = 0; j < sz; ++j)
            mp[i][j] = m.mp[i][j % m.sz];

        for (int i = m.sz; i < sz; ++i)
        for (int j = 0; j < m.sz; ++j)
            mp[i][j] = m.mp[i % m.sz][j];

        for (int i = m.sz; i < sz; ++i)
        for (int j = m.sz; j < sz; ++j)
            mp[i][j] = mn.mp[i % m.sz][j % m.sz];
    }
};

Mat m[10], mn[10];

void init()
{
    m[0].sz = mn[0].sz = 1;
    m[0].mp[0][0] = '+';
    mn[0].mp[0][0] = '*';

    for (int i = 1; i < 9; ++i)
    {
        m[i].construct(m[i-1], mn[i-1]);
        mn[i].construct(mn[i-1], m[i-1]);
    }

    m[9].construct(m[8], mn[8]);
}

int main()
{
    init();
    int k;
    scanf("%d", &k);

    for (int i = 0; i < m[k].sz; ++i)
    {
        printf("%s\n", m[k].mp[i]);
    }
    return 0;
}
