#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAXLEN = 505;
const ll MOD = 1000000007;

int test;
ll sum, pow10[MAXLEN];
char s[MAXLEN], b[MAXLEN], tmp[MAXLEN];
bool mark[MAXLEN];

void init() {
    pow10[0] = 1;
    for (int i = 1; i < MAXLEN; i++) {
        pow10[i] = (pow10[i-1] * 10) % MOD;
    }
}

ll getSum(int sIndex, int bIndex) {
    if (s[sIndex] > b[bIndex]) {
        return 0;
    }
    if (s[sIndex] < b[bIndex]) {
        sum = sum + ((ll)(s[sIndex]-'0') * pow10[strlen(b) - 1 - bIndex]) % MOD;
    }
}

ll solve() {
    scanf("%s %s", s, b);
    memset(mark, 0, sizeof(mark));

    while (strlen(b) < strlen(s)) {
        strcpy(tmp, b);
        sprintf(b, "0%s", tmp);
    }

    if (strlen(b) > strlen(s)) {
        //...
    }
}

int main() {
    scanf("%d\n", &test);
    while (test --> 0) {
        printf("%lld\n", solve());
    }
    return 0;
}