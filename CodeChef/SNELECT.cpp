#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int test, n;
char s[MAXN+5];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%s", s+1);
        n = strlen(s+1);

        for (int i = 1; i <= n; ++i)
        if (s[i] == 'm') {
            if (s[i-1] == 's') {
                s[i-1] = '.';
            } else if (s[i+1] == 's') {
                s[i+1] = '.';
            }
        }

        int mo = 0, sn = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 's') {
                ++sn;
            } else if (s[i] == 'm') {
                ++mo;
            }
        }

        if (sn > mo) {
            printf("snakes\n");
        } else if (sn < mo) {
            printf("mongooses\n");
        } else {
            printf("tie\n");
        }
    }
    return 0;
}
