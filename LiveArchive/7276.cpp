#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = (1LL<<31) - 1;

int n, lastPos, curPos;
ll cntLast[2010], cntCur[2010];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while (scanf("%d", &n) != EOF)
    {
        scanf("%d %d", &lastPos, &curPos);
        memset(cntCur, 0, sizeof(cntCur));
        memset(cntLast, 0, sizeof(cntLast));
        cntCur[lastPos] = 1;

        for (int i = 1; i < n; ++i)
        {
            lastPos = curPos;
            scanf("%d", &curPos);
            memcpy(cntLast, cntCur, sizeof(cntCur));
            memset(cntCur, 0, sizeof(cntCur));

            for (int i = 1; i < 2010; ++i)
            if (cntLast[i])
            {
                if (i < lastPos)
                {
                    if (curPos > i)
                        cntCur[i] = (cntCur[i] + cntLast[i]) % MODD;
                    if (curPos < lastPos)
                        cntCur[lastPos] = (cntCur[lastPos] + cntLast[i]) % MODD;
                }
                else if (i > lastPos)
                {
                    if (curPos < i)
                        cntCur[i] = (cntCur[i] + cntLast[i]) % MODD;
                    if (curPos > lastPos)
                        cntCur[lastPos] = (cntCur[lastPos] + cntLast[i]) % MODD;
                }
            }
        }

        ll res = 0;

        for (int i = 1; i < 2010; ++i)
            res = (res + cntCur[i]) % MODD;

        printf("%lld\n", res);
    }
    return 0;
}
