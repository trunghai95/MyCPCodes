#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);

    if (n&1) {
        printf("7");
        n = (n - 3) / 2;
    } else {
        n = n / 2;
    }

    while (n --> 0) {
        printf("1");
    }
    printf("\n");
    return 0;
}
