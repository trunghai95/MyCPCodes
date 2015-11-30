#include <bits/stdc++.h>

using namespace std;

vector<int> u[51];

int init()
{
    for (int k = 1; k <= 50; ++k)
    {
        for (int i = 1; i*i <= k; ++i)
            if (k % i == 0) u[k].push_back(i);
    }
}

int ff(int n, int m, int k)
{
    if (n > m) swap(n, m);
    if (n == 1) return 1;
    if (k % n == 0) return n*n;
    if (k <= n) return n*n + 1;
//    return ff(n, m - k/n, k % n) + n*n;

    int res = n*n*2 + 1;
    if (k % m == 0) return min(res, m*m);
    if (k <= m) return min(res, m*m + 1);

    int nm = m - k/n;
    int nk = k % n;
    if (nm >= n) return res;
    int tmp = n*n + nm*nm;
    if (nk % nm != 0) tmp += (nk > nm) ? (nm*nm + 1) : 1;

    return min(res, tmp);
}

int solve(int n, int m, int k)
{
    int res = 2e9;
    if (n > m) swap(n, m);
    for (int i = 0; i < u[k].size(); ++i)
    {
        int a = u[k][i], b = k/u[k][i], tmp;
        if (a <= n && b <= m)
        {
            tmp = (b == m) ? m*m : (n*n + ((a == n) ? 0 : b*b));
            res = min(tmp, res);
        }
        if (a <= m && b <= n)
        {
            tmp = (a == m) ? m*m : (n*n + ((b == n) ? 0 : b*b));
            res = min(tmp, res);
        }
    }

    return min(res, ff(n, m, k));
}

int main()
{
    init();
    int test, n, m, k;
    cin >> test;
    while (test--)
    {
        cin >> n >> m >> k;
        if (k == n*m)
            cout << "0\n";
        else
        {
            int res1 = solve(n, m, k);
            int res2 = solve(n, m, n*m - k);
            cout << min(res1, res2) << '\n';
        }
    }
    return 0;
}
