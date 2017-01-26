#include <bits/stdc++.h>

using namespace std;

int n, m, k;
set<string> st;
char s[600];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        st.insert(string(s));
    }

    for (int i = 1; i <= m; ++i) {
        scanf("%s", s);
        if (st.count(string(s))) {
            ++k;
        }
    }

    if (n > m) {
        printf("YES\n");
    } else if (n < m) {
        printf("NO\n");
    } else if (k&1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
