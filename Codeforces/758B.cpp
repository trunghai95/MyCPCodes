#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n, cnt[4], p[4];
char s[MAXN+2];

int main() {
    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
            p[0] = i%4;
        } else if (s[i] == 'B') {
            p[1] = i%4;
        } else if (s[i] == 'Y') {
            p[2] = i%4;
        } else if (s[i] == 'G') {
            p[3] = i%4;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == '!') {
            ++cnt[i%4];
        }
    }

    for (int i = 0; i < 4; ++i)
        printf("%d ", cnt[p[i]]);
    printf("\n");
    return 0;
}
