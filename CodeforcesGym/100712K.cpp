#include <bits/stdc++.h>

using namespace std;

int n, t, k, a[100007], cnt[100007], x, y, f;

int main()
{
    cin >> t;
    while (t--)
    {
        f = 0;
        memset(cnt,0,sizeof(cnt));
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (a[i] != 0)
                ++cnt[a[i]];
            else
            {
                --n; --i;
            }
        }
        sort(a,a+n);
        for (int i = 0; i < n; ++i)
        if (k%a[i] == 0)
        {
            x = a[i];
            y = k/x;
            if ((x != y && cnt[x] && cnt[y]) || (x == y && cnt[x] > 1))
            {
                f = 1;
                break;
            }
        }
        if (f)
            cout << x << " " << y << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
