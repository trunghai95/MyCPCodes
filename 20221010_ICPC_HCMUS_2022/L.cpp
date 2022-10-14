#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000006;
int n, id[MAXN], l, r, d, res;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d);
        id[d] = i;
    }
    l = id[n];
    r = id[n];
    for (int i = n-1; i > 0; i--) {
        if (id[i] > l) {
            res++;
        }
        if (id[i] < r) {
            res++;
        }
        l = min(l, id[i]);
        r = max(r, id[i]);
    }
    printf("%d\n", res);
    return 0;
}