#include <bits/stdc++.h>

using namespace std;

int n, a[100001], cnt[100001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cnt[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        if (a[i] < a[i-1]) cnt[i] = 1;
        else cnt[i] = cnt[i-1] + 1;
    }

    sort(cnt,cnt+n);
    cout << cnt[n-1];
    return 0;
}
