#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
const int MAXLEN = 20;
int n, m, q, p[MAXN*2 + 2], rk[MAXN*2 + 2], type;
map<string, int> id;
char s[MAXLEN + 2];

int find(int x) {
    return (x == p[x] ? x : (p[x] = find(p[x])));
}

bool join(int x, int y, int t) {
    // cout << "++ " << x << ' ' << y << ' ' << t << '\n';
    x = find(x);
    y = find(y);

    int x_ = (x > n ? x - n : x + n);
    int y_ = (y > n ? y - n : y + n);
    // cout << x << ' ' << y << ' ' << x_ << ' ' << y_ << '\n';

    if (t == 1) {
        if (x == y_) {
            return false;
        } else if (x == y) {
            return true;
        }
        if (rk[x] + rk[x_] > rk[y] + rk[y_]) swap(x, y), swap(x_, y_);
        p[x] = y;
        p[x_] = y_;
        rk[y] += rk[x];
        rk[y_] += rk[x_];
    } else {
        if (x == y) {
            return false;
        } else if (x == y_) {
            return true;
        }

        if (rk[x] + rk[x_] > rk[y] + rk[y_]) swap(x, y), swap(x_, y_);
        p[x] = y_;
        p[x_] = y;
        rk[y_] += rk[x];
        rk[y] += rk[x_];
    }

    return true;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        id[string(s)] = i;
    }

    for (int i = 1; i <= n*2; ++i) {
        p[i] = i;
        rk[i] = 1;
    }

    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d %s", &type, s);
        u = id[string(s)];
        scanf("%s", s);
        v = id[string(s)];

        if (join(u, v, type)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    for (int i = 0, u, v; i < q; ++i) {
        scanf("%s", s);
        u = id[string(s)];
        scanf("%s", s);
        v = id[string(s)];

        u = find(u);
        v = find(v);
        if (u == v) {
            printf("1\n");
        } else if (abs(u - v) == n) {
            printf("2\n");
        } else {
            printf("3\n");
        }
    }
    return 0;
}
