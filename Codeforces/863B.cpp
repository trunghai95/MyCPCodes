#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, a[MAXN+2], res;

int Try(int l, int r) {
    int res = 0;
    vector<int> v;
    for (int i = 1; i < l; ++i) {
        v.push_back(a[i]);
    }
    for (int i = l+1; i < r; ++i) {
        v.push_back(a[i]);
    }
    for (int i = r+1; i <= n; ++i) {
        v.push_back(a[i]);
    }

    for (int i = 0; i < (int)v.size(); i+=2) {
        res += v[i+1] - v[i];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    n *= 2;

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    sort(a+1, a+1+n);

    res = 1e9;
    for (int i = 1; i <= n; ++i)
    for (int j = i+1; j <= n; ++j) {
        res = min(res, Try(i, j));
    }

    printf("%d\n", res);
    return 0;
}
