#include <bits/stdc++.h>

using namespace std;

int n, m, k, a;

bool check() {
    scanf("%d", &k);
    set<int> s;
    bool res = true;

    for (int i = 0; i < k; ++i) {
        scanf("%d", &a);
        if (a == 0) {
            continue;
        }
        if (s.count(-a)) {
            res = false;
        }
        s.insert(a);
    }

    return res;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        if (check()) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
