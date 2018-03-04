#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, res;

int main() {
    scanf("%lld %lld", &a, &b);
    if (a == b) {
        printf("infinity\n");
        return 0;
    }
    if (a < b) {
        printf("0\n");
        return 0;
    }
    a -= b;
    for (ll i = 1; i*i <= a; ++i)
    if (a % i == 0) {
        res += (i > b);
        if (a/i != i) {
            res += (a/i > b);
        }
    }
    printf("%lld\n", res);
    return 0;
}