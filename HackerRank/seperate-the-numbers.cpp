#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 32;
int test, n;
char s[MAXN+2];

bool Try(char* s, ll start) {
    if (!s[0]) {
        return true;
    }

    if (s[0] == '0') {
        return false;
    }

    ll cur = 0;

    while (s[0] && cur < start) {
        cur = cur * 10 + s[0] - '0';
        ++s;
    }

    if (cur == start) {
        return Try(s, start + 1);
    }

    return false;
}

ll solve() {
    if (s[0] != '0') {
        ll start = 0;
        for (int i = 0; i < n/2; ++i) {
            start = start * 10 + s[i] - '0';
            if (Try(s+i+1, start + 1)) {
                return start;
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%s", s);
        n = strlen(s);
        ll x = solve();
        if (x < 0) {
            printf("NO\n");
        } else {
            printf("YES %lld\n", x);
        }
    }
    return 0;
}
