#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int test, n;
char s[MAXN+2];

bool solve() {
    bool f = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'H') {
            if (!f) return false;
            f = false;
        } else if (s[i] == 'T') {
            if (f) return false;
            f = true;
        }
    }
    return f;
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %s", &n, s);
        printf("%s\n", solve()?"Valid":"Invalid");
    }
    return 0;
}
