#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
ll x;

int main()
{
    scanf("%d", &n);

    while (n--)
    {
        scanf("%lld", &x);

        while (1)
        {
            ll tmp = x;
            while (tmp % 10LL == 0LL)
                tmp /= 10LL;

            if (tmp % 10LL != 5LL) break;

            x *= 4LL;
        }

        printf("%lld\n", x);
    }
    return 0;
}
