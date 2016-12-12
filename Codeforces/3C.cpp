#include <bits/stdc++.h>

using namespace std;

char s[5][5];
int cntx, cnt0;
bool wx, w0;

int main() {

    for (int i = 0; i < 3; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < 3; ++j) {
            if (s[i][j] == 'X') ++cntx;
            else if (s[i][j] == '0') ++cnt0;
        }
    }

    if (cntx < cnt0 || cntx > cnt0 + 1) {
        printf("illegal\n");
        return 0;
    }

    for (int i = 0; i < 3; ++i) {
        if ((s[i][0] == s[i][1] && s[i][0] == s[i][2] && s[i][0] == 'X')
            || (s[0][i] == s[1][i] && s[0][i] == s[2][i] && s[0][i] == 'X')) {
            wx = true;
        }
        if ((s[i][0] == s[i][1] && s[i][0] == s[i][2] && s[i][0] == '0')
            || (s[0][i] == s[1][i] && s[0][i] == s[2][i] && s[0][i] == '0')) {
            w0 = true;
        }
    }

    if (s[0][0] == s[1][1] && s[0][0] == s[2][2] && s[0][0] == 'X') wx = true;
    if (s[0][2] == s[1][1] && s[0][2] == s[2][0] && s[0][2] == 'X') wx = true;
    if (s[0][0] == s[1][1] && s[0][0] == s[2][2] && s[0][0] == '0') w0 = true;
    if (s[0][2] == s[1][1] && s[0][2] == s[2][0] && s[0][2] == '0') w0 = true;

    if (wx) {
        if (w0 || cntx == cnt0) {
            printf("illegal\n");
        } else {
            printf("the first player won\n");
        }
    } else if (w0) {
        if (cntx > cnt0) {
            printf("illegal\n");
        } else {
            printf("the second player won\n");
        }
    } else if (cntx + cnt0 == 9) {
        printf("draw\n");
    } else if (cntx == cnt0) {
        printf("first\n");
    } else {
        printf("second\n");
    }

    return 0;
}
