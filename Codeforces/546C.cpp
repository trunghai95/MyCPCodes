#include <bits/stdc++.h>

using namespace std;

int n, k1, k2, x;
queue<int> q1, q2;

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n >> k1;
    for (int i = 0; i < k1; ++i)
    {
        cin >> x;
        q1.push(x);
    }
    cin >> k2;
    for (int i = 0; i < k2; ++i)
    {
        cin >> x;
        q2.push(x);
    }

    int p = 1;
    for (int i = 2; i <= n+1; ++i)
        p *= i;

    for (int i = 1; i <= p; ++i)
    {
        if (q1.front() < q2.front())
        {
            q2.push(q1.front());
            q2.push(q2.front());
            q1.pop(), q2.pop();
        }
        else
        {
            q1.push(q2.front());
            q1.push(q1.front());
            q1.pop(), q2.pop();
        }

        if (q1.empty())
        {
            cout << i << ' ' << 2;
            return 0;
        }
        else if (q2.empty())
        {
            cout << i << ' ' << 1;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
