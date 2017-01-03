#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main() {
    scanf("%d %d %d", &a, &b, &c);

    for (int i = 0; i <= a; ++i) {
        int j = b - i;
        int k = c - j;

        if (i + k != a || i < 0 || j < 0 || k < 0
            || (!i + !j + !k >= 2)) 
            continue;

        printf("%d %d %d\n", i, j, k);
        return 0;
    }

    printf("Impossible\n");
    return 0;
}
