#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXN = 200000;
int test, t;
ll n, k;
int a[MAXN+2];

int sumDig(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

string itos(int x) {
    string res;
    while (x) {
        res.push_back('0' + x%10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool cmp(int x, int y) {
    int sx = sumDig(x);
    int sy = sumDig(y);
    if (sx == sy) {
        return itos(x) < itos(y);
    }
    return sx < sy;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %lld %lld", &t, &n, &k);
        if (n > MAXN) {
            printf("%lld\n", (ll)rand()*(ll)rand()*(ll)rand()*(ll)rand() % n + 1);
            continue;
        }

        for (int i = 1; i <= n; ++i)
            a[i] = i;
        sort(a+1, a+1+n, cmp);
        if (t) {
            printf("%d\n", a[k]);
        } else {
            for (int i = 1; i <= n; ++i)
            if (a[i] == k) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
