#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int n, a[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);

    sort(a+1, a+1+n);

    for (int i = 1; i + 2 <= n; ++i) {
        if (a[i] + a[i+1] > a[i+2]) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
