#include <bits/stdc++.h>

using namespace std;

char s[30];
int pos1, pos2, p[30];
char res[2][20];

int main() {
    scanf("%s", s+1);
    for (int i = 1; i <= 27; ++i) {
        if (p[s[i]-'A']) {
            pos1 = p[s[i]-'A'];
            pos2 = i;
            break;
        } else {
            p[s[i]-'A'] = i;
        }
    }

    int tmp = pos2 - pos1 - 1;
    if (!tmp) {
        printf("Impossible\n");
        return 0;
    }

    tmp = tmp / 2;
    int c = 13 - tmp;
    for (int i = pos1; i <= pos1 + tmp; ++i) {
        res[0][c++] = s[i];
    }

    c = 13;
    for (int i = pos1 + tmp + 1; i < pos2; ++i) {
        res[1][c--] = s[i];
    }

    int i = pos2 + 1;
    if (i > 27) i = 1;
    for (; c > 0; --c) {
        res[1][c] = s[i];
        if (++i > 27) i = 1;
    }

    c = 1;
    for (; !res[0][c]; ++c) {
        res[0][c] = s[i];
        if (++i > 27) i = 1;
    }

    res[0][14] = res[1][14] = 0;
    printf("%s\n%s\n", res[0] + 1, res[1] + 1);
    return 0;
}
