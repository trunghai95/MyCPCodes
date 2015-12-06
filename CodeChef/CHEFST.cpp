#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
ll a, b, m;

int main()
{
    scanf("%d", &test);

    while (test--)
    {
        scanf("%lld %lld %lld", &a, &b, &m);

        m = m*(m+1)/2;
        m = min(m, min(a, b));

        a -= m;
        b -= m;

        printf("%lld\n", a + b);
    }
    return 0;
}
