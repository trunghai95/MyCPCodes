#include <bits/stdc++.h>

using namespace std;

char t[] = "Bulbasaur";
char s[100010];
int cnt[300];

int main() {
    scanf("%s", s);
    for (int i = 0; s[i]; ++i)
        ++cnt[s[i]];

    int res = 0;
    while (true) {
        for (int i = 0; i < 9; ++i) {
            if (cnt[t[i]] <= 0) {
                printf("%d\n", res);
                return 0;
            }

            --cnt[t[i]];
        }

        ++res;
    }
    return 0;
}
