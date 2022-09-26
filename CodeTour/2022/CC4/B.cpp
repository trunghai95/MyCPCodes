#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
int n, a[MAXN];
unordered_map<int, int> cnt;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", cnt[a[i]]);
    }
    printf("\n");
    return 0;
}