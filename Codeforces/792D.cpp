#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
ll n, u;
int q;
char s[MAXN+2];
bool dir[70];

int main() {
    scanf("%lld %d", &n, &q);

    while (q --> 0) {
        scanf("%lld %s", &u, s);
        ll lef = 1, rig = n, mid = (n + 1) / 2;
        int level = 0;

        while (mid != u) {
            if (u > mid) {
                dir[level] = 1;
                lef = mid + 1;
            } else {
                dir[level] = 0;
                rig = mid - 1;
            }

            mid = (lef + rig) / 2;
            ++level;
        }

        for (int i = 0; s[i]; ++i) {
            if (s[i] == 'U') {
                if (level == 0) {
                    continue;
                }

                if (dir[--level] == 1) {
                    mid = lef - 1;
                    lef = mid * 2 - rig;
                } else {
                    mid = rig + 1;
                    rig = mid * 2 - lef;
                }
            } else {
                if (lef == rig) {
                    continue;
                }

                if (s[i] == 'R') {
                    dir[level] = 1;
                    lef = mid + 1;
                } else {
                    dir[level] = 0;
                    rig = mid - 1;
                }
                mid = (lef + rig) / 2;
                ++level;
            }
        }

        printf("%lld\n", mid);
    }
    return 0;
}
