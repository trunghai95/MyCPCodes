#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 4294967295;

int test, n, a[100003];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);

        a[0] = 100000;
        for (int i = 1; i < n; ++i) {
            a[i] = (MAX-100000)/n;
        }
        for (int i = 1; i < (MAX - 100000)%n; ++i) {
            ++a[i];
        }

        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
