#include <bits/stdc++.h>

using namespace std;

int test, n, a;

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> n;

		int res = 0;

		for (int i = 0; i < n; ++i)
			cin >> a, res ^= a;

		if (res == 0 || !(n&1))
			cout << "First\n";
		else
			cout << "Second\n";
	}
	return 0;
}