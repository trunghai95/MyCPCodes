#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100001;
bool ck[MAXN+2];

void init() {
    for (int i = 2; i <= MAXN; ++i)
    if (!ck[i]) {
        if (i > MAXN/i) {
            continue;
        }
        for (int j = i*i; j <= MAXN; j += i) {
            ck[j] = true;
        }
    }
}

int n;

int main() {
    init();

    scanf("%d", &n);
    ++n;
    if (n < 4) {
        printf("1\n");
        for (int i = 2; i <= n; ++i) {
            printf("1 ");
        }
        printf("\n");
    } else {
        printf("2\n");
        for (int i = 2; i <= n; ++i) {
            if (!ck[i]) {
                printf("1 ");
            } else {
                printf("2 ");
            }
        }

        printf("\n");
    }
    return 0;
}
