#include <bits/stdc++.h>

using namespace std;

int test, a, b, n;
char s[20];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d %d", &a, &b, &n);
        ++a;

        while (a <= b) {
            int m = (a+b)/2;
            printf("%d\n", m);
            fflush(stdout);
            scanf("%s", s);
            if (s[0] == 'C') {
                break;
            } else if (s[0] == 'W') {
                return 0;
            } else if (s[4] == 'S') {
                a = m+1;
            } else {
                b = m-1;
            }
        }
    }
    return 0;
}