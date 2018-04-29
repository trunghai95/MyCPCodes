#include <bits/stdc++.h>

using namespace std;

const int MAXN = 25;
int test, n, m;
char s[MAXN+2][MAXN+2];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s[i]+1);
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j <= m; ++j) {
                if (s[i][j] == '?') {
                    s[i][j] = s[i][j-1];
                }
            }

            for (int j = m-1; j >= 1; --j) {
                if (s[i][j] == '?') {
                    s[i][j] = s[i][j+1];
                }
            }
        }

        for (int j = 1; j <= m; ++j) {
            for (int i = 2; i <= n; ++i) {
                if (s[i][j] == '?') {
                    s[i][j] = s[i-1][j];
                }
            }

            for (int i = n-1; i >= 1; --i) {
                if (s[i][j] == '?') {
                    s[i][j] = s[i+1][j];
                }
            }
        }

        printf("Case #%d:\n", tt);
        for (int i = 1; i <= n; ++i) {
            printf("%s\n", s[i]+1);
        }
    }
    return 0;
}
