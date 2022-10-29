#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

#define pii pair<int,int>
#define ll long long
const int MAXN = 1e5;
int n, k;
ll bit[MAXN][11];
pii r[MAXN];

void update(int a, int b, ll val) {
    // printf("update %d %d %d\n", a, b, val);
    while (a <= n) {
        bit[a][b] += val;
        a += (a & (-a));
    }
}

ll get(int a, int b) {
    ll ret = 0;
    while (a > 0) {
        ret += bit[a][b];
        a -= (a & (-a));
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &r[i].first, &r[i].second);
    }
    sort(r, r+n);

    for (int i = 0; i < n; i++) {
        update(r[i].second, 1, 1);
        for (int j = 2; j <= k; j++) {
            update(r[i].second, j, get(r[i].second-1, j-1));
        }
    }

    printf("%lld\n", get(n, k));
    return 0;
}