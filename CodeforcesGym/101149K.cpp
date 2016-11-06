#include <bits/stdc++.h>

using namespace std;

int x[2], y[2];

int main() {
    scanf("%d %d %d %d", x, y, x+1, y+1);
    printf("%.15lf\n", 0.916297857297023*((x[1]-x[0])*(x[1]-x[0]) + (y[1]-y[0])*(y[1]-y[0])));
    return 0;
}
