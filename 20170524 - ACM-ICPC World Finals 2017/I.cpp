#include <bits/stdc++.h>

using namespace std;

int n, q;
bool e[26][26];
char s[100], t[100];

bool solve() {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    for (int i = 0; s[i]; ++i)
    if (!e[s[i]-'a'][t[i]-'a']) {
        return false;
    }

    return true;
}

int main() {
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; ++i) {
        scanf("%s %s", s, t);
        e[s[0]-'a'][t[0]-'a'] = true;
    }

    for (int i = 0; i < 26; ++i) e[i][i] = true;

    for (int k = 0; k < 26; ++k)
    for (int i = 0; i < 26; ++i)
    for (int j = 0; j < 26; ++j)
    if (e[i][k] && e[k][j]) {
        e[i][j] = true;
    }

    while (q --> 0) {
        scanf("%s %s", s, t);
        printf("%s\n", solve()?"yes":"no");
    }
    return 0;
}
