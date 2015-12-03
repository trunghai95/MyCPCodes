#include <bits/stdc++.h>

using namespace std;

char s1[1000001], s[2000001];
int n2, n, z[2000001];

int main()
{
    scanf("%s %s", s1, s);
    n2 = strlen(s);
    strcpy(s+n2, s1);
    n = strlen(s);

    int l = 0, r = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && s[r] == s[r-l]) ++r;

            z[i] = r - l;
            --r;
        }
        else
        {
            int k = i - l;
            if (z[k] < r - i + 1) z[i] = z[k];
            else
            {
                l = i;
                while (r < n && s[r] == s[r-l]) ++r;

                z[i] = r - l;
                --r;
            }
        }
    }

    for (int i = n2; i < n; ++i)
    if (z[i] >= n2)
    {
        printf("%d ", i - n2 + 1);
    }

    return 0;
}
