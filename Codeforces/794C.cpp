#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5;
char s[MAXN+2], t[MAXN+2], res[MAXN+2];
int n;

int main() {
    scanf("%s %s", s+1, t+1);
    n = strlen(s+1);

    int l1 = 1, l2 = 1, r2 = n / 2;
    int r1 = n - r2;
    int l = 1, r = n;

    sort(s+1, s+1+n);
    sort(t+1, t+1+n, greater<char>());

    while (true) {
        if (l == r) {
            res[l] = s[l1];
            break;
        }
        if (s[l1] < t[l2]) {
            res[l] = s[l1];
            ++l, ++l1;
        } else {
            res[r] = s[r1];
            --r, --r1;
        }
        if (l == r) {
            res[l] = t[l2];
            break;
        }
        if (t[l2] > s[l1]) {
            res[l] = t[l2];
            ++l, ++l2;
        } else {
            res[r] = t[r2];
            --r, --r2;
        }
    }

    printf("%s\n", res+1);
    return 0;
}
