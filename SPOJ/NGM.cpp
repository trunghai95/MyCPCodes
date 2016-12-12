#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    n = n%10;
    if (n) {
        printf("1\n%d\n", n);
    } else {
        printf("2\n");
    }
    return 0;
}
