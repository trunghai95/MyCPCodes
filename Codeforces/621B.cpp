#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll res;
int n, x, y;
map<int,int> mp1, mp2;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &x, &y);
        ++mp1[x+y];
        ++mp2[x-y];
    }

    map<int,int>::iterator it;

    for (it = mp1.begin(); it != mp1.end(); ++it)
    {
        res += (ll)(*it).second*((*it).second - 1)/2;
    }

    for (it = mp2.begin(); it != mp2.end(); ++it)
    {
        res += (ll)(*it).second*((*it).second - 1)/2;
    }

    printf("%lld", res);
    return 0;
}
