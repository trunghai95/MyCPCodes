#include <bits/stdc++.h>

using namespace std;

int test, n;

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);
        if (n >= 38) {
            int m = n/5*5;
            if (n - m >= 3) {
                n = m + 5;
            }
        }

        printf("%d\n", n);
    }
    return 0;
}
