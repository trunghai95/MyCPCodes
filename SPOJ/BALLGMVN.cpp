// 80/100

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MAXN = 1000;
int n, x[MAXN*2 + 5], y[MAXN*2 + 5];
map<pii, int> mp[MAXN*2 + 1000];

void proc(int &x, int &y) {
    if (x == 0) {
        y = 1;
        return;
    }

    if (y == 0) {
        x = 1;
        return;
    }

    int g = __gcd(abs(x), abs(y));
    x /= g;
    y /= g;
    if (x < 0) x = -x, y = -y;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", x+i, y+i);
    }

    for (int i = n+1; i <= n*2; ++i) {
        scanf("%d %d", x+i, y+i);
        for (int j = 1; j <= n; ++j) {
            int xx = x[i] - x[j];
            int yy = y[i] - y[j];
            proc(xx, yy);
            mp[i][pii(xx, yy)] = j;
            mp[j][pii(xx, yy)] = i;
        }
    }

    for (int i = 1; i <= n; ++i)
    for (int j = i+1; j <= n; ++j) {
        int xx = x[i] - x[j];
        int yy = y[i] - y[j];
        proc(xx, yy);
        map<pii,int>::iterator it = mp[i].find(pii(xx, yy));

        if (it != mp[i].end()) {
            printf("%d %d %d\n", i, j, it->S);
            return 0;
        }
    }

    for (int i = n+1; i <= n*2; ++i)
    for (int j = i+1; j <= n*2; ++j) {
        int xx = x[i] - x[j];
        int yy = y[i] - y[j];
        proc(xx, yy);
        map<pii,int>::iterator it = mp[i].find(pii(xx, yy));

        if (it != mp[i].end()) {
            printf("%d %d %d\n", it->S, i, j);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
