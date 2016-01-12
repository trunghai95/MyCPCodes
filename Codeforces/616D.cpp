#include <bits/stdc++.h>

using namespace std;

int n, k, a[500010], cnt[1000001], cntNum;

int main()
{
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);

    int lef = 0, rig = 0, resl = 0, resr = 0, longest = 1;
    cnt[a[0]] = 1;
    cntNum = 1;

    while (lef < n)
    {
        while (rig < n && cntNum <= k)
        {
            ++rig;
            if (++cnt[a[rig]] == 1) ++cntNum;
        }

        if (--cnt[a[rig--]] == 0) --cntNum;

        if (longest < rig - lef + 1)
        {
            longest = rig - lef + 1;
            resl = lef, resr = rig;
        }

        if (--cnt[a[lef++]] == 0) --cntNum;
    }

    printf("%d %d", resl + 1, resr + 1);

    return 0;
}
