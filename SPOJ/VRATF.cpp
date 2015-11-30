#include <bits/stdc++.h>

using namespace std;

int n, k;
queue<int> q;
int res;

int main()
{
    cin >> n >> k;
    q.push(n);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (u <= k || ((u - k)&1))
            ++res;
        else
        {
            int x = (u-k) >> 1;
            q.push(x);
            q.push(x+k);
        }
    }

    cout << res;
    return 0;
}
