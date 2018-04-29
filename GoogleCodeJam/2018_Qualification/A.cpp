#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 30;
int test, n;
char s[MAXN+3];
ll d, sum, x;

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%lld %s", &d, s);
        n = strlen(s);

        x = 1;
        sum = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'C') {
                x <<= 1;
            } else {
                sum += x;
            }
        }

        int res = 0;
        for (int i = n-1; i >= 0 && sum > d; --i)
        if (s[i] == 'C') {
            for (int j = i; s[j+1] == 'S' && sum > d; ++j) {
                sum -= (x >> 1);
                swap(s[j], s[j+1]);
                ++res;
            }
            x >>= 1;
        }

        printf("Case #%d: ", tt);
        if (sum > d) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", res);
        }
    }
    return 0;
}