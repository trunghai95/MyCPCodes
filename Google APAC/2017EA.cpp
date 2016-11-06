#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, tt;
char s[111];
ll len, l, r, cnt[111];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%s", s+1);
        len = strlen(s+1);
        scanf("%lld %lld", &l, &r);
        --l;

        for (int i = 1; i <= len; ++i) {
            cnt[i] = cnt[i-1] + (s[i] == 'B');
        }

        l = cnt[len] * (l / len) + cnt[l % len];
        r = cnt[len] * (r / len) + cnt[r % len];
        printf("Case #%d: %lld\n", ++tt, r - l);
    }
    return 0;
}
