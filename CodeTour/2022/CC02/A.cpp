#include <stdio.h>

using namespace std;

const int MAXN = 100005;
int n, x[MAXN], y[MAXN];

bool solve() {
    scanf("%d", &n);
    if (n == 0) {
        return false;
    }

    double res = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", x+i, y+i);
    }

    for (int i = 0; i < n; i++) {
        int j = i+1;
        if (j >= n) {
            j = 0;
        }
        res = res + double(x[i] + x[j]) * (y[i] - y[j]);
    }
    if (res < 0) {
        res = -res;
    }

    printf("%.2lf\n", res / 2.0);

    return true;
}

int main() {
    while (solve()) {}
    return 0;
}