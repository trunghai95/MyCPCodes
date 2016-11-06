#include <bits/stdc++.h>

using namespace std;

int n, a, res;

int main() {
    scanf("%d", &n);
    while (n --> 0) {
        scanf("%d", &a);
        res = max(res, a);
    }
    printf("%d\n", res);
    return 0;
}
