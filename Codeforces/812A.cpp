#include <bits/stdc++.h>

using namespace std;

int a[4][4];

int main() {
    for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j) {
        scanf("%d", a[i] + j);
    }

    if (a[0][3] && (a[1][0] || a[2][1] || a[3][2] 
        || a[0][1] || a[0][2] || a[0][0])) {
        printf("YES\n");
    } else if (a[1][3] && (a[2][0] || a[3][1] || a[0][2]
        || a[1][1] || a[1][2] || a[1][0])) {
        printf("YES\n");
    } else if (a[2][3] && (a[3][0] || a[0][1] || a[1][2]
        || a[2][1] || a[2][2] || a[2][0])) {
        printf("YES\n");
    } else if (a[3][3] && (a[0][0] || a[1][1] || a[2][2]
        || a[3][1] || a[3][2] || a[3][0])) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
