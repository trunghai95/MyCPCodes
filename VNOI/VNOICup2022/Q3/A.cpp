#include <stdio.h>

using namespace std;

int test, n, i, j, x, y, a, b;

void solve() {
    scanf("%d %d %d %d", &i, &j, &x, &y);
    if ((i+j)%2 != (x+y)%2) {
        printf("-1\n");
        return;
    }
    if (i == x && j == y) {
        printf("0\n");
        return;
    }

    if (i-j == x-y || i+j == x+y) {
        printf("1\n%d %d\n", x, y);
        return;
    }

    printf("2\n");

    // a-b=i-j,a+b=x+y
    a = (i-j+x+y)/2;
    b = (x+y-i+j)/2;
    if (a > 0 && a <= n && b > 0 && b <= n) {
        printf("%d %d\n%d %d\n", a, b, x, y);
        return;
    }

    // a-b=x-y, a+b=i+j
    a = (x-y+i+j)/2;
    b = (i+j-x+y)/2;
    printf("%d %d\n%d %d\n", a, b, x, y);
}

int main() {
    scanf("%d %d", &n, &test);
    while (test --> 0) {
        solve();
    }
    return 0;
}