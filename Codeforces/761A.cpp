#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
    cin >> a >> b;

    if (abs(a-b) > 1 || (a == 0 && b == 0)) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}
