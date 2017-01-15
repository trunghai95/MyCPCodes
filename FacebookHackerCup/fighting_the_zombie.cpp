#include <bits/stdc++.h>

using namespace std;

const int MAXX = 20;
const int MAXY = 20;
int yval[] = {4,6,8,10,12,20};
double f[MAXX+2][MAXY+2][MAXX*MAXY+2];

void init() {
    for (int ii = 0; ii < 6; ++ii) {
        int y = yval[ii];
        f[0][y][0] = 1;
        for (int x = 0; x < MAXX; ++x) {
            for (int i = x; i <= x*y; ++i)
            for (int j = 1; j <= y; ++j) {
                f[x+1][y][i+j] += f[x][y][i] / (1.0 * y);
            }
        }

        for (int x = 1; x <= MAXX; ++x) {
            for (int i = x*y; i >= x; --i)
                f[x][y][i] += f[x][y][i+1];
        }
    }
}

int test, h, n, x, y, k;
char s[20];

void proc() {
    int i = x = y = k = 0;
    while (true) {
        if (s[i] == 'd') {
            ++i;
            break;
        }
        x = x*10 + s[i] - '0';
        ++i;
    }

    while (s[i] && s[i] != '-' && s[i] != '+') {
        y = y*10 + s[i] - '0';
        ++i;
    }

    if (!s[i]) return;
    int sign = (s[i] == '+') ? 1 : -1;
    ++i;
    while (s[i]) {
        k = k*10 + s[i] - '0';
        ++i;
    }
    k *= sign;
}

double solve(int x, int y, int k) {
    if (k < x) return 1.0;
    if (k > x*y) return 0.0;
    return f[x][y][k];
}

int main() {
    init();
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &h, &n);
        double res = 0;
        while (n --> 0) {
            scanf("%s", s);
            proc();
            res = max(res, solve(x, y, h-k));
        }

        printf("Case #%d: %.6lf\n", tt, res);
    }
    return 0;
}
