#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const int MAXN = 1e6;
char s[MAXN+2];
ll res, cnt;

int main() {
    scanf("%s", s);

    for (int i = strlen(s) - 1; i >= 0; --i) {
        if (s[i] == 'b') {
            cnt = (cnt + 1) % MODD;
        } else {
            res = (res + cnt) % MODD;
            cnt = (cnt * 2) % MODD;
        }
    }

    printf("%lld\n", res);
    return 0;
}
