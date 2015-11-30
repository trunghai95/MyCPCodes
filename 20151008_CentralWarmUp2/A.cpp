#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int test;
	cin >> test;
	while (test--)
    {
        cin >> n;
        for (int i = 10; i <= 100000000 && i <= n; i *= 10)
        {
            n = (n + i/2) / i * i;
            if (i >= n) break;
        }
        cout << n << endl;
    }

    return 0;
}
