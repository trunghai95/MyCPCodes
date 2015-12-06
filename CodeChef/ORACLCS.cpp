#include <bits/stdc++.h>

using namespace std;

char s[200];
int test, n;

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &test);

    while (test--)
    {
        scanf("%d", &n);
        int a = 2e9, b = 2e9;

        while (n--)
        {
            scanf("%s", s);
            int cnta = 0, cntb = 0, i = 0;
            while (s[i] != 0)
            {
                if (s[i] == 'a') ++cnta;
                else ++cntb;
                ++i;
            }
            a = min(a, cnta);
            b = min(b, cntb);
        }

        printf("%d\n", min(a, b));
    }
    return 0;
}
