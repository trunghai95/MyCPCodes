#include <bits/stdc++.h>

using namespace std;

int n, a[6], res, b[6];

int get(int x, int y) {
    if (x == 0) {
        if (y == 1) {
            return 1;
        } else {
            return 0;
        }
    } else if (x == 1) {
        if (y == 0) {
            return 4;
        } else {
            return 5;
        }
    } else {
        if (y == 0) {
            return 2;
        } else {
            return 3;
        }
    }
}

void Try(int n, int last) {
    for (int i = 0; i < 6; ++i)
    if (b[i] > a[i]) {
        return;
    }

    if (n == 0) {
        ++res;
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (i != last) {
            ++b[get(last, i)];
        }
        Try(n-1, i);
        if (i != last) {
            --b[get(last, i)];
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 6; ++i)
        scanf("%d", a+i);

    for (int i = 0; i < 3; ++i) {
        Try(n-1, i);
    }

    printf("%d\n", res);
    return 0;
}
