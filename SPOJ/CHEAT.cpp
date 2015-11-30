#include <bits/stdc++.h>

using namespace std;

int n, x;
queue<int> q;
stack<int> s;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        q.push(i);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);

        if (!s.empty() && s.top() == x)
        {
            s.pop();
            continue;
        }

        while (!q.empty() && q.front() < x)
        {
            s.push(q.front());
            q.pop();
        }

        if (q.empty() || q.front() != x)
        {
            printf("YES");
            return 0;
        }

        q.pop();
    }

    printf("NO");
    return 0;
}
