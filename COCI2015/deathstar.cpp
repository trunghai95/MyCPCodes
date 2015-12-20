#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        int res = 0;

        for (int j = 0, x; j < n; ++j)
        {
            scanf("%d", &x);
            res |= x;
        }

        printf("%d ", res);
    }
    return 0;
}
