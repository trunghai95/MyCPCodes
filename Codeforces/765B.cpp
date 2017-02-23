#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
char s[MAXN+2];
bool ck[MAXN+2];

int main() {
    scanf("%s", s);

    for (int i = 0; s[i]; ++i) {
        ck[s[i]] = true;
    }

    for (char c = 'b'; c <= 'z'; ++c) {
        if (ck[c] && !ck[c-1]) {
            printf("NO\n");
            return 0;
        }
    }

    char cur = 'a';

    for (int i = 0; s[i]; ++i) {
        if (s[i] > cur) {
            printf("NO\n");
            return 0;
        }

        if (s[i] == cur) ++cur;
    }

    printf("YES\n");
    return 0;
}
