#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool ck[1000001];
int n;

int main()
{
    memset(ck, -1, sizeof(ck));
    ck[0] = 0;
    ck[1] = 1;

    for (ll i = 2; i*i <= 1000000; ++i)
    {
        if (ck[i])
        {
            for (ll j = i*i; j <= 1000000; j += i)
                ck[j] = 0;
        }
    }

    int test;
    scanf("%d", &test);
    for (int ii = 1; ii <= test; ++ii)
    {
        scanf("%d", &n);
        int res = 0;
        for (int i = 1; i <= n; ++i)
            if (ck[i]) ++res;
        printf("Case #%d: %d\n", ii, res);
    }
    return 0;
}
