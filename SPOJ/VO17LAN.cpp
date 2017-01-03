#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50000;
int test, n, a[MAXN+2];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i);

        vector<int> v;

        for (int u = 1; u <= a[1]/u; ++u) {
            if (a[1] % u == 0)
                v.push_back(u), v.push_back(a[1] / u);
        }

        if (v.size() > 2 && v[v.size() - 1] == v[v.size() - 2]) v.pop_back();

        int res = 1;
        for (int i = 0; i < (int)v.size(); ++i)
        if (v[i] > res) {
            int u = v[i];
            int rig = 0;
            for (int j = 2; j <= n; ++j) {
                if (a[j] % u != 0) {
                    if (!rig)
                        rig = a[j];
                    else
                        rig = __gcd(rig, a[j]);
                }
            }
            if (rig)
                res = max(res, min(u, rig));
            else
                res = max(res, u);
        }

        printf("%d\n", res);
    }
    return 0;
}
