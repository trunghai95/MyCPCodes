#include <bits/stdc++.h>

using namespace std;

const int MAX = 60010;
int n, a[MAX], bit[MAX], res;

void update(int x)
{
    while (x <= MAX)
    {
        ++bit[x];
        x += x&(-x);
    }
}

int get(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += bit[x];
        x -= x&(-x);
    }
    return res;
}

int main()
{
    cin >> n;
    res = 0;
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        update(a[i]);
        res += i - get(a[i]);
    }

    cout << res;
    return 0;
}
