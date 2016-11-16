#include <bits/stdc++.h>

using namespace std;

int n, cnt[300];
char s[100010];

int main() {
    scanf("%d %s", &n, s);

    for (int i = 0; i < n; ++i) {
        ++cnt[s[i]];
    }

    if (cnt['A'] > cnt['D'])
        cout << "Anton\n";
    else if (cnt['A'] < cnt['D'])
        cout << "Danik\n";
    else
        cout << "Friendship\n";
    return 0;
}
