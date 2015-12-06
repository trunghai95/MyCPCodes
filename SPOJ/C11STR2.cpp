#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

char a[MAXN], b[MAXN], s[MAXN*2];
int z[MAXN*2], n, la, lb;

int main()
{
    scanf("%s %s", a, b);
    la = strlen(a), lb = strlen(b);
    strcpy(s, b);
    strcpy(s + lb, a);
    n = la + lb;

    int L = 0, R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && s[R] == s[R-L]) ++R;
            z[i] = R - L, --R;
        }
        else
        {
            int k = i - L;
            if (z[k] < R - i + 1) z[i] = z[k];
            else
            {
                L = i;
                while (R < n && s[R] == s[R-L]) ++R;
                z[i] = R - L, --R;
            }
        }
    }

    int ll;
    for (ll = max(la, lb); ll < n; ++ll)
        if (z[ll] == n - ll) break;

    printf("%s", a);
    for (int i = z[ll]; i < lb; ++i)
        printf("%c", b[i]);

    return 0;
}
