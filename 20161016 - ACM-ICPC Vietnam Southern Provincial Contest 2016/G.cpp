#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXBIT = 64;

ll calCntExactBit(ll bound, int ones){
    int bits[MAXBIT + 1], pos = 0;
    for (int i = 0; i < MAXBIT; ++i)
        bits[i] = (bound >> i) & 1;
    reverse(bits, bits + MAXBIT);
    ll f[MAXBIT][MAXBIT];
    memset(f, 0, sizeof(f));
    int cntOnes = 0;

    f[0][1] = (bits[0] == 1);
    for (int i = 0; i < MAXBIT - 1; ++i){
        for (int j = 0; j < MAXBIT - 1; ++j){
            f[i + 1][j] += f[i][j];
            f[i + 1][j + 1] += f[i][j];
        }
        cntOnes += (bits[i] == 1);
        if (bits[i + 1] == 1)
            ++f[i + 1][cntOnes];
    }
    return f[MAXBIT - 1][ones];
}

ll cntExactBit(ll lef, ll rig, int ones){
    if (lef > rig) {
        return 0;
    }
    return calCntExactBit(rig + 1, ones) - calCntExactBit(lef, ones);
}

int test;
ll a, b;

int main(){
    //freopen("in.txt", "r", stdin);

    scanf("%d", &test);

    while (test --> 0) {
        scanf("%lld %lld", &a, &b);
        ll n = b - a + 1;

        double res = 0;
        for (int x = 1; x < MAXBIT; ++x)
        for (int y = 1; y <= x; ++y) {
            ll cnt = cntExactBit(max(a, (1LL << (x-1))), min(b, (1LL << x) - 1), y);
            res += 1.0*cnt/n*y/x;
        }
        printf("%.3lf\n", res);
    }
    return 0;
}
    