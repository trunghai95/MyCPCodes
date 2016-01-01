//WA
#include <bits/stdc++.h>

using namespace std;

int n, a[3];
int cnt[3];

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d %d %d %d", &n, a, a+1, a+2);
    sort(a, a+3);
    for (int i = 0, x; i < n; ++i)
    {
        scanf("%d", &x);
        if (x <= a[0]) ++cnt[0];
        else if (x <= a[1]) ++cnt[1];
        else if (x <= a[2]) ++cnt[2];
        else if (x <= a[0] + a[1]) ++cnt[0], ++cnt[1];
        else if (x <= a[0] + a[2]) ++cnt[0], ++cnt[2];
        else if (x <= a[1] + a[2]) ++cnt[1], ++cnt[2];
        else if (x <= a[0] + a[1] + a[2]) ++cnt[0], ++cnt[1], ++cnt[2];
        else
        {
            printf("-1");
            return 0;
        }
    }

    int mn = min(min(cnt[0], cnt[1]), cnt[2]);
    int res = mn;
    for (int i = 0; i < 3; ++i) cnt[i] -= mn;

    if (!cnt[0] && !cnt[1] && !cnt[2])
        printf("%d", res);
    else if (!cnt[0] && !cnt[1])
        printf("%d", res + cnt[2]);
    else if (!cnt[1] && !cnt[2])
        printf("%d", res + cnt[0] / 3 + (cnt[0] % 3 > 0));
    else if (!cnt[0] && !cnt[2])
        printf("%d", res + cnt[1] / 2 + (cnt[1] % 2 > 0));
    else if (!cnt[2])
    {
        int sum = cnt[0] + cnt[1];
        cnt[2] = cnt[1] / 2;
        cnt[1] -= cnt[2];
        if (cnt[0] <= cnt[2])
            printf("%d", res + cnt[1]);
        else
        {
            if (cnt[1] == cnt[2])
                cnt[0] -= cnt[2], printf("%d", res + cnt[2] + cnt[0] / 3 + (cnt[0] % 3 > 0));
            else if (cnt[0] - cnt[2] <= 2)
                cout << res + cnt[1];
            else cnt[0] -= cnt[2] + 2, printf("%d", res + cnt[1] + cnt[0] / 3 + (cnt[0] % 3 > 0));
        }
    }
    else if (!cnt[0])
    {
        int sum = cnt[1] + cnt[2];
        cnt[2] = sum / 2;
        cnt[1] = sum - cnt[2];
        printf("%d", res + cnt[1]);
    }
    else
    {
        int sum = cnt[0] + cnt[2];
        cnt[1] = cnt[0] / 2;
        cnt[0] -= cnt[1];
        if (cnt[0] < cnt[2])
            printf("%d", res + cnt[2]);
        else if (cnt[1] > cnt[2])
            printf("%d", res + sum / 3 + (sum % 3 > 0));
        else printf("%d", res + max(max(cnt[0], cnt[1]), cnt[2]));
    }
    return 0;
}
