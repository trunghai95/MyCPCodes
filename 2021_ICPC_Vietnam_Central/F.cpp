#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 100005;

int n, pos[300];
char s[MAXN];
ll lef[MAXN], rig[MAXN];

ll solve() {
    int len = strlen(s);
    memset(pos, -1, sizeof(pos));
    for (int i = 0; i < len; i++) {
        if (pos[s[i]] == -1) {
            lef[i] = i + 1;
        } else {
            lef[i] = i - pos[s[i]];
        }

        pos[s[i]] = i;
    }
    memset(pos, -1, sizeof(pos));
    for (int i = len - 1; i >= 0; i--) {
        if (pos[s[i]] == -1) {
            rig[i] = len - i;
        } else {
            rig[i] = pos[s[i]] - i;
        }

        pos[s[i]] = i;
    }

    ll res = 0;
    for (int i = 0; i < len; i++) {
        // printf("%d %lld %lld\n", i, lef[i], rig[i]);
        res += lef[i] * rig[i];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    while (n --> 0) {
        scanf("%s", s);
        printf("%lld\n", solve());
    }
    return 0;
}