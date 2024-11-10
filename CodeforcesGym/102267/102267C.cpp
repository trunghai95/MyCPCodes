#include <bits/stdc++.h>

using namespace std;

int s, x, cnt;

int main() {
    scanf("%d %d", &s, &x);
    while (s > 0) {
        s /= x;
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}