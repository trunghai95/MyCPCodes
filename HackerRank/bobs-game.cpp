#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int test, n, g[MAXN+2][MAXN+2], sumxor;
char s[MAXN+3][MAXN+3];
bool ck[4];

int dx[] = {-1, -1, 0};
int dy[] = {0, -1, -1};

bool valid(int x, int y) {
    return x > 0 && y > 0 && s[x][y] != 'X';
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);

        sumxor = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s[i]+1);

            for (int j = 1; j <= n; ++j)
            if (s[i][j] != 'X') {
                ck[0] = ck[1] = ck[2] = ck[3] = 0;
                for (int d = 0; d < 3; ++d) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if (valid(x, y)) {
                        ck[g[x][y]] = true;
                    }
                }

                for (int k = 0; k < 4; ++k)
                if (!ck[k]) {
                    g[i][j] = k;
                    break;
                }

                if (s[i][j] == 'K') {
                    sumxor ^= g[i][j];
                }
            }
        }

        if (sumxor == 0) {
            printf("LOSE\n");
            continue;
        }

        int res = 0;

        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        if (s[i][j] == 'K')
        for (int d = 0; d < 3; ++d) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (valid(x, y) && sumxor == (g[i][j] ^ g[x][y])) {
                ++res;
            }
        }

        printf("WIN %d\n", res);
    }
    return 0;
}
