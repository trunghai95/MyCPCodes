#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
char s[MAXN+2], t[MAXN+2];

int main() {
    scanf("%s %s", s, t);

    if (strcmp(s, t)) {
        printf("%d\n", (int)max(strlen(s), strlen(t)));
    } else {
        printf("-1\n");
    }
    return 0;
}
