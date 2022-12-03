#include <bits/stdc++.h>

using namespace std;

int y, fact[10], cur, rescnt[10];

void init() {
    fact[0] = 1;
    for (int i = 1; i < 10; i++) {
        fact[i] = fact[i-1]*i;
    }
}

int main() {
    init();
    scanf("%d", &y);
    if (y == 1) {
        printf("0\n");
        return 0;
    }

    for (int i = 9; i >= 0; i--) {
        if (fact[i] <= y) {
            rescnt[i] += y / fact[i];
            y -= fact[i] * rescnt[i];
        }
    }

    // for (int i = 0; i < 10; i++) {
    //     printf("%d:%d\n", i, rescnt[i]);
    // }

    if (rescnt[1] > 0) {
        rescnt[0] += rescnt[1] - 1;
        rescnt[1] = 1;
    }

    for (int i = 1; i < 10; i++) {
        if (rescnt[i] > 0) {
            printf("%d", i);
            rescnt[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < rescnt[i]; j++) {
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}