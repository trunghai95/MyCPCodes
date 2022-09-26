#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;
int n, d, a[MAXN], res;

int count(int lo, int hi, int bound1, int bound2) {
    int cnt = 0;
    while (lo < hi) {
        if (a[lo] + a[hi] < bound1) {
            lo++;
        } else if (a[lo] + a[hi] > bound2) {
            hi--;
        } else {
            cnt++;
            lo++;
            hi--;
        }
    }
    return cnt;
}

int main() {
    freopen("PAIR.INP", "r", stdin);
    freopen("PAIR.OUT", "w", stdout);
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }

    sort(a, a+n);

    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if ((j-i+1)/2 <= res) {
                continue;
            }
            res = max(res, count(i, j, a[i]+a[j], a[i]+a[j]+d));
            res = max(res, count(i, j, a[i]+a[j]-d, a[i]+a[j]));
        }
    }

    printf("%d\n", res);
    return 0;
}