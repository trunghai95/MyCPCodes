#include <bits/stdc++.h>

using namespace std;

int n, k, val[200], m, sum, x, l;
char s[11111];

int main()
{
    scanf("%d",&n);
    while (n--)
    {
        sum = 0;
        memset(val, 0, sizeof(val));
        scanf("%d",&k);
        for (int i = 0; i < k; ++i)
        {
            scanf("%s %d",s,&x);
            val[s[0]] = x;
        }
        scanf("%d",&m);
        for (int i = 0; i < m; ++i)
        {
            scanf(" %[^\n]s",s);
            l = strlen(s);
            for (int j = 0; j < l; ++j)
                sum += val[s[j]];
        }
        printf("%d.%02d$\n",sum/100,sum%100);
    }
    return 0;
}
