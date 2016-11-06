#include <bits/stdc++.h>

using namespace std;

long long n;
int test;

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%lld", &n);
        n = (n-1)*7 + (n-2)*(n-1)*2 + 3;
        if (n % 3 == 0) {
            printf("%lld.00\n", n/3);
        } else if (n % 3 == 1) {
            printf("%lld.33\n", n/3);
        } else {
            printf("%lld.67\n", n/3);
        }
    }
    return 0;
}
