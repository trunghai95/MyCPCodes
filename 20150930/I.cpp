#include <bits/stdc++.h>

using namespace std;

int test, n, num[100001], res;
int cnt[2], cc[2];
char c, ct, c0;

int gcd(int x, int y)
{
    if (!x || !y) return (x+y);
    return (x>y)?gcd(x%y, y):gcd(y%x, x);
}

int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n;
        res = 0;
        cnt[0] = cnt[1] = 0;
        cin >> num[0] >> ct;
        cnt[0] = num[0];
        for (int i = 1; i < n; ++i)
        {
            cin >> num[i] >> c;
            if (c == ct)
            {
                cnt[1 - i&1] += num[i];
                num[i-1] += num[i];
                --i; --n;
            }
            else
            {
                cnt[i&1] += num[i];
                ct = c;
            }
        }
        if (!cnt[0] || !cnt[1])
        {
            cout << cnt[0] + cnt[1] << endl;
            continue;
        }
        int g = gcd(cnt[0], cnt[1]);
        cnt[0] /= g;
        cnt[1] /= g;

        cc[0] = cc[1] = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!cc[1 - i&1] || (cc[1 - i&1] % cnt[1 - i&1]))
            {
                cc[i&1] = num[i];
            }
            else
            {
                int xx = cc[1 - i&1] / cnt[1 - i&1] * cnt[i&1];
                xx -= cc[i&1];
                if (xx > 0 && xx <= num[i])
                {
                    ++res;
                    cc[i&1] = num[i] - xx;
                    cc[1 - i&1] = 0;
                }
                else
                    cc[i&1] += num[i];
            }
        }

        cout << res << endl;
    }
    return 0;
}
