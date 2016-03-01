#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	cin >> n;
	if (n > 0)
	{
		cout << n;
		return 0;
	}

	int res1 = n / 10;
	int res2 = n/100*10 + n%10;

	cout << max(res1, res2);
	return 0;
}