#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
const int INF = 1e9;
int k;
char s[MAXN+2];
vector<int> v;

void prepare() {
    int last = -1;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == ' ' || s[i] == '-') {
            v.push_back(i - last);
            last = i;
        }
    }
    v.push_back(strlen(s) - 1 - last);
}

int Try(int c) {
    int cur = 0, res = 1;
    for (int i = 0; i < (int)v.size(); ++i) {
        if (cur + v[i] <= c) {
            cur += v[i];
            continue;
        }
        if (v[i] > c) {
            return INF;
        }
        ++res;
        cur = v[i];
    }

    return res;
}

int main() {
    scanf("%d %[^\n]", &k, s);
    prepare();

    int lo = 1, hi = strlen(s);

    while (lo < hi) {
        int mid = (lo + hi) / 2;

        // cout << mid << ' ' << Try(mid) << '\n';

        if (Try(mid) > k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    printf("%d\n", lo);
    return 0;
}
