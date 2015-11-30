#include <bits/stdc++.h>

using namespace std;

char s[20];
int n, test, gt[11], c[11][11];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d", &test);
    while (test--)
    {
        scanf("%s", s);
        n = atoi(s);
        int cnt = 0, len = strlen(s), spc = 0;

        while (next_permutation(s, s+len))
        {
            ++cnt;
        }

        itoa(n, s, 10);

        do
        {
            ++spc;
        }
        while (prev_permutation(s, s+len));

        spc += cnt;

        if (cnt == 0)
        {
            printf("0.000000000\n");
            continue;
        }
        double res = 1.0/spc, xx = 1.0/spc;

        for (int i = 1; i < cnt; ++i)
        {
            xx = xx / spc * (cnt - i) / i;
            res += xx;
        }

        printf("%.9lf\n", res);
    }
    return 0;
}
