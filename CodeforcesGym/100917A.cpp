#include <bits/stdc++.h>

using namespace std;

struct Paint {
    int a, b, c;
    Paint() {}
    Paint(int a, int b, int c): a(a), b(b), c(c) {}
};

int n;
char s[3002][3002];
int cnt[2][3002][27];
bool done[2][3002];
vector<Paint> res;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= n; ++j) {
            if (s[i][j] != '?') {
                ++cnt[0][i][s[i][j] - 'a'];
                ++cnt[1][j][s[i][j] - 'a'];
            }
        }
    }

    while (res.size() < n*2) {
        int r1 = -1, r2 = -1, r3 = -1;
        for (int i = 1; i <= n; ++i)
        if (!done[0][i]) {
            int cc = -1;
            for (int j = 0; j < 26; ++j)
            if (cnt[0][i][j]) {
                if (cc == -1) cc = j;
                else { cc = -2; break; }
            }

            if (cc == -1) {
                done[0][i] = true;
                r1 = 0, r2 = i, r3 = 0;
                break;
            } else if (cc != -2) {
                done[0][i] = true;
                r1 = 0, r2 = i, r3 = cc;
                break;
            }
        }

        for (int i = 1; r1 == -1 && i <= n; ++i)
        if (!done[1][i]) {
            int cc = -1;
            for (int j = 0; j < 26; ++j)
            if (cnt[1][i][j]) {
                if (cc == -1) cc = j;
                else { cc = -2; break; }
            }

            if (cc == -1) {
                done[1][i] = true;
                r1 = 1, r2 = i, r3 = 0;
                break;
            } else if (cc != -2) {
                done[1][i] = true;
                r1 = 1, r2 = i, r3 = cc;
                break;
            }
        }

        res.push_back(Paint(r1, r2, r3));
        if (r1) {
            for (int i = 1; i <= n; ++i) {
                if (s[i][r2] != '?') {
                    --cnt[0][i][s[i][r2] - 'a'];
                }
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                if (s[r2][i] != '?') {
                    --cnt[1][i][s[r2][i] - 'a'];
                }
            }
        }
    }

    for (int i = (int)res.size() - 1; i >= 0; --i) {
        printf("%c %d %c\n", res[i].a?'v':'h', res[i].b, 'a' + res[i].c);
    }
    return 0;
}