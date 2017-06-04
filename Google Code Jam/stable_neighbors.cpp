#include <bits/stdc++.h>

using namespace std;

int n, a[6], test;
char c[] = "ROYGBV";

void solve(int i, int j, int k) {
    string s(a[i], c[i]);
    
    for (int ii = 0; a[j] > 0 && ii < (int)s.length(); ++ii) {
        if (s[ii] != c[j]) {
            s.insert(ii+1, 1, c[j]);
            --a[j];
        }
    }

    for (int ii = (int)s.length() - 1; a[k] > 0 && ii >= 0; --ii) {
        if (s[ii] == c[i]) {
            s.insert(ii+1, 1, c[k]);
            --a[k];
        }
    }

    for (int ii = 1; ii < (int)s.length(); ++ii) {
        if (s[ii] == s[ii-1]) {
            printf("IMPOSSIBLE\n");
            return;
        }
    }

    if (s[0] == s[s.length() - 1]) {
        printf("IMPOSSIBLE\n");
    } else {
        printf("%s\n", s.c_str());
    }
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d", &n);
        for (int i = 0; i < 6; ++i) {
            scanf("%d", a+i);
        }

        printf("Case #%d: ", tt);
        if (a[0] >= a[2] && a[0] >= a[4]) {
            solve(0, 2, 4);
        } else if (a[2] >= a[0] && a[2] >= a[4]) {
            solve(2, 0, 4);
        } else {
            solve(4, 0, 2);
        }
    }
    return 0;
}
