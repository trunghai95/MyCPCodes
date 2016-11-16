// WA

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n;
char s[MAXN+5][MAXN+5];

void flip(char &c) {
    if (c == '1') c = '0';
    else c = '1';
}

bool solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i + 1; ++j)
        if (s[i][j] == '0') {
            if (j == n - i + 1) {
                for (int i = 1; i <= n; ++i)
                    printf("%s\n", s[i]+1);
                return false;
            }

            flip(s[i][j]);
            flip(s[i][j+1]);
            flip(s[i+1][j]);
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%s\n", s[i]+1);
    return true;
}

int main() {
    int tt = 0;

    while (true) {
        scanf("%d", &n);
        if (!n) return 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
        }

        printf("Triangle %d can%s be filled.\n", ++tt, solve()?"":"not");
    }
    return 0;
}
