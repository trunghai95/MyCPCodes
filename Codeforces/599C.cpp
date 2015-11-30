#include <bits/stdc++.h>

using namespace std;

int h[100000], mx, mn[100000], n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", h+i);

    mn[n-1] = h[n-1];
    for (int i = n-2; i >= 0; --i)
        mn[i] = min(h[i], mn[i+1]);

    int res = 1;
    mx = 0;
    for (int i = 0; i < n-1; ++i)
    {
        mx = max(mx, h[i]);
        if (mx <= mn[i+1])
        {
            ++res;
            mx = 0;
        }
    }
    printf("%d", res);
    return 0;
}
