#include <bits/stdc++.h>

using namespace std;

int n, x, pos[200000];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        pos[x] = i;
    }

    int mx = 0, cur = 0;
    pos[0] = 2e9;
    for (int i = 1; i <= n; ++i)
    {
        if (pos[i] > pos[i-1])
            ++cur;
        else
        {
            mx = max(mx, cur);
            cur = 1;
        }
    }
    mx = max(mx, cur);

    printf("%d", n - mx);
    return 0;
}
