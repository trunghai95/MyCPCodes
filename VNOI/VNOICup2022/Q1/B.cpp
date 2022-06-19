#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define ll long long

const int MAXN = 2000005;

int n, c[MAXN], cntMul[MAXN], cntVal[MAXN];
vector<int> primes;

int main() {
    memset(cntMul, 0, sizeof(cntMul));
    memset(cntVal, 0, sizeof(cntVal));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", c+i);
        cntVal[c[i]]++;
    }

    for (int i = 2; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            cntMul[i] += cntVal[j];
        }
    }

    for (int i = 0; i < n; i++) {
        ll cnt = cntMul[c[i]*2];
        // for (int j = 0; j < n; j++) {
        //     if (c[j] % (c[i]*2) == 0) {
        //         cnt++;
        //     }
        // }
        printf("%lld ", cnt*(cnt-1)/2);
    }
    printf("\n");

    return 0;
}