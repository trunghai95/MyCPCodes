#include <bits/stdc++.h>

using namespace std;

int n, lef[200010], rig[200010];

int main() {
    scanf("%d", &n);

    int mx = -1e9, res = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", lef+i, rig+i);
        mx = max(mx, lef[i]);
    }

    for (int i = 0; i < n; ++i)
        res += (rig[i] >= mx);

    printf("%d\n", res);
    return 0;
}
