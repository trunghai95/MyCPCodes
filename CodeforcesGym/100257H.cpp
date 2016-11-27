#include <bits/stdc++.h>

using namespace std;

int x[3], y[3];

int main() {
    for (int i = 0; i < 3; ++i)
        scanf("%d %d", x+i, y+i);

    if (x[1] >= x[0]) {
        if (x[2] > x[1] || x[2] < x[0]) {
            printf("No\n");
            return 0;
        }
    } else {
        if (x[2] < x[1] || x[2] > x[0]) {
            printf("No\n");
            return 0;
        }
    }

    if (y[1] >= y[0]) {
        if (y[2] > y[1] || y[2] < y[0]) {
            printf("No\n");
            return 0;
        }
    } else {
        if (y[2] < y[1] || y[2] > y[0]) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}
