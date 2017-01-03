#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100000;
int cntPrime[MAXN+5];

void init() {
    fill(cntPrime, cntPrime + MAXN + 1, 1);
    cntPrime[0] = cntPrime[1] = 0;
    for (ll i = 2; i <= MAXN; ++i) {
        if (cntPrime[i]) {
            for (ll j = i*i; j <= MAXN; j += i) {
                cntPrime[j] = 0;
            }
        }
        cntPrime[i] += cntPrime[i-1];
    }
}

int test, n;

int main() {
    init();
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);

        printf("%s\n", (cntPrime[n]&1) ? "Alice" : "Bob");
    }
    return 0;
}
