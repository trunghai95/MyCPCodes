#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int test, p, x, y;

int dist(int x, int y) {
    return (x-50)*(x-50) + (y-50)*(y-50);
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d %d", &p, &x, &y);
        printf("Case #%d: ", tt);
        if (!p || dist(x, y) > 2500) {
            printf("white\n");
            continue;
        }

        double ang = atan2(y-50, x-50);
        ang = PI/2 - ang;
        while (ang < 0) ang += PI*2;
        while (ang > PI*2) ang -= PI*2;
        ang = ang / (PI*2) * 100;
        if (ang <= (double)p) {
            printf("black\n");
        } else {
            printf("white\n");
        }
    }
    return 0;
}
