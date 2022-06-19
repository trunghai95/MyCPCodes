#include <stdio.h>

using namespace std;

// const int MAXN = 100005;
const int MAXM = 30;
int n, m, k, wlFlag[MAXM], wlFlagNeg[MAXM], tmp;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &tmp);
            if (tmp > 0) {
                wlFlag[i] = wlFlag[i] | (1 << (tmp-1));
            } else {
                wlFlagNeg[i] = wlFlagNeg[i] | (1 << (-tmp-1));
            }
        }
    }

    int maxFlag = 1 << n;
    // printf("%d\n", maxFlag);
    int res = 0;
    for (int f = 0; f < maxFlag; f++) {
        bool ok = true;
        for (int i = 0; i < m; i++) {
            if ((f & wlFlag[i]) > 0) {
                continue;
            } 
            int fNeg = ((maxFlag - 1) ^ f);
            if ((fNeg & wlFlagNeg[i]) > 0) {
                continue;
            }
            // printf("f:%d fNeg:%d i:%d wlFlag:%d wlFlagNeg:%d\n", f, fNeg, i, wlFlag[i], wlFlagNeg[i]);
            ok = false;
            break;
        }
        if (ok) {
            res++;
        }
    }
    printf("%d\n", res);
    return 0;
}