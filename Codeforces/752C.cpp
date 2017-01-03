#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int n;
char s[MAXN+5];

int main() {
    scanf("%d %s", &n, s);

    int res = 1;
    char dx = 0, dy = 0;

    for (int i = 0; s[i]; ++i) {
        if (s[i] == 'L' || s[i] == 'R') {
            if (!dx) {
                dx = s[i];
            } else if (dx != s[i]) {
                dy = 0;
                dx = s[i];
                ++res;
            }
        } else {
            if (!dy) {
                dy = s[i];
            } else if (dy != s[i]) {
                dy = s[i];
                dx = 0;
                ++res;
            }
        }
        // cout << res << ' ' << i << ' ' << s[i] << ' ' << dx << ' ' << dy << '\n';
    }

    printf("%d\n", res);
    return 0;
}
