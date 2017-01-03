#include <bits/stdc++.h>

using namespace std;

#define N 0
#define S 1
#define W 2
#define E 3
typedef pair<int,int> pii;
int n, t;
char dir[10];
vector<pii> v;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %s", &t, dir);
        if (!strcmp(dir, "South")) {
            v.push_back(pii(t, S));
        } else if (!strcmp(dir, "North")) {
            v.push_back(pii(t, N));
        } else if (!strcmp(dir, "West")) {
            v.push_back(pii(t, W));
        } else {
            v.push_back(pii(t, E));
        }
    }

    reverse(v.begin(), v.end());
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        // cout << cur << ' ' << v[i].first << ' ' << v[i].second << '\n';
        if (v[i].second == N) {
            cur += v[i].first;
            if (cur > 20000) {
                printf("NO\n");
                return 0;
            }
        } else if (v[i].second == S) {
            cur -= v[i].first;
            if (cur < 0) {
                printf("NO\n");
                return 0;
            }
        } else {
            if (cur >= 20000 || cur <= 0) {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("%s\n", cur?"NO":"YES");
    return 0;
}
