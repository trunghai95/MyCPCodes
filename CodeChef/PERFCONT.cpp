#include <bits/stdc++.h>

using namespace std;

int test, n, p, a, cnt[2];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d", &n, &p);
        cnt[0] = cnt[1] = 0;

        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a);
            if (a >= p/2) {
                ++cnt[0];
            } else if (a <= p/10) {
                ++cnt[1];
            }
        }

        if (cnt[0] == 1 && cnt[1] == 2) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
