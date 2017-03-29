#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, k, a;
vector<int> v;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        v.push_back(i+1);
    }

    int cur = 0;
    while (k --> 0) {
        scanf("%d", &a);
        cur = (cur + a) % v.size();
        printf("%d ", v[cur]);
        v.erase(v.begin() + cur);
    }
    printf("\n");
    return 0;
}
