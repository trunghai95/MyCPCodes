#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6;
int n, a, mnpos, mxneg, sum;

int main() {
    mnpos = INF;
    mxneg = -INF;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);

        if (a > 0) {
            sum += a;
        }

        if (a&1) {
            if (a > 0) {
                mnpos = min(mnpos, a);
            } else {
                mxneg = max(mxneg, a);
            }
        }
    }

    if (!(sum&1)) {
        sum -= min(mnpos, abs(mxneg));
    }

    printf("%d\n", sum);
    return 0;
}
