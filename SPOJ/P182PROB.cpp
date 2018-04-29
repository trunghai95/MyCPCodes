#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int n, a;
ll c[3], res;
map<int, int> cnt;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++cnt[a];
    }
    map<int,int>::iterator it;
    int i = 0;
    for (it = cnt.begin(); it != cnt.end() && i < 3; it++, i++) {
        c[i] = it->second;
    }
    if (c[0] > 2) {
        res = c[0]*(c[0]-1)*(c[0]-2)/6;
    } else if (c[0] == 2) {
        res = c[1]*2;
    } else {
        // c[0] == 1
        if (c[1] > 1) {
            res = c[1]*(c[1]-1)/2;
        } else {
            // c[1] == 1
            res = c[2];
        }
    }

    printf("%lld\n", res);
    return 0;
}