#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int n, f[MAXN+2];

void try1() {
    for (int i = 1; i <= n; ++i) {
        if (f[i] != i)
            return;
    }

    printf("%d\n", n);
    for (int i = 1; i <= n; ++i)
        printf("%d ", i);
    printf("\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", i);
    printf("\n");
    exit(0);
}

void try2() {
    for (int i = 2; i <= n; ++i) {
        if (f[i] != f[i-1])
            return;
    }

    printf("1\n");
    for (int i = 1; i <= n; ++i)
        printf("1 ");
    printf("\n%d\n", f[1]);
    exit(0);
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", f+i);
    }

    try1();
    try2();

    printf("-1\n");
    return 0;
}
