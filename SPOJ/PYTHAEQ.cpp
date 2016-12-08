#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll r, res;
ll m[3][3][3] = {{{1, -2, 2}, {2, -1, 2}, {2, -2, 3}}, 
                {{1, 2, 2}, {2, 1, 2}, {2, 2, 3}},
                {{-1, 2, 2}, {-2, 1, 2}, {-2, 2, 3}}};

void Try(const ll &a, const ll &b, const ll &c) {
    if (r % c == 0) res += 8;
    if (c >= r) return;

    ll aa, bb, cc;
    for (int i = 0; i < 3; ++i) {
        aa = m[i][0][0]*a + m[i][0][1]*b + m[i][0][2]*c;
        bb = m[i][1][0]*a + m[i][1][1]*b + m[i][1][2]*c;
        cc = m[i][2][0]*a + m[i][2][1]*b + m[i][2][2]*c;
        Try(aa, bb, cc);
    }
}

int main() {
    scanf("%lld", &r);
    if (r == 0) {
        printf("1\n");
        return 0;
    }

    r = abs(r);
    res = 4;
    Try(3, 4, 5);

    printf("\n%lld\n", res);
    return 0;
}
