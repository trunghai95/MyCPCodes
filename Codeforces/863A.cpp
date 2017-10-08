#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
char s[MAXN+2];
int n;

int main() {
    scanf("%s", s);
    n = strlen(s);
    int r = n-1;
    int l = 0;

    while (s[r] == '0') {
        --r;
    }

    while (l < r) {
        if (s[l] != s[r]) {
            printf("NO\n");
            return 0;
        }
        ++l;
        --r;
    }

    printf("YES\n");
    return 0;
}
