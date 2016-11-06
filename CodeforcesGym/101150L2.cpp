#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;
#define F first
#define S second

int n, pos[1010];
ll a[1010], res, k, r;
vector<pil> v;
queue<pil> q;

int main() {
    memset(pos, -1, sizeof(pos));
    scanf("%lld %lld %d", &r, &k, &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
        q.push(pil(i, a[i]));
    }

    for (int i = 1; i <= r; ++i) {
        if (pos[q.front().F] != -1) {
            r -= i - 1;
            res += r / (i - pos[q.front().F] - 1) * (res - v[pos[q.front().F]].S);
            r %= (i - pos[q.front().F] - 1);

            while (r --> 0) {
                ll sum = 0;
                int cnt = 0;

                while (cnt < n) {
                    if (sum + q.front().S > k) break;
                    sum += q.front().S;
                    q.push(q.front());
                    q.pop();
                    ++cnt;
                }
                res += sum;
            }
            break;
        }

        pos[q.front().F] = v.size();
        v.push_back(pil(q.front().F, res));
        ll sum = 0;
        int cnt = 0;

        while (cnt < n) {
            if (sum + q.front().S > k) break;
            sum += q.front().S;
            q.push(q.front());
            q.pop();
            ++cnt;
        }
        res += sum;
    }

    printf("%lld\n", res);
    return 0;
}