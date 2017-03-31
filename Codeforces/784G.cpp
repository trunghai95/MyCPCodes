#include <bits/stdc++.h>

using namespace std;

char s[500];
int res, cur;
bool neg;

int main() {
    scanf("%s", s);

    for (int i = 0; s[i]; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            cur = cur * 10 + s[i] - '0';
        } else {
            if (neg) {
                res -= cur;
            } else {
                res += cur;
            }
            cur = 0;
            neg = (s[i] == '-');
        }
    }

    if (neg) {
        res -= cur;
    } else {
        res += cur;
    }

    sprintf(s, "%d", res);

    for (int i = 0; i < 48; ++i)
        printf("+");
    cur = '0';

    for (int i = 0; s[i]; ++i) {
        while (cur < s[i]) {
            ++cur;
            printf("+");
        }

        while (cur > s[i]) {
            --cur;
            printf("-");
        }

        printf(".");
    }

    printf("\n");
    return 0;
}
