#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v;

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 2; i <= n && k > 1; ++i) {
        if (n % i == 0) {
            v.push_back(i);
            n /= i;
            --k;
            --i;
        }
    }

    if (k > 1 || n == 1) {
        printf("-1\n");
    } else {
        for (int i = 0; i < (int)v.size(); ++i) {
            printf("%d ", v[i]);
        }
        printf("%d\n", n);
    }
    return 0;
}
