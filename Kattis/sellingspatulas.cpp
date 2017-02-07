#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define F first
#define S second

const int MAXN = 1000;
int n, resl, resr, len;
int res, sum, tmp;
pii a[MAXN+2];
char s[20];

int main() {

    while (true) {
        scanf("%d", &n);

        if (!n) {
            return 0;
        }

        res = -1;

        for (int j = 1; j <= n; ++j) {
            scanf("%d %s", &a[j].F, s);
            len = strlen(s);
            s[len-3] = s[len-2];
            s[len-2] = s[len-1];
            s[len-1] = 0;
            sscanf(s, "%d", &a[j].S);
            sum = 0;

            for (int i = j; i >= 1; --i) {
                sum += a[i].S;
                tmp = sum - 8 * (a[j].F - a[i].F + 1);

                if (tmp <= 0) continue;
                if (tmp > res) {
                    res = tmp;
                    resl = a[i].F;
                    resr = a[j].F;
                } else if (tmp == res) {
                    if (a[j].F - a[i].F < resr - resl 
                        || (a[j].F - a[i].F == resr - resl && a[i].F < resl)) {
                        resl = a[i].F;
                        resr = a[j].F;
                    }
                }
            }
        }

        if (res <= 0) {
            printf("no profit\n");
        } else {
            printf("%d.%02d %d %d\n", res/100, res%100, resl, resr);
        }
    }
    return 0;
}
