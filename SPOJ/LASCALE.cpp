#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m;
vector<ll> lef, rig;
ll gt3;

int main()
{
    scanf("%lld", &m);
    gt3 = 1;

    while (m)
    {
        if (m % 3 == 1) rig.push_back(gt3), --m;
        else if (m % 3 == 2) lef.push_back(gt3), ++m;

        m /= 3;
        gt3 *= 3;
    }

    printf("%d", lef.size());
    for (int i = 0; i < lef.size(); ++i)
        printf(" %lld", lef[i]);
    printf("\n%d", rig.size());
    for (int i = 0; i < rig.size(); ++i)
        printf(" %lld", rig[i]);
    return 0;
}
