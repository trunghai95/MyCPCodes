#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int n, a, b, k;
vector<int> v;
char s[MAXN+5];

int main() {
    scanf("%d %d %d %d %s", &n, &a, &b, &k, s);

    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            last = i;
        } else if (i - last == b) {
            v.push_back(i+1);
            last = i;
        }
    }

    int cnt = v.size();
    cnt = max(0, min(cnt, cnt - a + 1));

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}
