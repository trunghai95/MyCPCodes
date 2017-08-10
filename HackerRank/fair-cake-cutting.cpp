#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, n;

int main() {
    scanf("%lld %lld %lld", &a, &b, &n);

    ll g = __gcd(a, b);
    a /= g;
    b /= g;

    g = n * b / a;

    printf("%lld\n", g);
    return 0;
}
