#include <bits/stdc++.h>

using namespace std;

int test, n, a[10000];

int main()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> test;

	while (test--)
    {
        cin >> n;
        int sum = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }

        sort(a,a+n);

        int sums = 0, i;
        for (i = n - 1; i >= 0; --i)
        {
            sums += a[i];
            if (sums > sum/2)
                break;
        }
        i = max(i, 0);
        cout << n - i << endl;
    }

    return 0;
}
