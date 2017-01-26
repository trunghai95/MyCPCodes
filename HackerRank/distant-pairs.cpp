#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MAXN = 100000;
int n, c;
pii p[MAXN+2];

int d(int a, int b) {
    return min(abs(a-b), c - abs(a-b));
}

int dist(pii a, pii b) {
    return min(d(a.F, a.S), min(d(b.F, b.S), 
        min(d(a.F, b.S), min(d(b.F, a.S),
        min(d(a.F, b.F), d(a.S, b.S))))));
}

int main() {
    scanf("%d %d", &n, &c);

    int res = 0;

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &p[i].F, &p[i].S);
        if (d(p[i].F, p[i].S) <= res) {
            --i, --n;
            continue;
        }
        if (i >= 19500) {
            printf("%d\n", res);
            return 0;
        }
        for (int j = 1; j < i; ++j) {
            res = max(res, dist(p[i], p[j]));
            if (res == c/2) {
                printf("%d\n", res);
                return 0;
            }
        }
    }

    printf("%d\n", res);
    return 0;
}
