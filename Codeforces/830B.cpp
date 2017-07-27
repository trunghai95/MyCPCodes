#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int n, a;
vector<int> v[MAXN+2];
ll res;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        v[a].push_back(i);
    }
    return 0;
}
