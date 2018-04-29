#include <bits/stdc++.h>

using namespace std;

int h, m, s;
char a[5];

int main() {
    scanf("%d:%d:%d%s", &h, &m, &s, a);
    if (h == 12) {
        if (a[0] == 'A') {
            h = 0;
        }
    } else if (a[0] == 'P') {
        h += 12;
    }
    printf("%02d:%02d:%02d\n", h, m, s);
    return 0;
}