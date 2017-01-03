#include <bits/stdc++.h>

using namespace std;

char s[200];
int res = 1;

int main() {
    scanf("%s", s);

    for (int i = 0; s[i]; ++i) {
        if (s[i] == '_')
            ++res;
    }

    printf("%d\n", res);
    return 0;
}
