#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100000;
const int MAX = 8500;
const ll MODD = 1e9 + 7;

vector<int> primes;
bool ck[MAX + 5];

void init() {
    for (int i = 2; i <= MAX; ++i)
    if (!ck[i]) {
        if (i) {
            primes.push_back(i);
        }
        for (int j = i*i; j <= MAX; j += i)
            ck[j] = true;
    }
}

int n, x, cnt[1001], test;
ll a[MAX+5], b[MAX+5];

int main() {
    init();

    scanf("%d", &test);
    while (test --> 0) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            ++cnt[x-3500];
        }

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        a[0] = 1;
        for (int i = 0; i <= 1000; ++i){
            int val = i + 3500;
            for (int j = 0; j <= MAX; ++j)
            if (a[j]) {
                int tmp = val^j;
                b[tmp] = (b[tmp] + a[j] * ((cnt[i] + 1) / 2)) % MODD;
                b[j] = (b[j] + a[j] * (cnt[i] / 2 + 1)) % MODD;
            }
            memcpy(a, b, sizeof(b));
            memset(b, 0, sizeof(b));
        }

        ll res = 0;
        for (int i = 0; i < (int)primes.size(); ++i) {
            res = (res + a[primes[i]]) % MODD;
        }

        printf("%lld\n", res);
    }
    return 0;
}
