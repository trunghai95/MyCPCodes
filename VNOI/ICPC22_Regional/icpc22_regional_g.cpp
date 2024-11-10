#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10004;
int n, r, x1, x2, p;

int main() {
    scanf("%d %d %d %d", &n, &r, &x1, &x2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        if (x1 < x2) {
            if (p + r <= x1) {
                printf("GOAL\n");
                return 0;
            }
        } else {
            if (p - r >= x1) {
                printf("GOAL\n");
                return 0;
            }
        }
    }
    printf("NO GOAL\n");
    return 0;
}