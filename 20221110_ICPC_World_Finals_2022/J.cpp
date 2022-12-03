#include <cstdio>

using namespace std;

#define ll long long

struct Output {
    ll length = -1;
    int type = 0;
    int input1, input2;
};

const int MAXN = 30004;
const int S1 = 1;
const int S2 = 2;
const int M = 3;

int m, n, q, x, y, z;
Output out[MAXN];
char s[5];

ll getLen(int x) {
    if (x == 1) {
        return m;
    }
    if (out[x].length >= 0) {
        return out[x].length;
    }
    if (out[x].type == 0) {
        return out[x].length = 0;
    }
    if (out[x].type == M) {
        return getLen(out[x].input1) + getLen(out[x].input2);
    }
    if (out[x].type == S1) {
        return (getLen(out[x].input1) - 1)/2 + 1;
    }
    return getLen(out[x].input1) / 2;
}

void solve(int x, ll k) {
    ll l = getLen(x);
    // printf("--%d %d %d\n", x, k, l);
    if (k > l) {
        printf("none\n");
        return;
    }
    if (x == 1) {
        printf("%lld\n", k);
        return;
    }
    if (out[x].type == M) {
        ll l1 = getLen(out[x].input1);
        ll l2 = getLen(out[x].input2);
        if (l1 <= l2 && k > l1*2) {
            solve(out[x].input2, k - l1);
        } else if (l1 > l2 && k > l2*2) {
            solve(out[x].input1, k - l2);
        } else if (k % 2 == 0) {
            solve(out[x].input2, k/2);
        } else {
            solve(out[x].input1, (k+1)/2);
        }
    } else if (out[x].type == S1) {
        solve(out[x].input1, k*2 - 1);
    } else {
        // S2
        solve(out[x].input1, k*2);
    }
}

int main() {
    scanf("%d %d %d", &m, &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", s, &x, &y, &z);
        if (s[0] == 'S') {
            out[y].type = S1;
            out[y].input1 = x;
            out[z].type = S2;
            out[z].input1 = x;
        } else {
            out[z].type = M;
            out[z].input1 = x;
            out[z].input2 = y;
        }
    }

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &x, &y);
        solve(x, y);
    }
    return 0;
}