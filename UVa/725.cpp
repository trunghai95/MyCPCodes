#include <bits/stdc++.h>

using namespace std;

int n, a, b, m, tmp, f, i;
bool ck[10];

int main()
{
    while (1)
    {
        f = 0;
        cin >> n;
        if (n == 0)
            return 0;
        m = 98765/n;
        for (a = 1234; a <= m; ++a)
        {
            memset(ck,0,sizeof(ck));
            b = a*n;
            tmp = a;
            for (i = 0; i < 5; ++i)
            {
                if (ck[tmp%10])
                    break;
                ck[tmp%10] = 1;
                tmp /= 10;
            }
            if (i < 5)
                continue;
            tmp = b;
            for (i = 0; i < 5; ++i)
            {
                if (ck[tmp%10])
                    break;
                ck[tmp%10] = 1;
                tmp /= 10;
            }
            if (i < 5)
                continue;
            f = 1;
            printf("%05d / %05d = %d\n", b, a, n);
        }
        if (!f)
            printf("There are no solutions for %d.\n",n);
        printf("\n");
    }
    return 0;
}
