#include <bits/stdc++.h>

using namespace std;

int x[10][10], a[10], b[10];

int calc() {
    return x[x[x[x[x[0][b[0]]][b[1]]][b[2]]][b[3]]][b[4]];
}

int Try() {
    for (int i = 0; i < 5; ++i)
        b[i] = a[i];

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j)
        if (j != a[i]) {
            b[i] = j;
            if (calc() == 0) {
                return 1;
            }
            b[i] = a[i];
        }
        b[i] = a[i];
    }

    for (int i = 0; i < 4; ++i)
    if (b[i] != b[i+1]) {
        swap(b[i], b[i+1]);
        if (calc() == 0) {
            return 1;
        }
        swap(b[i], b[i+1]);
    }

    return 0;
}

int main() {
    for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
        scanf("%d", x[i]+j);

    int res = 0;
    for (a[0] = 0; a[0] < 10; ++a[0])
    for (a[1] = 0; a[1] < 10; ++a[1])
    for (a[2] = 0; a[2] < 10; ++a[2])
    for (a[3] = 0; a[3] < 10; ++a[3]) {
        a[4] = x[x[x[x[0][a[0]]][a[1]]][a[2]]][a[3]];
        res += Try();
    }

    printf("%d\n", res);
    return 0;
}
