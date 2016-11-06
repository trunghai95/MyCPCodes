#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, test;
ll k;

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %lld", &n, &k);

        bool on = true;
        for (int i = 0; i < n; ++i) {
            if (!((k >> i) & 1)) {
                on = false;
                break;
            }
        }

        printf("%s\n", on?"ON":"OFF");
    }
    return 0;
}