#include <bits/stdc++.h>

using namespace std;

int a, b, res;

int main() {
    scanf("%d %d", &a, &b);

    while (a <= b) {
        ++res;
        a *= 3;
        b *= 2;
    }

    printf("%d\n", res);
    return 0;
}
