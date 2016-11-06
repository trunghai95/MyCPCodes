#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int p, res[1000010];

int main() {
    scanf("%d", &p);

    memset(res, -1, sizeof(res));

    for (ll i = 0; i < p; ++i) {
        res[(i*i)%p] = i;
    }

    for (int i = 0; i < p; ++i)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
