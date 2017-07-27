#include <bits/stdc++.h>

using namespace std;

int c, v, vm, a, l;

int main() {
    scanf("%d %d %d %d %d", &c, &v, &vm, &a, &l);

    int res = 0, cur = 0;

    while (true) {
        ++res;
        cur += v - min(l, cur);
        if (cur >= c)
            break;

        v = min(vm, v + a);
    }

    printf("%d\n", res);
    return 0;
}
