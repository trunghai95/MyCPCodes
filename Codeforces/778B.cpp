#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1000;
const int MAXN = 5000;

int n, m, cnt[MAXM+2][2];
char s[MAXM+2], skip[4], t[20];
int f[MAXN+2][MAXM+2][2];
map<string,int> id;

void Swap(char *s, char *t) {
    for (int i = 0; s[i] || t[i]; ++i)
        swap(s[i], t[i]);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%s %s", s, skip);
        id[string(s)] = i;
        scanf("%s", s);

        if (s[0] == '0' || s[0] == '1') {
            for (int j = 0; j < m; ++j) {
                f[i][j][0] = f[i][j][1] = s[j] - '0';
            }
        } else {
            scanf("%s %s", skip, t);
            if (t[0] == '?') {
                Swap(s, t);
            }

            if (s[0] != '?') {
                int ss = id[string(s)];
                int tt = id[string(t)];
                if (skip[0] == 'X') {
                    for (int j = 0; j < m; ++j) {
                        f[i][j][0] = (f[ss][j][0] ^ f[tt][j][0]);
                        f[i][j][1] = (f[ss][j][1] ^ f[tt][j][1]);
                    }
                } else if (skip[0] == 'O') {
                    for (int j = 0; j < m; ++j) {
                        f[i][j][0] = (f[ss][j][0] | f[tt][j][0]);
                        f[i][j][1] = (f[ss][j][1] | f[tt][j][1]);
                    }
                } else {
                    for (int j = 0; j < m; ++j) {
                        f[i][j][0] = (f[ss][j][0] & f[tt][j][0]);
                        f[i][j][1] = (f[ss][j][1] & f[tt][j][1]);
                    }
                }
            } else if (t[0] == '?') {
                if (skip[0] == 'X') {
                    for (int j = 0; j < m; ++j) {
                        f[i][j][0] = f[i][j][1] = 0;
                    }
                } else {
                    for (int j = 0; j < m; ++j) {
                        f[i][j][0] = 0;
                        f[i][j][1] = 1;
                    }
                }
            } else {
                int tt = id[string(t)];
                if (skip[0] == 'X') {
                    for (int j = 0; j < m; ++j) {
                        f[i][j][0] = (0 ^ f[tt][j][0]);
                        f[i][j][1] = (1 ^ f[tt][j][1]);
                    }
                } else if (skip[0] == 'O') {
                    for (int j = 0; j < m; ++j) {
                        f[i][j][0] = (0 | f[tt][j][0]);
                        f[i][j][1] = (1 | f[tt][j][1]);
                    }
                } else {
                    for (int j = 0; j < m; ++j) {
                        f[i][j][0] = (0 & f[tt][j][0]);
                        f[i][j][1] = (1 & f[tt][j][1]);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    for (int j = 0; j < m; ++j) {
        cnt[j][0] += f[i][j][0];
        cnt[j][1] += f[i][j][1];
    }


    for (int i = 0; i < m; ++i) {
        if (cnt[i][0] <= cnt[i][1]) {
            printf("0");
        } else {
            printf("1");
        }
    }
    printf("\n");

    for (int i = 0; i < m; ++i) {
        if (cnt[i][0] >= cnt[i][1]) {
            printf("0");
        } else {
            printf("1");
        }
    }
    printf("\n");
    return 0;
}
