#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1e5;
int n, a, mp[MAXN+2], cnt[MAXN+2], res;
queue<int> q;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        mp[a]++;
    }
    for (int i = 0; i <= MAXN; i++) {
        cnt[mp[i]]++;
    }

    for (int i = MAXN; i > 0; i--) {
        if (cnt[i] == 0) {
            if (!q.empty()) {
                int c = q.front();
                q.pop();
                res += c - i;
            }
        } else {
            while (cnt[i] > 1) {
                q.push(i);
                cnt[i]--;
            }
        }
    }
    while (!q.empty()) {
        res += q.front();
        q.pop();
    }
    printf("%d\n", res);
    return 0;
}