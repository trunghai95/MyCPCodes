#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n, a[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    sort(a+1, a+1+n);

    int res1 = 2e9+1;
    int res2 = 0;

    for (int i = 2; i <= n; ++i) {
        int dis = a[i] - a[i-1];
        if (dis == res1) {
            ++res2;
        } else if (dis < res1) {
            res1 = dis;
            res2 = 1;
        }
    }

    printf("%d %d\n", res1, res2);
    return 0;
}
