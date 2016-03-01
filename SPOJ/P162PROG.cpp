#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int res = 0;
	while (n)
	{
		res += n&1;
		n >>= 1;
	}

	cout << res;
	return 0;
}