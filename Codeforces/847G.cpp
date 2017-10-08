#include <bits/stdc++.h>

using namespace std;

int n, cnt[10], res;
char s[10];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < 7; ++j) {
            cnt[j] += s[j] - '0';
        }
    }

    for (int i = 0; i < 7; ++i) {
        res = max(res, cnt[i]);
    }

    printf("%d\n", res);
    return 0;
}
