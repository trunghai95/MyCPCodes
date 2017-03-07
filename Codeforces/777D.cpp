#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500000;
int n;
string s[MAXN+2];
char t[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%s", t);
        s[i] = string(t);
    }

    for (int i = n-1, j; i >= 1; --i) {
        int len = min(s[i].length(), s[i+1].length());

        for (j = 1; j < len; ++j) {
            if (s[i][j] < s[i+1][j]) {
                break;
            } else if (s[i][j] > s[i+1][j]) {
                s[i] = s[i].substr(0, j);
                break;
            }
        }

        if (j == len && s[i].length() > s[i+1].length()) {
            s[i] = s[i].substr(0, s[i+1].length());
        }
    }

    for (int i = 1; i <= n; ++i) {
        printf("%s\n", s[i].c_str());
    }
    return 0;
}
