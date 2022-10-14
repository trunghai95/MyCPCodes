#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;
ll w, sum, x, y;

int main() {
    scanf("%lld %d", &w, &n);
    while (n --> 0) {
        scanf("%lld %lld", &x, &y);
        sum += x*y;
    }
    printf("%lld\n", sum/w);
    return 0;
}