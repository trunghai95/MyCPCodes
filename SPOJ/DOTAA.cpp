#include <bits/stdc++.h>

using namespace std;

int test, n, m, d, h, cnt;

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d %d", &n, &m, &d);
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &h);
            cnt += (h-1) / d;
        }

        if (cnt >= m)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
