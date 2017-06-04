#include <bits/stdc++.h>

using namespace std;

int n, k;
char s[1005], p[1005][2005];

int main() {
    scanf("%d %d %s", &n, &k, s);
    p[0][1000] = 'D';
    int lo = 1001 - k, hi = 999 + k;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            for (int j = lo; j <= hi; ++j)
            if (p[i][j]) {
                p[i+1][j] = 'D';
                p[i+1][j+1] = 'W';
                p[i+1][j-1] = 'L';
            }
        } else if (s[i] == 'W') {
            for (int j = lo; j <= hi; ++j)
            if (p[i][j]) {
                p[i+1][j+1] = 'W';
            }
        } else if (s[i] == 'L') {
            for (int j = lo; j <= hi; ++j)
            if (p[i][j]) {
                p[i+1][j-1] = 'L';
            }
        } else {
            for (int j = lo; j <= hi; ++j)
            if (p[i][j]) {
                p[i+1][j] = 'D';
            }
        }
    }

    int cur = -1;
    --lo, ++hi;
    if (p[n][lo]) {
        cur = lo;
    } else if (p[n][hi]) {
        cur = hi;
    } else {
        printf("NO\n");
        return 0;
    }

    string res;
    for (int i = n; i > 0; --i) {
        res.push_back(p[i][cur]);
        if (p[i][cur] == 'W') --cur;
        else if (p[i][cur] == 'L') ++cur;
    }

    reverse(res.begin(), res.end());
    printf("%s\n", res.c_str());
    return 0;
}
