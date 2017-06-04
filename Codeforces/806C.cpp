#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXP = 40;
int n, cnt[MAXP+4], sm[MAXP+4];
ll a;

void prepare() {
    scanf("%d", &n);
    int j = 0;
    ll cur = 1;

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a);
        while (a > cur) {
            cur = cur * 2;
            ++j;
        }
        if (a == cur) {
            ++cnt[j];
        } else {
            ++sm[j];
        }
    }
}

bool check(int c) {
    int s = 0;
    // cout << "+++ " << c << '\n';
    for (int i = 0; i <= MAXP; ++i) {
        if (cnt[i] < c) {
            s += sm[i];
            s -= min(s, c - cnt[i]);
            c = cnt[i];
        } else {
            s += cnt[i] - c + sm[i];
        }
    }
    return (s == 0);
}

int main() {
    prepare();

    bool f = false;
    for (int i = 1; i <= cnt[0]; ++i) {
        if (check(i)) {
            printf("%d ", i);
            f = true;
        }
    }
    if (!f) printf("-1");
    printf("\n");
    return 0;
}
