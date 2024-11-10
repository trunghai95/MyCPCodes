#include <bits/stdc++.h>

using namespace std;

int x[3], y[3];

void solve() {
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 0; i < 3; i++) {
        int j = (i+1)%3;
        int k = (i+2)%3;
        if ((x[j] < x[i] && x[k] > x[i]) || (x[j] > x[i] && x[k] < x[i]) || (y[j] < y[i] && y[k] > y[i]) || (y[j] > y[i] && y[k] < y[i])) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int test;
    scanf("%d", &test);
    while (test --> 0) {
        solve();
    }
    return 0;
}