#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, t, a;

int main() {
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        a = 86400 - a;
        if (a >= t) {
            printf("%d\n", i);
            return 0;
        } else {
            t -= a;
        }
    }
    return 0;
}